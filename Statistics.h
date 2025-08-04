#pragma once
#include <iostream>
#include <unordered_map>
struct Requests {
    int totalRequest = 0;
    int getRequest = 0;
    int postRequest = 0;
    int putRequest = 0;
    int deleteRequest = 0;
};

struct Statistics {
    Requests requests;

    int totalBytesTransferred = 0;
    int successfulResponses = 0;
    int clientErrors = 0;
    int serverErrors = 0;

    std::unordered_map<std::string, int> ipFrequency;
};