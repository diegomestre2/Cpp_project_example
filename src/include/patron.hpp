#pragma once
#include <string>
class Patron {
public:
	Patron() = default;
	bool has_debt() {
		if (fees > 0)
			return true;
		return false;
	}

	const std::string &get_user_name() {
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
	std::string user_name{"\0"};
	uint32_t lib_number{0};
	double fees{0.0};
};