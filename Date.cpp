#include "Date.h"
#include <time.h>

void Date::SetDate(int year_, int month_, int date_)
{
    year = year_;
    month = month_;
    day = date_;
}

int Date::CalcDifDay()
{
    //  Œ»İŠÔ
    time_t nowTime = time(NULL);
    //  ’÷‚ßØ‚è
    struct tm deadline;
    deadline.tm_sec = 0;
    deadline.tm_min = 0;
    deadline.tm_hour = 0;
    deadline.tm_mday = day;
    deadline.tm_mon = month - 1;
    deadline.tm_year = year - 1900;
    deadline.tm_isdst = -1;

    //  •ÏŠ·
    time_t deadline_t = mktime(&deadline);

    float diff = difftime(deadline_t, nowTime);

    //  •b‚©‚ç•ª
    diff /= 60;
    //  •ª‚©‚çŠÔ
    diff /= 60;
    //  ŠÔ‚©‚ç“ú
    diff /= 24;

    return (int)diff;
}
