#pragma once
#include <iostream>
#include <string>
#include "LogEntry.h"
#include <vector>

class LogParser {
private:
    std::string filePath;

public:
    std::vector<LogEntry> parseFile(const std::string& filePath);
    LogEntry parseLine(const std::string& line);
    bool isValidLine(const std::string& line);
};