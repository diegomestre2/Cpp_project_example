#pragma once

#include "std_lib_facilities.hpp"

class Permutation {
public:
	Permutation() = delete; // Default Constructor
	Permutation(int a, int b);
	~Permutation() = default;                                 // Default Destructor
	Permutation(const Permutation &rhs) = default;            // Copy Constructor
	Permutation &operator=(const Permutation &rhs) = default; // Copy Assignment operator
	Permutation(Permutation &&rhs) = default;                 // Move Assignment Constructor
	Permutation &operator=(Permutation &&rhs) = default;      // Move Assigment operator
	void calculate_permutation();

private:
	int a;
	int b;
};