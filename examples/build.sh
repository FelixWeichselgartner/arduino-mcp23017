cp ../src/MCP23017.cpp MCP23017.cpp
cp ../src/MCP23017.hpp MCP23017.hpp
g++ -std=c++11 test.cpp MCP23017.cpp -li2c -o test.out
