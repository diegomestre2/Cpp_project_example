#pragma once
#include <exception>
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
		return true;
	}
	std::string &get_isbn() {
		return isbn;
	}
	std::string &get_title() {
		return title;
	}
	std::string &get_author() {
		return author;
	}
	std::string &get_copyright_date() {
		return copyright_date;
	}

private:
	std::string isbn;
	std::string title;
	std::string author;
	std::string copyright_date;
};