#pragma once

class Patron {
public:
	Patron() = default;
	bool has_debt() {
		if (fees > 0)
			return true;
		return false;
	}

private:
	std::string user_name;
	uint32_t lib_number;
	double fees;
};