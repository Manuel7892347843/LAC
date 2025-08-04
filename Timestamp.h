#pragma once
#include <iostream>
#include <string>

struct Timestamp {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    Timestamp() : year(0), month(0), day(0), hour(0), minute(0), second(0) {}

    Timestamp(int y, int mo, int d, int h, int mi, int s)
        : year(y), month(mo), day(d), hour(h), minute(mi), second(s) {
    }

    std::string toString() const {
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02d:%02d:%02d",
            year, month, day, hour, minute, second);
        return std::string(buffer);
    }
};