#include <Servo.h>
#include <Wire.h>

#include "batterystats.h"
#include "params.h"

typedef struct
{
  int left_mode, left_pwm;
  int right_mode, right_pwm;
} motor_packet_type;

Params *params;
BatteryStats batt;
motor_packet_type mp;
int read_one();

void setup()
{
  params = new Params();
  batt.set_params(params);

  // Initialize the IO pins
  pinMode(params->charger_pin(), OUTPUT); // set the charger pin mode to output
  digitalWrite(params->charger_pin(), 1); // disable current regulator to charge battery

  // setup the serial port
  Serial.begin(params->baud_rate());
  Serial.flush();
}

void loop()
{
  // battery tasks
  batt.update();
  batt.check_current_draw();
  batt.check_voltage();

  if (batt.needs_charge())
  {
    batt.charge();
    return;
  }

  if (Serial.available())
  {
    unsigned char byte1 = read_one();
    unsigned char byte2 = read_one();
    unsigned int command = (byte1 << 8) + byte2;

    // Change mode
    if (command == params->command_CH_code())
    {
      // who cares
    }

    // Read voltage
    else if (command == params->command_VO_code())
    {
      // returns a "raw" value from the analog pin
      // divide this by a magic number to get the real voltage
      // for us, for now, that magic number is 68.319
      // We'll divide it "client" side so that we can tweak it later
      int volts = batt.get_voltage();
      Serial.write(volts/256);
      Serial.write(volts%256);
    }

    // flush comms buffers
    else if (command == params->command_FL_code())
    {
      Serial.flush();
    }

    // read analog pins
    else if (command == params->command_AN_code())
    {
      // who cares
    }

    // set servos
    else if (command == params->command_SV_code())
    {
      // who cares
    }

    // set motors
    else if (command == params->command_HB_code())
    {
      // read four bytes from serial:
      mp.left_mode  = read_one();
      mp.left_pwm   = read_one();
      mp.right_mode = read_one();
      mp.right_pwm  = read_one();
    }
  }

  if (batt.needs_charge())
  {
    memset(&mp, 0, sizeof(motor_packet_type));
  }

  if (batt.left_ok())
  {
    switch (mp.left_mode)
    {
      case 0: // reverse
        analogWrite(params->left_motor_a_pin(), mp.left_pwm);
        analogWrite(params->left_motor_b_pin(), 0);
        break;
        
      case 1: // Brake
        analogWrite(params->left_motor_a_pin(), mp.left_pwm);
        analogWrite(params->left_motor_b_pin(), mp.left_pwm);
        break;

      case 2: // Forward
        analogWrite(params->left_motor_a_pin(), 0);
        analogWrite(params->left_motor_b_pin(), mp.left_pwm);
        break;
    }
  }

  if (batt.right_ok())
  {
    switch (mp.right_mode)
    {
      case 0: // reverse
        analogWrite(params->left_motor_a_pin(), mp.right_pwm);
        analogWrite(params->left_motor_b_pin(), 0);
        break;
        
      case 1: // Brake
        analogWrite(params->left_motor_a_pin(), mp.right_pwm);
        analogWrite(params->left_motor_b_pin(), mp.right_pwm);
        break;

      case 2: // Forward
        analogWrite(params->left_motor_a_pin(), 0);
        analogWrite(params->left_motor_b_pin(), mp.right_pwm);
        break;
    }
  }
}

int read_one()
{
  int data;
  do
  {
    data = Serial.read();
  } while (data < 0);
  return data;
}
