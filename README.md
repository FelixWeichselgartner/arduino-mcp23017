# MCP23017 for Raspberry Pi

[![License](https://img.shields.io/badge/license-MIT%20License-blue.svg)](http://doge.mit-license.org)

This library provides full control over the Microchip's [MCP23017](https://www.microchip.com/wwwproducts/en/MCP23017), including interrupt support.

## Features
 * Individual pins read & write
 * Ports read & write
 * Registers read & write
 * Full interrupt support

## Usage
You can create multiple MCP23017 objects based on  MCP23017 `A0`, `A1` and `A2` pins wirings.
Available addresses go from `0x20` to `0x27`, allowing up to 8 MCP23017 on the same I2C bus.

```cpp
#include "MCP23017.hpp"

MCP23017 mcp = MCP23017(bus, 0x24);
```

You have to create a I²C-interface with smbus. See [here](./examples/test.cpp) for an example.
