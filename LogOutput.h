#pragma once
#include <iostream>
#include "LogEntry.h"
#include "LogParser.h"
#include <vector>

class LogOutput {
private:
    std::string filePath;
    std::vector<LogEntry> obtain_entries() const;
public:
    LogOutput(std::string filePath, bool debug);
    void read() const;
};