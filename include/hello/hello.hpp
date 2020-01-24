#pragma once
#include <iostream>
#include <string>


class Hello{
public:
	Hello() = default; //Default Constructor
	Hello(const Hello& rhs) = default; // Default Copy Constructor
	Hello(Hello&& rhs) = default; //Default Move Constructor
	Hello& operator=(const Hello& rhs) = default; // Default Copy Assignment
	Hello& operator=(Hello&& rhs) = default; // Default Move Assignment
	~Hello() = default; //Default Destructor

	void print();
private:
	std::string hello{"Hello Example Project!"};
};