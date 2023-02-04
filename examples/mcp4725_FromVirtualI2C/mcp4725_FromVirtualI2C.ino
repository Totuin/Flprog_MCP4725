#include "flprog_MCP4725.h"

FLProgI2C wireDevice(0);
FLProgTCA9548A commutator(&wireDevice);
FLProgVirtualI2C virtualWire(&commutator, 2);
FLProgMCP4725 dac(&virtualWire);

void setup(void)
{
  wireDevice.begin();
}

void loop(void)
{
  uint32_t counter;
  for (counter = 0; counter < 4095; counter++)
  {
    dac.setVoltage(counter, false);
    delay(2);
  }
  for (counter = 4095; counter > 0; counter--)
  {
    dac.setVoltage(counter, false);
    delay(2);
  }
}