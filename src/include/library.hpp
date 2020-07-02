#pragma once
#include "book.hpp"
#include "chrono.hpp"
#include "patron.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

struct Transaction {
	Transaction(Patron patron_, Book book_, Chrono::Date date_) : book(book_), patron(patron_), date(date_) {
	}
	Book book;
	Patron patron;
	Chrono::Date date;
};

class Library {
public:
	Library() = default;
	void add_book(Book book) {
		books.push_back(book);
	}
	void add_patron(Patron patron) {
		patrons.push_back(patron);
	}
	std::vector<Patron> get_debtors() {
		std::vector<Patron> debtors;
		for (auto patron : patrons) {
			auto has_debt = patron.has_debt();
			if (has_debt)
				debtors.push_back(patron);
		}
		return debtors;
	}
	void checkout_book(Patron user, Book book_to_borrow) {
		if (std::none_of(patrons.begin(), patrons.end(),
		                 [&](auto patron) { return patron.get_user_name() == user.get_user_name(); })) {
			std::cout << "Patron not valid" << std::endl;
			exit(1);
		}
		if (std::none_of(books.begin(), books.end(),
		                 [&](auto book) { return book.get_title() == book_to_borrow.get_title(); })) {
			std::cout << "Book not valid" << std::endl;
			exit(1);
		}
		if (user.has_debt()) {
			std::cout << "Patron has debt" << std::endl;
			exit(1);
		}
		Chrono::Date date(Chrono::Year(2020), Chrono::Month::jul, 1);
		transactions.emplace_back(user, book_to_borrow, date);
		std::cout << "checkout complete!" << std::endl;
	}

private:
	std::vector<Book> books;
	std::vector<Patron> patrons;
	std::vector<Transaction> transactions;
};