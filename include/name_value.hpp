#pragma once
#include "std_lib_facilities.hpp"

class NameValue {
public:
	NameValue(string name, double value);

	string name;
	double value;
};