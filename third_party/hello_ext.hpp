#pragma once
#include <iostream>
#include <string>

class HelloExt {
public:
	HelloExt() = default;
	~HelloExt() = default;
	void print() {
		std::cout << hello << std::endl;
	}
	// internal member
private:
	std::string hello{"Hello ExternalWorld"};
};