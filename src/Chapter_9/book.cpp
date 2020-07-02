#include "book.hpp"

Book::Book(std::string isbn_, std::string title_, std::string author_, std::string copyright_date_, Genre genre_)
    : genre(genre_) {
	if (not is_valid_isbn(isbn_)) {
		throw std::invalid_argument("ISBN not valid. Valid format is n-n-n-x");
	}
	isbn = isbn_;
	author = author_;
	title = title_;
	copyright_date = copyright_date_;
}

bool operator==(Book &lhs, Book &rhs) {
	return lhs.get_isbn().compare(rhs.get_isbn()) == 0;
}

bool operator!=(Book &lhs, Book &rhs) {
	return lhs.get_isbn().compare(rhs.get_isbn()) != 0;
}

std::ostream &operator<<(std::ostream &os, Book &rhs) {
	os << rhs.get_title() << '\n';
	os << rhs.get_author() << '\n';
	os << rhs.get_isbn() << '\n';
	os << std::endl;
	return os;
}

bool Book::is_valid_isbn(std::string &isbn) {
	size_t count = 0;
	for (auto ch : isbn) {
		if (ch != '-') {
			count++;
			auto digit = static_cast<uint32_t>(ch - '0');
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