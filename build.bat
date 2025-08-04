@echo LAC - LogAnalyzerConsole
@echo LAC - Creating the directory and going inside of it
mkdir build && cd build
@echo LAC - Generating files inside of build
cmake .. -G "Visual Studio 17 2022"
@echo LAC - Opening the solution LAC.sln
start LAC.sln