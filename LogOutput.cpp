#include "LogOutput.h"
#include "LogParser.h"
#include <iostream>
#include <unordered_map>
#include "Statistics.h"
#include "globals.h"

LogOutput::LogOutput(std::string filePath, bool debug) {
    this->filePath = filePath;
    debug_mode = debug;
}

std::vector<LogEntry> LogOutput::obtain_entries() const {
    try {
        LogParser parser;
        return parser.parseFile(filePath);
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return {};
    }
}

void LogOutput::read() const {
    std::vector<LogEntry> entries = obtain_entries();

    Statistics stats;

    for (const LogEntry& entry : entries) {
        stats.requests.totalRequest++;
        if (entry.method == "GET")
            stats.requests.getRequest++;
        else if (entry.method == "POST")
            stats.requests.postRequest++;
        else if (entry.method == "PUT")
            stats.requests.putRequest++;
        else if (entry.method == "DELETE")
            stats.requests.deleteRequest++;

        stats.totalBytesTransferred += entry.response;

        int status = entry.http_code_status;
        if (status >= 200 && status < 300)
            stats.successfulResponses++;
        else if (status >= 400 && status < 500)
            stats.clientErrors++;
        else if (status >= 500 && status < 600)
            stats.serverErrors++;

        stats.ipFrequency[entry.ip]++;
    }

    std::cout << "\n== STATISTICS ==\n";
    std::cout << "Total Requests:            " << stats.requests.totalRequest << "\n";
    std::cout << "  GET Requests:            " << stats.requests.getRequest << "\n";
    std::cout << "  POST Requests:           " << stats.requests.postRequest << "\n";
    std::cout << "  PUT Requests:            " << stats.requests.putRequest << "\n";
    std::cout << "  DELETE Requests:         " << stats.requests.deleteRequest << "\n";

    std::cout << "Successful Responses (2xx): " << stats.successfulResponses << "\n";
    std::cout << "Client Errors (4xx):        " << stats.clientErrors << "\n";
    std::cout << "Server Errors (5xx):        " << stats.serverErrors << "\n";

    std::cout << "Total Bytes Transferred:    " << stats.totalBytesTransferred << "B\n";

    std::cout << "\nTop IPs:\n";
    for (const auto& pair : stats.ipFrequency) {
        std::cout << "  " << pair.first << ": " << pair.second << " requests\n";
    }
}