#ifndef __BATTERYSTATS_H__
#define __BATTERYSTATS_H__

#include <Arduino.h>
#include "params.h"

class BatteryStats
{
  private:
    Params *m_params;
    unsigned int m_volts, m_high_volts, m_start_volts;
    unsigned int m_left_amps, m_right_amps;
    unsigned int m_last_left_overload_time, m_last_right_overload_time;
    unsigned int m_started_charging_time;
    bool m_charged;
    
  public:
    BatteryStats();

    BatteryStats(Params *params);

    void set_params(Params *params);

    void update();

    void check_current_draw();

    void check_voltage();

    int get_voltage();

    bool needs_charge();

    bool get_charged();

    void charge();

    bool left_ok();

    bool right_ok();
};

#endif
