#include <RTClib.h>
#include <SPI.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#include <math.h>
#include "lc_dataset.h"
#include "expoFunc.h"
#include "linearFunc.h"

#define LEDPWM 3
RTC_DS1307 rtc;
DateTime Timestamp;

// Current brightness of the LED
byte y;
// Maximum brightness of the LED
byte ymax;
// Initial brightness of the LED
byte y0 = 1;

bool expoType = false; // If is false uses the linear function to simulate sunrises and sunsets if true uses the expoFunc to simulate sunrises and sunsets

// Current amount of seconds past from midnight(0) when sunrise starts and ends ej. 7:50 -> 28200 s
long sunriseStart;
long sunriseEnd;

// Current amount of seconds past from midnight(0) when sunset starts and ends ej. 7:50 -> 28200 s
long sunsetStart;
long sunsetEnd;

// Current amount of seconds past from midnight(0) ej. 7:50 -> 28200 s
long currentTime;

// Duration of the sunrise and sunset in seconds
int sunriseDuration;
int sunsetDuration;

/**
 * @brief      Sets the brightness of the LED to the given value.
 *
 * If the given value is different from the current brightness, this function
 * sets the brightness of the LED to the given value and returns the new
 * brightness.
 *
 * @param[in]  value  The desired brightness value of the LED.
 * @return     The new brightness value of the LED.
 */
int setPin(byte value)
{
    if (value != y)
    {
        y = value;
        analogWrite(LEDPWM, y);
        return y;
    }
}

/**
 * @brief      Sets the brightness of the LED according to the time of day.
 *
 * This function checks the current time and compares it with the start and end
 * times of the sunrise and sunset. It then sets the brightness of the LED
 * using either the linear or exponential function depending on the value of
 * expoType.
 */
void getLedStatus()
{
    // Sunrise handler
    if (currentTime >= sunriseStart && currentTime < sunriseEnd)
    {
        if (expoType)
        {
            /** Using this type of function has its limitations because the board you are using must be
            able to handle double (64 bits) to perform the operations correctly. Many Arduino boards treat
            double as a float (32 bits), which only provides two decimal places of precision. This issue
            might be addressed using a library like BigNumber or by storing all the digits of a number in an array.
            However, boards like the Nano have limited RAM, which can further complicate this approach. */
            setPin(expoFunc(y0, ymax, sunriseDuration, sunriseStart, currentTime));
        }
        else
        {
            setPin(linearFunction("sunrise", ymax, y0, sunriseDuration, sunriseStart, currentTime));
        }

        Serial.println("Sunrise handler y = " + String(y));
    }

    // Sunset handler
    if (currentTime >= sunsetStart && currentTime < sunsetEnd)
    {
        if (expoType)
        {
            setPin(expoFunc(y0, ymax, sunsetDuration, sunsetStart, currentTime));
        }
        else
        {
            setPin(linearFunction("sunset", ymax, y0, sunsetDuration, sunsetStart, currentTime));
        }

        Serial.println("Sunset handler y = " + String(y));
    }

    // Daytime handler
    if (currentTime >= sunriseEnd && currentTime < sunsetStart)
    {
        setPin(ymax);
        Serial.println("DayTime handler y = " + String(y));
    }

    // Nighttime handler
    if (currentTime >= sunsetEnd || currentTime < sunriseStart)
    {
        setPin(0);
        Serial.println("NightTime handler y = " + String(y));
    }
}

/**
 * @brief      Converts a given hour, minute and optional seconds to total number of seconds.
 *
 * @param[in]  hour   The hour of the day (0-23).
 * @param[in]  min    The minute of the hour (0-59).
 * @param[in]  sec    The second of the minute (0-59). Default is 0.
 *
 * @return     The total number of seconds from midnight.
 */
long toSeconds(byte hour, byte min, byte sec = 0)
{
    return (long)hour * 3600 + min * 60 + sec;
}

void setup()
{
    Serial.begin(19200);
    rtc.begin();
    /**  only have to use the first time to set the time. Once set the RTC to the current date and time, load the script once more time with this line removed or commented because if not when power supply is lost the RTC will be set to the date that we first set it to.
     */
    // rtc.adjust(DateTime(2025, 1, 27, 18, 25, 58));

    pinMode(LEDPWM, OUTPUT);
}

void loop()
{
    Timestamp = rtc.now(); // getting the current date and hour

    byte currentHour = int(Timestamp.hour());
    byte currentMinute = int(Timestamp.minute());
    byte currentSecond = int(Timestamp.second());
    byte currentDay = int(Timestamp.day());
    byte currentMonth = int(Timestamp.month());

    byte dayIndex = (int)currentDay - 1;
    byte monthIndex = (int)currentMonth - 1;

    ymax = pgm_read_byte(&(months[monthIndex][31][0])); // Max Brightness

    byte sunriseHour = pgm_read_byte(&(months[monthIndex][dayIndex][0]));
    byte sunriseMinute = pgm_read_byte(&(months[monthIndex][dayIndex][1]));
    byte sunsetHour = pgm_read_byte(&(months[monthIndex][dayIndex][2]));
    byte sunsetMinute = pgm_read_byte(&(months[monthIndex][dayIndex][3]));

    sunriseDuration = pgm_read_word(&(months[monthIndex][31][1]));
    sunsetDuration = pgm_read_word(&(months[monthIndex][31][2]));

    currentTime = toSeconds(currentHour, currentMinute, currentSecond); // Current amount of seconds past from midnight(0)

    sunriseStart = toSeconds(sunriseHour, sunriseMinute); // Current amount of seconds past from midnight(0)
    sunriseEnd = (long)sunriseStart + sunriseDuration;    // Current amount of seconds past from midnight(0)

    // Notice sunsetHour and sunsetMinute is the ending of the sunset when sun is out of the horizon so sunset star is sunset end - sunset duration
    sunsetStart = toSeconds(sunsetHour, sunsetMinute); // Current amount of seconds past from midnight(0)
    sunsetEnd = (long)sunsetStart + sunsetDuration;    // Current amount of seconds past from midnight(0)

    Serial.println(currentHour + ":" + currentMinute);
    Serial.println();

    getLedStatus();

    Serial.println();
}
