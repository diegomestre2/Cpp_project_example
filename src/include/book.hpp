#pragma once
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

class Book {
public:
	Book() = default;
	Book(std::string isbn_, std::string title_, std::string author_, std::string copyright_date_) {
		if (not is_valid_isbn(isbn_)) {
			throw std::invalid_argument("ISBN not valid. Valid format is n-n-n-x");
		}
		isbn = isbn_;
		author = author_;
		title = title_;
		copyright_date = copyright_date_;
	}
	void check_in() {
	}
	void check_out() {
	}
	bool is_valid_isbn(const std::string &isbn) {
		size_t position = 0;
		size_t count = 0;
		for (auto ch : isbn) {
			count++;
			if (ch != '-') {
				auto digit = static_cast<uint32_t>(ch + '0');
				if ((digit < 0 || digit > 9)) {
					if (count == 4) {
						return true;
					}
					return false;
				}
			}
		}
		return true;
	}
	const std::string &get_isbn() {
		return isbn;
	}
	const std::string &get_title() {
		return title;
	}
	const std::string &get_author() {
		return author;
	}
	const std::string &get_copyright_date() {
		return copyright_date;
	}

private:
	std::string isbn;
	std::string title;
	std::string author;
	std::string copyright_date;
};

bool operator==(const Book &lhs, const Book &rhs) {
	return lhs.get_isbn().compare(rhs.get_isbn()) == 0;
}

bool operator!=(const Book &lhs, const Book &rhs) {
	return lhs.get_isbn().compare(rhs.get_isbn()) != 0;
}

std::ostream &operator<<(std::ostream &os, const Book &rhs) {
	os << rhs.get_title() << '\n';
	os << rhs.get_author() << '\n';
	os << rhs.get_isbn() << '\n';
	os << std::endl;
}

enum class Genre { fiction, nonfiction, periodical, biography, children };
git