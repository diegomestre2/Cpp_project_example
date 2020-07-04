#pragma once
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

enum class Genre { fiction, nonfiction, periodical, biography, children };
class Book {
public:
	Book() = default;
	Book(std::string isbn_, std::string title_, std::string author_, std::string copyright_date_, Genre genre_);
	void check_in() {
	}
	void check_out() {
	}
	bool is_valid_isbn(std::string &isbn);
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
	Genre get_genre() {
		return genre;
	}

private:
	std::string isbn;
	std::string title;
	std::string author;
	std::string copyright_date;
	Genre genre;
};

bool operator==(const Book &lhs, const Book &rhs);

bool operator!=(const Book &lhs, const Book &rhs);

std::ostream &operator<<(std::ostream &os, const Book &rhs);