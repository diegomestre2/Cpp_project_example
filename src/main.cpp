#include <iostream>
#include <library.hpp>

int main(int argc, char **argv) {
	Library lib;
	auto book1 = Book("1-2-3-A", "one up", "Peter Lynch", "02-07-2020", Genre::nonfiction);
	auto book2 = Book("1-2-4-A", "learn to earn", "Peter Lynch", "02-07-2020", Genre::nonfiction);
	lib.add_book(book1);
	lib.add_book(book2);
	auto patron1 = Patron("diego", 123);
	auto patron2 = Patron("jessica", 124);
	lib.add_patron(patron1);
	lib.checkout_book(book1, patron1);
	lib.checkout_book(book2, patron2);
}