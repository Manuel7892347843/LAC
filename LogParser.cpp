#include "LogParser.h"
#include <string>
#include "LogEntry.h"
#include <vector>
#include <fstream>
#include <regex>
#include <sstream>
#include "globals.h"

std::vector<LogEntry> LogParser::parseFile(const std::string& filePath) {
    if (debug_mode)
        std::cout << "Attempting to open file: " << filePath << "\n";

    std::ifstream logFile(filePath);
    if (!logFile.is_open()) {
        if (debug_mode)
            std::cerr << "ERROR: Unable to open the file!\n";
        throw std::runtime_error("...");
    }

    std::string line;
    std::vector<LogEntry> entries;
    int lineCount = 0;

    while (std::getline(logFile, line)) {
        lineCount++;
        if (debug_mode)
            std::cout << "Line " << lineCount << ": " << line << "\n";

        if (isValidLine(line)) {
            try {
                entries.push_back(parseLine(line));
                if (debug_mode)
                    std::cout << "Valid line processed\n";
            }
            catch (...) {
                std::cerr << "ERRORE parsing line " << lineCount << "\n";
            }
        }
        else {
            std::cerr << "Invalid line discarded: " << line << "\n";
        }
    }

    if (debug_mode)
        std::cout << "Total lines processed: " << entries.size() << "\n";
    return entries;
}

LogEntry LogParser::parseLine(const std::string& line)
{
    std::regex logRegex(R"(^\[(\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2})\] (\d{1,3}(?:\.\d{1,3}){3}) (\S+) (\S+) \"(\d{3})\" (\d+) B$)");
    std::smatch match;

    if (std::regex_match(line, match, logRegex)) {
        std::string timestamp_s = match[1];
        std::string ip = match[2];
        std::string method = match[3];
        std::string url = match[4];
        int http_code_status = std::stoi(match[5]);
        int response = std::stoi(match[6]);

        Timestamp timestamp{};
        int parsed = sscanf_s(timestamp_s.c_str(), "%d-%d-%d %d:%d:%d",
            &timestamp.year, &timestamp.month, &timestamp.day,
            &timestamp.hour, &timestamp.minute, &timestamp.second);

        if (parsed != 6) {
            throw std::runtime_error("parseLine: Timestamp parsing failed.");
        }

        return LogEntry(timestamp, ip, method, url, http_code_status, response);
    }
    else {
        throw std::runtime_error("parseLine: Line format is invalid.");
    }
}

bool LogParser::isValidLine(const std::string& line) {
    if (line.empty()) {
        if (debug_mode)
            std::cerr << "Discarded: Empty line\n";
        return false;
    }

    size_t timestamp_end = line.find("] ");
    if (timestamp_end == std::string::npos) {
        if (debug_mode)
            std::cerr << "Discarded: Missing ']' in timestamp\n";
        return false;
    }

    std::string timestamp = line.substr(0, timestamp_end + 1);
    std::string remaining = line.substr(timestamp_end + 2);

    std::istringstream stream(remaining);
    std::string ip, method, url, http_code, response, b;

    stream >> ip >> method >> url >> http_code >> response >> b;

    if (debug_mode)
        std::cerr << "Tokens extracted: [" << timestamp << "], [" << ip << "], ["
        << method << "], [" << url << "], [" << http_code << "], ["
        << response << "], [" << b << "]\n";

    if (ip.empty() || method.empty() || url.empty() || http_code.empty() || response.empty() || b.empty()) {
        if (debug_mode)
            std::cerr << "Discarded: Missing tokens\n";
        return false;
    }

    if (timestamp.front() != '[' || timestamp.back() != ']') {
        if (debug_mode)
            std::cerr << "Discarded: Malformed timestamp\n";
        return false;
    }

    if (b != "B") {
        if (debug_mode)
            std::cerr << "Discarded: Final ‘B’ missing\n";
        return false;
    }

    return true;
}