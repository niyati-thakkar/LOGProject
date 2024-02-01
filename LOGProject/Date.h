#ifndef _DATE_
#define _DATE_
#include<iostream>
#include <ctime>
#include "String.h"
class Date {
private:
	int day;
	int month;
	int year;
public:
	static Date currentDate();
	Date(int d, int m, int y);
	String getStringRep() const;
	bool operator!=(const Date & other) const;
};
#endif