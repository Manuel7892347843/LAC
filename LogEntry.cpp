#include "LogEntry.h"
#include "Timestamp.h"
#include <sstream>

LogEntry::LogEntry()
    : timestamp(), ip(""), method(""), url(""), http_code_status(0), response(0) {
}

LogEntry::LogEntry(const Timestamp& timestamp, const std::string& ip, const std::string& method, const std::string& url, const int& http_code_status, const int& response)
    : timestamp(timestamp), ip(ip), method(method), url(url), http_code_status(http_code_status), response(response) {
}

std::string LogEntry::toString() const {
    std::ostringstream oss;

    oss << "[" << timestamp.toString() << "] "     // Timestamp
        << ip << " "                               // IP
        << method << " "                          // Metodo (GET, POST...)
        << url << " "                             // Requested URL
        << "\"" << http_code_status << "\" "      // HTTP code in quotation marks
        << response << " B";                       // Number of bytes with space and B

    return oss.str();
}