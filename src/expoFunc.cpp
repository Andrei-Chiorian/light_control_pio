#include <expoFunc.h>

/**
 * @brief      Exponential brightness function to simulate sunrises and sunsets
 *
 * @param[in]  y0        The initial brightness of the LED.
 * @param[in]  ymax      The maximum brightness of the LED.
 * @param[in]  duration  The duration of the sunrise or sunset in seconds.
 * @param[in]  start     The starting time of the sunrise or sunset in seconds.
 * @param[in]  time      The current time in seconds.
 *
 * @return     The current brightness of the LED.
 */
int expoFunc(byte y0, byte ymax, int duration, long start, long time)
{
    double k = double(log(ymax / y0)) / duration;

    double t = (time - start);

    int y = y0 * exp(k * t);

    if (start > 50400) y = ymax - (y - y0);    

    return y;
}