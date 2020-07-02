#pragma once

#include <iostream>
namespace Chrono {

class Year {
	static constexpr int min = 1800;
	static constexpr int max = 2200;

public:
	class Invalid {};
	Year(int year);
	int get_year() const {
		return value;
	}
	void add_year(int n) {
		value += n;
	}

private:
	int value{0};
};
enum class Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
class Date {
public:
	class Invalid {};
	Date();
	Date(Year y, Month m, int d);
	// non modifying operations
	int get_day() const {
		return day;
	}
	Month get_month() const {
		return month;
	}
	int get_year() const {
		return year.get_year();
	}
	// modifying operations
	void add_day(int n);
	void add_year(int n);
	bool is_valid();

private:
	// internal members
	int day{1};
	Month month{Month::jan};
	Year year{2001};
};
Month int_to_month(int value);
Month operator++(Month &m);
bool is_date(Year y, Month m, int d);
bool is_leapyear(Year y);
bool operator==(const Date &a, const Date &d);
bool operator!=(const Date &a, const Date &d);
std::ostream &operator<<(std::ostream &os, const Date &d);
std::istream &operator>>(std::istream &is, Date &d);
enum class Day { monday, tuesday, wednesday, thursday, friday, saturday, sunday };
Day day_of_week(const Date &d);
Date next_sunday(const Date d);
Date next_weekday(const Date &d);
} // namespace Chrono