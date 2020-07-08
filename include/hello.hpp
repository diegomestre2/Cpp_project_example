#pragma once
#include <iostream>
#include <string>
class Hello {
public:
	Hello() = default;
	~Hello() = default;
	// member functions
	void print();

private:
	std::string hello{"Hello World"};
};