#include "LogOutput.h"

int main() {
    LogOutput logOutput("DISK://path//to//logfile.txt", false);
    logOutput.read();
    return 0;
}