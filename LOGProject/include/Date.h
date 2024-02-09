#ifndef _DATE_
#define _DATE_
#include<iostream>
#include <ctime>
#include "../include/String.h"
class Date {
public:
	class InvalidDate : public  std::runtime_error{
		public:
			InvalidDate() : std::runtime_error("") {}
			const char* what() const noexcept { return "Invalid Date Input! try entering DD-MM-YYYY\n"; }
	};
private:
	int day;
	int month;
	int year;
public:
	static Date currentDate();
	Date(int d, int m, int y);
	String getStringRep() const;
	bool operator!=(const Date & other) const;
	bool operator==(const Date& other) const;
	bool operator>=(const Date& other) const;
	bool operator<=(const Date& other) const;
	bool operator>(const Date& other) const;
	bool operator<(const Date& other) const;
};
#endif