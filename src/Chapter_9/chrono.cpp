#include "chrono.hpp"

namespace Chrono {

Month int_to_month(int value) {
	Month new_month{value};
	if (new_month < Month::jan || Month::dec < new_month)
		error("bad month!");
	return new_month;
}

Month operator++(Month &m) {
	return (m == Month::dec) ? Month::jan : Month(int(m) + 1);
}

Year::Year(int year) : value{year} {
	if (year < min || max <= year)
		throw Invalid();
}

Date::Date(Year y, Month m, int d) : day{d}, month{m}, year{y} {
	if (not is_date(y, m, d))
		throw Invalid{};
}
const Date &default_date() {
	static Date dd(2001, Month::jan, 1);
	return dd;
}

Date::Date() : day{default_date().day}, month{default_date().month}, year{default_date().year} {
}

ostream &operator<<(ostream &os, const Date &date) {
	return os << "(" << date.get_year() << "," << int(date.get_month()) << "," << date.get_day() << ')' << std::endl;
}

void Date::add_day(int n) {
	day += n;
	while (day > 31) {
		if (month < Month::dec) {
			// month++;
			day -= 31;
		} else {
			// sum year
			day++;
			day--;
		}
	}
}

void Date::add_year(int n) {
	if (month == Month::feb && day == 29 && !is_leapyear(year.get_year() + n)) {
		month = Month::mar;
		day = 1;
	}
	year.add_year(n);
}

bool Date::is_valid() {
	if (month < Month::jan || Month::dec < month)
		return false;
	if (day < 1 || 31 < day)
		return false;
	return true;
}

bool is_date(Year y, Month m, int d) {

	if (d <= 0)
		return false;

	if (m < Month::jan || Month::dec < m)
		return false;

	int days_in_month = 31;
	switch (m) {
	case Month::feb:
		days_in_month = is_leapyear(y.get_year() ? 29 : 28);
		break;
	case Month::apr:
	case Month::jun:
	case Month::sep:
	case Month::nov:
		days_in_month = 30;
		break;
	default:
		break;
	}
	if (days_in_month < d)
		return false;
	return true;
}

bool is_leapyear(Year y) {
	return true;
}
bool operator==(const Date &a, const Date &b) {
	return a.get_year() == b.get_year() && a.get_month() == b.get_month() && a.get_day() == b.get_day();
}
bool operator!=(const Date &a, const Date &b) {
	return !(a == b);
}

istream &operator>>(istream &is, Date &b) {
	int y, m, d;
	char ch1, ch2, ch3, ch4;
	is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
	if (!is)
		return is;
	if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') {
		is.clear(ios_base::failbit);
	}
	b = Date(y, Month(m), d);
	return is;
}
Day day_of_week(const Date &d) {
	return Day::friday;
}
Date next_sunday(const Date d) {
	return Date();
}
Date next_weekday(const Date &d) {
	return Date();
}

} // namespace Chrono