#ifndef __PARAMS_H__
#define __PARAMS_H__

#include <Arduino.h>

typedef enum Modes { MODE_NONE, MODE_RC, MODE_SERIAL, MODE_I2C } Mode_Type;

class Params
{
  private:
    Mode_Type m_mode;                         // The mode of operation. only SERIAL really does anything though.
    unsigned int m_baud_rate;                 // The baud rate (eg. 9600)
    unsigned int m_i2c_addr;                  // The i2c address for this device
    unsigned int m_one_volt;                  // How much of a change on the battery analog pin signifies 1 volt

    // pins
    unsigned char m_battery_pin;              // Analog input 00
    unsigned char m_left_motor_amps_pin;      // Analog input 06
    unsigned char m_right_motor_amps_pin;     // Analog input 07
    unsigned char m_left_motor_a_pin;         // Left motor H bridge, input A
    unsigned char m_left_motor_b_pin;         // Left motor H bridge, input B
    unsigned char m_right_motor_a_pin;        // Right motor H bridge, input A
    unsigned char m_right_motor_b_pin;        // Right motor H bridge, input B
    unsigned char m_charger_pin;              // Low = ON, High = OFF

    // limits
    unsigned int m_max_charge_time_limit;       // If the battery voltage does not change in this number of milliseconds then stop charging.
    unsigned int m_min_voltage_limit;         // This is the voltage at which the speed controller goes into recharge mode.
    unsigned int m_peak_voltage_cutoff_limit; // This is the nominal battery voltage reading. Peak charge can only occur above this voltage.
    unsigned int m_max_left_amps_limit;       // set overload current for left motor
    unsigned int m_max_right_amps_limit;      // set overload current for right motor
    unsigned int m_overload_interval_limit;   // interval in ms after which it's safe to drive the motors again after an overload

    // Command constants. These are computed as (A << 8) + B for AB in: CH, VO, FL, AN, SV, HB
    unsigned int m_command_CH_code;           // Change mode (I2C <--> Serial)
    unsigned int m_command_VO_code;           // Get voltage
    unsigned int m_command_FL_code;           // Flush buffers
    unsigned int m_command_AN_code;           // Read analog pins
    unsigned int m_command_SV_code;           // Set servo positions
    unsigned int m_command_HB_code;           // Set motors

  public:
    Params();

    // getters/setters
    Mode_Type mode(Mode_Type mode=MODE_NONE);

    unsigned int baud_rate(unsigned int baud_rate=0);

    unsigned int i2c_addr(unsigned int i2c_addr=0);

    unsigned int one_volt(unsigned int one_volt=0);

    unsigned char battery_pin(unsigned char battery_pin=0);

    unsigned char left_motor_amps_pin(unsigned char left_motor_amps_pin=0);

    unsigned char right_motor_amps_pin(unsigned char right_motor_amps_pin=0);

    unsigned char left_motor_a_pin(unsigned char left_motor_a_pin=0);

    unsigned char left_motor_b_pin(unsigned char left_motor_b_pin=0);

    unsigned char right_motor_a_pin(unsigned char right_motor_a_pin=0);

    unsigned char right_motor_b_pin(unsigned char right_motor_b_pin=0);

    unsigned char charger_pin(unsigned char charger_pin=0);

    unsigned int max_charge_time_limit(unsigned int max_charge_time_limit=0);

    unsigned int min_voltage_limit(unsigned int min_voltage_limit=0);

    unsigned int peak_voltage_cutoff_limit(unsigned int peak_voltage_cutoff_limit=0);

    unsigned int max_left_amps_limit(unsigned int max_left_amps_limit=0);

    unsigned int max_right_amps_limit(unsigned int max_right_amps_limit=0);

    unsigned int overload_interval_limit(unsigned int overload_interval_limit=0);

    unsigned int command_CH_code(unsigned int command_CH_code=0);

    unsigned int command_VO_code(unsigned int command_VO_code=0);

    unsigned int command_FL_code(unsigned int command_FL_code=0);

    unsigned int command_AN_code(unsigned int command_AN_code=0);

    unsigned int command_SV_code(unsigned int command_SV_code=0);

    unsigned int command_HB_code(unsigned int command_HB_code=0);
};

#endif
