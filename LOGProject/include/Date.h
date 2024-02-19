#ifndef _DATE_H_
#define _DATE_H_
#include<iostream>
#include <ctime>
#include "String.h"
	enum class DateFormat {
		DMY, DYM, MDY, MYD, YDM, YMD
	};

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
		DateFormat formatDate;
	public:
		static Date currentDate();
		Date(int d, int m, int y, DateFormat df = DateFormat::DMY);
		bool operator!=(const Date & other) const;
		bool operator==(const Date& other) const;
		bool operator>=(const Date& other) const;
		bool operator<=(const Date& other) const;
		bool operator>(const Date& other) const;
		bool operator<(const Date& other) const;
		friend static String String::to_string(Date);
	};


#endif