#include <iostream>
using namespace std;
#include "MCP23017.hpp"
#include <unistd.h>


void mssleep(int msec) {
    usleep(msec * 1000);
}


int main() {
    int adapter_nr = 1; // for RPi B version
    std::string filename = "/dev/i2c-" + std::to_string(adapter_nr);
	cout << filename.c_str() << endl;

    int _bus = open(filename.c_str(), O_RDWR);
    if (_bus < 0) {
        cout << "ERROR 1 HANDLING; you can check errno to see what went wrong" << endl;
        exit(1);
    }
    
    MCP23017 mcp = MCP23017(_bus, 0x27);

    mcp.init();
    mcp.portMode(MCP23017Port::A, 0); //Port A as output
    mcp.portMode(MCP23017Port::B, 0); //Port B as output

    int mode = 1;

    while(1) {
        if (mode) {
            for (int i = 0; i < 16; i++) {
                mcp.write(1 << i);
                mssleep(20);
            }
        }
        else {
            for (int i = 0; i < 8; i++) {
                mcp.writePort(MCP23017Port::A, 1 << i);
                mcp.writePort(MCP23017Port::B, 1 << i);
                mssleep(20);
            }
        }
        if (mode) {
            mcp.write(0x0000);
        }
        else {
            mcp.writePort(MCP23017Port::A, 0x00);
            mcp.writePort(MCP23017Port::B, 0x00);
        }
    }

    return 1;
}
