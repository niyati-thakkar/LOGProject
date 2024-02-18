#include "../include/Date.h"
namespace Date{
	String Date::getStringRep() const{
		String date;
		String day = String::to_string(this->day);
		String month = String::to_string(this->month);
		String year = String::to_string(this->year);
		if (day.getSize() == 1) {
			day = "0" + day;
		}
		if (month.getSize() == 1) {
			month = "0" + month;
		}
		if (year.getSize() == 1) {
			year = "000" + year;
		}
		if (year.getSize() == 2) {
			year = "00" + year;
		}
		if (year.getSize() == 3) {
			year = "0" + year;
		}

		DateFormat df = formatDate;
		switch (df) {
		case DateFormat::DMY:
			date = day + "/" + month + "/" + year;
			break;
		case DateFormat::DYM:
			date = day + "/" + year + "/" + month;
			break;
		case DateFormat::MDY:
			date = month + "/" + day + "/" + year;
			break;
		case DateFormat::MYD:
			date = month + "/" + year + "/" + day;
			break;
		case DateFormat::YDM:
			date = year + "/" + day + "/" + month;
			break;
		case DateFormat::YMD:
			date = year + "/" + month + "/" + day;
			break;
		}
		// std::cout << date;
		return date;
	}

	Date Date::currentDate() {
		struct tm ltm;
		time_t now = time(0);
		localtime_s(&ltm, &now);

		return Date(ltm.tm_mday, 1 + ltm.tm_mon, 1900 + ltm.tm_year);
	}

	Date::Date(int i, int j, int k, DateFormat df) {
		int d = 0, m = 0, y = 0;
		formatDate = df;
		//DateFormat df = DateFormatter::getInstance().getDateFormat();
		switch (df) {
			case DateFormat::DMY: 
				d = i;
				m = j;
				y = k;
				break;
			case DateFormat::DYM:
				d = i;
				m = k;
				y = j;
				break;
			case DateFormat::MDY:
				d = j;
				m = i;
				y = k;
				break;
			case DateFormat::MYD:
				d = k;
				m = i;
				y = j;
				break;
			case DateFormat::YDM:
				d = j;
				m = k;
				y = i;
				break;
			case DateFormat::YMD:
				d = k;
				m = j;
				y = i;
				break;
		}
		//static_assert(y < 1, "year cannot be less than 1");
		if (y < 1) throw InvalidDate{};
		if (m < 1 || m > 12) throw InvalidDate{};
		if(d > 31) throw InvalidDate{};
		if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) throw InvalidDate{};
		else if(m == 2 && ((y % 4 !=0 && d > 28) || (y % 4 == 0 && d > 29))) throw InvalidDate{};
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
	bool Date::operator==(const Date& other) const {
		if (Date::year == other.year) return true;
		if (Date::month == other.month) return true;
		if (Date::day == other.day) return true;
		return false;
	}
	bool Date::operator<=(const Date& other) const {
		if (Date::year < other.year) return true;
		if (Date::year == other.year && Date::month < other.month) return true;
		if (Date::month == other.month && Date::day <= other.day) return true;
		return false;
	}
	bool Date::operator>=(const Date& other) const {
		if (Date::year > other.year) return true;
		if (Date::year == other.year && Date::month > other.month) return true;
		if (Date::month == other.month && Date::day >= other.day) return true;
		return false;
	}
	bool Date::operator>(const Date& other) const {
		if (Date::year > other.year) return true;
		if (Date::year == other.year && Date::month > other.month) return true;
		if (Date::month == other.month && Date::day > other.day) return true;
		return false;
	}
	bool Date::operator<(const Date& other) const {
		if (Date::year < other.year) return true;
		if (Date::year == other.year && Date::month < other.month) return true;
		if (Date::month == other.month && Date::day < other.day) return true;
		return false;
	}
}