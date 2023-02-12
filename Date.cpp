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
    //  ���ݎ���
    time_t nowTime = time(NULL);
    //  ���ߐ؂�
    struct tm deadline;
    deadline.tm_sec = 0;
    deadline.tm_min = 0;
    deadline.tm_hour = 0;
    deadline.tm_mday = day;
    deadline.tm_mon = month - 1;
    deadline.tm_year = year - 1900;
    deadline.tm_isdst = -1;

    //  �ϊ�
    time_t deadline_t = mktime(&deadline);

    float diff = difftime(deadline_t, nowTime);

    //  �b���番
    diff /= 60;
    //  �����玞��
    diff /= 60;
    //  ���Ԃ����
    diff /= 24;

    return (int)diff;
}
