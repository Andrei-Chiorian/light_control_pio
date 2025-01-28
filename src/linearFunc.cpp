#include <linearFunc.h>

/**
 * @brief      Calculates the brightness of an LED over time based on a linear function.
 *
 * This function simulates the brightness change of an LED during sunrise or sunset.
 * Depending on the type, it calculates the slope and intercept of the linear function
 * and returns the brightness for a given time.
 *
 * @param[in]  type      The type of event ("sunrise" or "sunset").
 * @param[in]  ymax      The maximum brightness of the LED.
 * @param[in]  y0        The initial brightness of the LED.
 * @param[in]  duration  The duration of the event in seconds.
 * @param[in]  start     The starting time of the event in seconds from midnight.
 * @param[in]  time      The current time in seconds from midnight.
 *
 * @return     The current brightness of the LED as a byte value.
 *             Returns 0 if the type is neither "sunrise" nor "sunset".
 */

int linearFunction(String type, int ymax, int y0, int duration, long start, long time)
{
    float slope;
    float intercept;

    if (type == "sunrise")
    {
        slope = float(ymax - y0) / duration;
        intercept = 1 - (slope * start);        
        
    }
    else if (type == "sunset")
    {
        slope = float(ymax - y0) / -duration;
        intercept = ymax - (slope * start);        
    }
    else
    {
        return 0;
    }

    byte y = round(slope * time + intercept);
    return y;
}