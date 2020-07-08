#include "hello.hpp"
#include "hello_ext.hpp"

int main(int argc, char **argv) {
	Hello hello;
	hello.print();
	HelloExt hello_ext;
	hello_ext.print();
	return 0;
}