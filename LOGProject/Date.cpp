#include "Date.h"
String Date::getStringRep() const{
	String date("",11);
	date[10] = '\0';

	date[1] = '0' + (day % 10);
	date[0] = '0' + (day / 10);

	date[2] = '-';

	date[4] = '0' + (month % 10);
	date[3] = '0' + (month / 10);

	date[5] = '-';

	date[9] = '0' + (year % 10);
	date[8] = '0' + ((year / 10) % 10);
	date[7] = '0' + ((year / 100) % 10);
	date[6] = '0' + (year / 1000);
	// std::cout << date;
	return date;

}
Date Date::currentDate() {
	struct tm ltm;
	time_t now = time(0);
	localtime_s(&ltm, &now);

	return Date(ltm.tm_mday, 1 + ltm.tm_mon, 1900 + ltm.tm_year);
}
Date::Date(int d, int m, int y) {
	if (y < 1) throw "invalid date";
	if (m < 1 || m > 12) throw "invalid date";
	if(d > 31) throw "invalid date";
	if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) throw "invalid date";
	else if(m == 2 && ((y % 4 !=0 && d > 28) || (y % 4 == 0 && d > 29))) throw "invalid date";
	day = d;
	month = m;
	year = y;
}
bool Date::operator!=(const Date& other) const {
	if (Date::year != other.year) return true;
	if (Date::month != other.month) return true;
	if (Date::day != other.day) return true;
	return false;
}