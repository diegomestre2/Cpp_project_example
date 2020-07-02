#pragma once
#include "std_lib_facilities.hpp"
class Patron {
public:
	Patron(String &user_name_, uint32_t lib_number_) : user_name(user_name_), lib_number(lib_number_) {
	}
	bool has_debt() {
		if (fees > 0)
			return true;
		return false;
	}

	const String &get_user_name() {
		return user_name;
	}
	const uint32_t get_lib_number() {
		return lib_number;
	}
	const double get_fees() {
		return fees;
	}
	void set_fee(double new_fee) {
		fees += new_fee;
	}

private:
	String user_name{"\0"};
	uint32_t lib_number{0};
	double fees{0.0};
};