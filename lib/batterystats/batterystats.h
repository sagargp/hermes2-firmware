#ifndef __BATTERYSTATS_H__
#define __BATTERYSTATS_H__

#include "params.h"

class BatteryStats
{
  private:
    int m_volts, m_left_amps, m_right_amps;
    int m_last_left_overload_time, m_last_right_overload_time;
    Params *m_params;
    
  public:
    BatteryStats();

    BatteryStats(Params *params);

    void set_params(Params *params);

    void update();

    void check_current_draw();

    void check_voltage();

    bool needs_charge();

    void charge();
};

#endif
