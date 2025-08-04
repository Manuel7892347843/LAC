cmake_minimum_required(VERSION 3.10)
project(LAC)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Lista dei sorgenti con PERCORSI COMPLETI
set(SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/globals.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LAC.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LogEntry.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LogOutput.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LogParser.cpp"
)

# Verifica che i file esistano
foreach(source ${SOURCES})
    if(NOT EXISTS ${source})
        message(WARNING "File non trovato: ${source}")
    endif()
endforeach()

add_executable(LAC ${SOURCES})

target_include_directories(LAC PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/File di intestazione"
)