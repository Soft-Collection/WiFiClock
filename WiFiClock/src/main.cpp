#include <Arduino.h>
#include "ClockLEDDisplay.h"
#include "RTC.h"
#include "Config.h"
#include "Period.h"

RTC rtc;
ClockLEDDisplay cld;
Period period100_1(NULL, 100, true);
Period period100_2(NULL, 100, true);

static void on_period100_1(void *instance);
static void on_period100_2(void *instance);

void setup()
{
   Serial.begin(115200);
   rtc.Init();
   cld.Init();
   period100_1.AddOnPeriodExpiredHandler(on_period100_1);
   period100_2.AddOnPeriodExpiredHandler(on_period100_2);
}
void loop()
{
   int8_t hour;
   int8_t minute;
   int8_t second;
   rtc.GetTime(hour, minute, second);
   uint32_t TC = millis();
   bool isUpdated = rtc.GetIsUpdated();
   if (!isUpdated)
   {
      period100_1.Check(TC); //Points only.
      return;
   }
   else
   {
      period100_2.Check(TC); //Time and points.
   }
}
void on_period100_1(void *instance)
{
   cld.DisplayPointsOnly(millis() % 1000 > 500);
}
void on_period100_2(void *instance)
{
   int8_t hour;
   int8_t minute;
   int8_t second;
   rtc.GetTime(hour, minute, second);
   cld.DisplayTime(hour, minute, millis() % 1000 > 500);
}
