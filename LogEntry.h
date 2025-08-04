#pragma once
#include <iostream>
#include <string>
#include "Timestamp.h"

class LogEntry {
public:
    std::string ip;
    Timestamp timestamp;
    std::string method;
    std::string url;
    int http_code_status;
    int response;

    LogEntry();
    LogEntry(const Timestamp& timestamp, const std::string& ip, const std::string& method, const std::string& url, const int& http_code_status, const int& response);

    std::string toString() const;
};