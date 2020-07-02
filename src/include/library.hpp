#pragma once
#include "book.hpp"
#include "chrono.hpp"
#include "patron.hpp"
#include "std_lib_facilities.hpp"

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>

struct Transaction {
	Transaction(Patron patron_, Book book_, Date date_) : patron(patron_), book(book_), date(date_{
	}
	Book book;
	Patron patron;
	Date date;
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
		for (auto &patron : patrons) {
			if (patron.has_debt())
				debtors.push_back(patron);
		}
		return debtors;
	}
	void checkout_book(Patron user, Book book_to_borrow) {
		if (std::none_of(patrons.begin(), patrons.end(),
		                 [&](auto patron) { return patron.get_user_name() == user.get_user_name(); })) {
			throw "Patron not valid";
		}
		if (std::none_of(books.begin(), books.end(),
		                 [&](auto book) { return book.get_title() == book_to_borrow.get_title(); })) {
			throw "Book not valid";
		}
		if (patron.has_debt()) {
			throw "Patron has debt";
		}
		Chrono::Date date(Chrono::Year(2020), Chrono::Month::jul, 1);
		transactions.emplace_back(user, book_to_borrow, date);
		std::cout << "checkout complete!" << std::endl;
	}

private:
	Vector<Book> books;
	Vector<Patron> patrons;
	Vector<Transaction> transactions;
};