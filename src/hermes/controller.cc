#include <Servo.h>
#include <Wire.h>
#include "IOpins.h"
#include "Constants.h"
#include "batterystats.h"
#include "params.h"

Params *params;
BatteryStats batt;
// CommandProcessor *cmd;

void setup()
{
  params = new Params();
  batt = new BatteryStats(params);
  // cmd = new CommandProcessor();
}

void loop()
{
  // battery tasks
  batt->update();
  batt->check_current_draw();
  batt->check_voltage();

  if (batt->needs_charge())
  {
    batt->charge();
    return;
  }

  // motor tasks
}
