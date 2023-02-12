#pragma once

class Date
{
private:
	int year = 0;
	int month = 0;
	int day = 0;
public:
	Date() {};
	Date(int year_, int month_, int date_) :year(year_), month(month_), day(date_) {};

	void SetDate(int year_, int month_, int date_);

	int GetYear() { return year; }
	int GetMonth() { return month; }
	int GetDay() { return day; }
};

