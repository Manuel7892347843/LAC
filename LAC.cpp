#include "LogOutput.h"

int main() {
    std::string filepath;
    std::cout << "Enter the path of the file .txt (if your path contains a backslash you have to replace it with '//' and remove the '""' at the start and at the end of the path): \n";
    std::getline(std::cin, filepath);
    LogOutput logOutput(filepath, false);
    logOutput.read();
    return 0;
}