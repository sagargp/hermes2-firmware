#include <Servo.h>
#include <Wire.h>
#include "params.h"
#include "batterystats.h"

BatteryStats::BatteryStats() :
  m_charged(true)
{
}

BatteryStats::BatteryStats(Params *params) :
  m_params(params),
  m_charged(true)
{
}

void BatteryStats::set_params(Params *params)
{
  m_params = params;
}

void BatteryStats::update()
{
  m_volts      = analogRead(m_params->battery_pin());
  m_left_amps  = analogRead(m_params->left_motor_amps_pin());
  m_right_amps = analogRead(m_params->right_motor_amps_pin());
}

void BatteryStats::check_current_draw()
{
  if (m_left_amps > m_params->max_left_amps_limit())
  {
    analogWrite(m_params->left_motor_a_pin(), 0);
    analogWrite(m_params->left_motor_b_pin(), 0);
    m_last_left_overload_time = millis();
  }

  if (m_right_amps > m_params->max_right_amps_limit())
  {
    analogWrite(m_params->right_motor_a_pin(), 0);
    analogWrite(m_params->right_motor_b_pin(), 0);
    m_last_right_overload_time = millis();
  }
}

void BatteryStats::check_voltage()
{
  // battery too low, and we still think it's "charged"
  if (m_volts < m_params->min_voltage_limit() && m_charged)
  {
    m_charged = false;
    m_high_volts = m_volts;
    m_start_volts = m_volts;
    m_started_charging_time = millis();

    // enable current reg to charge battery
    digitalWrite(m_params->charger_pin(), 0);
  }
}

bool BatteryStats::get_charged()
{
  return m_charged;
}

int BatteryStats::get_voltage()
{
  return m_volts;
}

bool BatteryStats::needs_charge()
{
  bool is_plugged_in = (m_volts - m_start_volts) > m_params->one_volt();
  return !m_charged && is_plugged_in;
}

void BatteryStats::charge()
{
  if (m_volts > m_high_volts)
  {
    m_high_volts = m_volts;
    m_started_charging_time = millis();
  }

  if (m_volts > m_params->peak_voltage_cutoff_limit())
  {
    if ((m_high_volts - m_volts) > 5 || (millis() - m_started_charging_time) > m_params->max_charge_time_limit())
    {
      m_charged = true;
      digitalWrite(m_params->charger_pin(), 1);
    }
  }
}

bool BatteryStats::left_ok()
{
  return (millis() - m_last_left_overload_time > m_params->overload_interval_limit());
}

bool BatteryStats::right_ok()
{
  return (millis() - m_last_right_overload_time > m_params->overload_interval_limit());
}
