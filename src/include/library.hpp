#pragma once
#include "book.hpp"
#include "chrono.hpp"
#include "patron.hpp"

#include <algorithm>
#include <exception>
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
		                 [&](auto patron) { return patron.user_name == user.user_name; })) {
			throw std::exception("Patron not valid");
		}
		if (std::none_of(books.begin(), books.end(), [&](auto book) { return book.title == book_to_borrow.title; })) {
			throw std::exception("Book not valid");
		}
		if (patron.has_debt()) {
			throw std::exception("Patorn has debt");
		}
		auto date = new Date(Year(2020), Month::jul, 1);
		transactions.emplace_back(patron, book, date);
	}

private:
	std::vector<Book> books;
	std::vector<Patron> patrons;
	std::vector<Transaction> transactions;
};