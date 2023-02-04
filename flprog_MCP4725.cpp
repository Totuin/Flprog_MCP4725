#include "flprog_MCP4725.h"

FLProgMCP4725::FLProgMCP4725(FLProgI2C *device, uint8_t i2c_address)
{
    i2cDevice = device;
    address = i2c_address;
}

bool FLProgMCP4725::setVoltage(uint16_t output, bool writeEEPROM, uint32_t dac_frequency)
{
    i2cDevice->setSpeed(dac_frequency);

    uint8_t packet[3];

    if (writeEEPROM)
    {
        packet[0] = MCP4725_CMD_WRITEDACEEPROM;
    }
    else
    {
        packet[0] = MCP4725_CMD_WRITEDAC;
    }
    packet[1] = output / 16;
    packet[2] = (output % 16) << 4;
    bool result = i2cDevice->fullWrite(address, packet, 3);
    i2cDevice->resetSpeedFrom(dac_frequency);
    return !result;
}
