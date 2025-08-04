# LogAnalyzerConsole

A C++ console application designed to efficiently analyze and process structured log files.

## 📄 Project Description

**LogAnalyzerConsole** is a command-line tool that parses log files, extracts structured data, and performs statistical analysis. Built using modern C++17 standards, the application offers modularity, performance, and clarity, making it a solid foundation for log-based insights and diagnostics.

---

## 🧩 Core Components

- **LogParser**: Reads and interprets lines from the log file, validating their structure.
- **LogEntry**: Encapsulates a single log entry and its relevant attributes (e.g., IP, timestamp, method, etc.).
- **Timestamp**: Provides parsing and formatting utilities for timestamps.
- **Statistics**: Collects, computes, and manages statistics from parsed log entries.
- **LogOutput**: Responsible for displaying formatted results and reports.

---

## 🧰 System Requirements

- **Operating System**: Windows 10 or later  
- **Compiler**: Any with C++20 support  
- **Recommended IDE**: Visual Studio 2017 or later  
- **Memory**: Minimum 4 GB RAM (recommended)

---

## ⚙️ Building the Project

1. Download or Clone the project in your device
2. Open the Terminal and execute this lines of code:
    - `cd path of the project in your device`
    - `mkdir build && cd build`
    - `cmake .. -G "Visual Studio 17 2022"`
    - `start LAC.sln`
3. Change the project configuration from `ALL_BUILD` to `LAC`
2. Choose `Debug` or `Release` configuration.
3. Build the project with `Ctrl+Shift+B` or run with `F5`.

---

## 📥 Input Format

The application processes log files formatted with:
- **One entry per line**
- Each line must include:
  - An IP address
  - A timestamp
  - HTTP method
  - Resource path
  - HTTP response code
  - Response size (in bytes)

Example log line:

`[2025-08-03 13:45:00] 192.168.1.1 GET /home.index "200" 2048 B`

---

## 📊 Output

The application provides:
- Total number of log entries
- Time range covered
- Distribution of HTTP methods and response codes
- Response size metrics and more

---

## ⚠️ Limitations

- Supports only **single log file processing** at a time
- Handles logs that fit in memory (no streaming)
- Currently supported only on **Windows**

---

## 🚀 Performance

The application is designed for:
- Fast I/O and line-by-line parsing
- Minimal memory footprint
- Efficient computation of statistics

Ensure log files are well-formed to maximize performance.