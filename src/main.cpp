#include <iostream>

//! inline replaces the function definition whereever it is called and makes sure the function won't have a function call overhead.
inline void keep_window_open() { 
    char a{'\0'};
    std::cin >> a;
}

/*int main(int argc, char** argv) {
    std::cout << "Hello, World" << std::endl;
    keep_window_open();
    return 0;
}*/

/*
Exercises

1. Change the program to output the two lines
Hello, programming!
Here we go!
*/

int main(int argc, char** argv) {
	std::cout << "Hello, Programming!" << '\n';
	std::cout << "Here we go!" << std::endl;
}