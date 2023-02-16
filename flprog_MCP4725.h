#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"

#define MCP4725_I2CADDR_DEFAULT 0x62
#define MCP4725_CMD_WRITEDAC 0x40
#define MCP4725_CMD_WRITEDACEEPROM 0x60

class FLProgMCP4725 : public FLProgI2cBasicSensor
{
public:
    FLProgMCP4725(FLProgI2C *device, uint8_t i2c_address = MCP4725_I2CADDR_DEFAULT);
    bool setVoltage(uint16_t output, bool writeEEPROM, uint32_t dac_frequency = 400000);
};
