#include <Servo.h>
#include <Wire.h>
#include "params.h"

Params::Params()
{
  // defaults taken from the original Constants.h file
  m_mode                      = MODE_SERIAL;
  m_baud_rate                 = 9600;
  m_i2c_addr                  = 0x04;
  m_one_volt                  = 7;
  m_battery_pin               = 0;
  m_left_motor_amps_pin       = 7;
  m_right_motor_amps_pin      = 6;
  m_left_motor_a_pin          = 3;
  m_left_motor_b_pin          = 11;
  m_right_motor_a_pin         = 5;
  m_right_motor_b_pin         = 6;
  m_charger_pin               = 13;
  m_max_charge_time_limit     = 300000;
  m_min_voltage_limit         = 410;
  m_peak_voltage_cutoff_limit = 487;
  m_max_left_amps_limit       = 800;
  m_max_right_amps_limit      = 800;
  m_overload_interval_limit   = 100;
  m_command_CH_code           = 17224;
  m_command_VO_code           = 22095;
  m_command_FL_code           = 17996;
  m_command_AN_code           = 16718;
  m_command_SV_code           = 21334;
  m_command_HB_code           = 18498;
}

// getters/setters
Mode_Type Params::mode(Mode_Type mode)
{
  if (mode != MODE_NONE)
    m_mode = mode;
  return m_mode;
}

unsigned int Params::baud_rate(unsigned int baud_rate)
{
  if (baud_rate != 0)
    m_baud_rate = baud_rate;
  return m_baud_rate;
}

unsigned int Params::i2c_addr(unsigned int i2c_addr)
{
  if (i2c_addr != 0)
    m_i2c_addr = i2c_addr;
  return m_i2c_addr;
}

unsigned int Params::one_volt(unsigned int one_volt)
{
  if (one_volt != 0)
    m_one_volt = one_volt;
  return m_one_volt;
}

unsigned char Params::battery_pin(unsigned char battery_pin)
{
  if (battery_pin != 0)
    m_battery_pin = battery_pin;
  return m_battery_pin;
}

unsigned char Params::left_motor_amps_pin(unsigned char left_motor_amps_pin)
{
  if (left_motor_amps_pin != 0)
    m_left_motor_amps_pin = left_motor_amps_pin;
  return m_left_motor_amps_pin;
}

unsigned char Params::right_motor_amps_pin(unsigned char right_motor_amps_pin)
{
  if (right_motor_amps_pin != 0)
    m_right_motor_amps_pin = right_motor_amps_pin;
  return m_right_motor_amps_pin;
}

unsigned char Params::left_motor_a_pin(unsigned char left_motor_a_pin)
{
  if (left_motor_a_pin != 0)
    m_left_motor_a_pin = left_motor_a_pin;
  return m_left_motor_a_pin;
}

unsigned char Params::left_motor_b_pin(unsigned char left_motor_b_pin)
{
  if (left_motor_b_pin != 0)
    m_left_motor_b_pin = left_motor_b_pin;
  return m_left_motor_b_pin;
}

unsigned char Params::right_motor_a_pin(unsigned char right_motor_a_pin)
{
  if (right_motor_a_pin != 0)
    m_right_motor_a_pin = right_motor_a_pin;
  return m_right_motor_a_pin;
}

unsigned char Params::right_motor_b_pin(unsigned char right_motor_b_pin)
{
  if (right_motor_b_pin != 0)
    m_right_motor_b_pin = right_motor_b_pin;
  return m_right_motor_b_pin;
}

unsigned char Params::charger_pin(unsigned char charger_pin)
{
  if (charger_pin != 0)
    m_charger_pin = charger_pin;
  return m_charger_pin;
}

unsigned int Params::max_charge_time_limit(unsigned int max_charge_time_limit)
{
  if (max_charge_time_limit != 0)
    m_max_charge_time_limit = max_charge_time_limit;
  return m_max_charge_time_limit;
}

unsigned int Params::min_voltage_limit(unsigned int min_voltage_limit)
{
  if (min_voltage_limit != 0)
    m_min_voltage_limit = min_voltage_limit;
  return m_min_voltage_limit;
}

unsigned int Params::peak_voltage_cutoff_limit(unsigned int peak_voltage_cutoff_limit)
{
  if (peak_voltage_cutoff_limit != 0)
    m_peak_voltage_cutoff_limit = peak_voltage_cutoff_limit;
  return m_peak_voltage_cutoff_limit;
}

unsigned int Params::max_left_amps_limit(unsigned int max_left_amps_limit)
{
  if (max_left_amps_limit != 0)
    m_max_left_amps_limit = max_left_amps_limit;
  return m_max_left_amps_limit;
}

unsigned int Params::max_right_amps_limit(unsigned int max_right_amps_limit)
{
  if (max_right_amps_limit != 0)
    m_max_right_amps_limit = max_right_amps_limit;
  return m_max_right_amps_limit;
}

unsigned int Params::overload_interval_limit(unsigned int overload_interval_limit)
{
  if (overload_interval_limit != 0)
    m_overload_interval_limit = overload_interval_limit;
  return m_overload_interval_limit;
}

unsigned int Params::command_CH_code(unsigned int command_CH_code)
{
  if (command_CH_code != 0)
    m_command_CH_code = command_CH_code;
  return m_command_CH_code;
}

unsigned int Params::command_VO_code(unsigned int command_VO_code)
{
  if (command_VO_code != 0)
    m_command_VO_code = command_VO_code;
  return m_command_VO_code;
}

unsigned int Params::command_FL_code(unsigned int command_FL_code)
{
  if (command_FL_code != 0)
    m_command_FL_code = command_FL_code;
  return m_command_FL_code;
}

unsigned int Params::command_AN_code(unsigned int command_AN_code)
{
  if (command_AN_code != 0)
    m_command_AN_code = command_AN_code;
  return m_command_AN_code;
}

unsigned int Params::command_SV_code(unsigned int command_SV_code)
{
  if (command_SV_code != 0)
    m_command_SV_code = command_SV_code;
  return m_command_SV_code;
}

unsigned int Params::command_HB_code(unsigned int command_HB_code)
{
  if (command_HB_code != 0)
    m_command_HB_code = command_HB_code;
  return m_command_HB_code;
}
