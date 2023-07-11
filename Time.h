#pragma once
#define UNIX_EPOCH_YEAR_AD 1970 // 1970
#define SECONDS_PER_DAY (24 * 60 * 60) // 86400
#define IS_LEAP_YEAR(year) (!((year) % 4) && (((year) % 100) || !((year) % 400)))
#define YEAR_SIZE(year) (IS_LEAP_YEAR(year) ? 366 : 365)

#define YEAR_KEY "year"
#define MONTH_KEY "month"
#define DAY_KEY "day"
#define WEEKDAY_KEY "weekday"
#define HOUR_KEY "hour"
#define MINUTE_KEY "minute"
#define SECOND_KEY "second"
#define DST_KEY "dst"
class Time
{
};

