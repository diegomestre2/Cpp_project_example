#pragma once
#include "std_lib_facilities.hpp"
#include "token.hpp"
#include "token_stream.hpp"

class Calculator {
public:
	Calculator() = default;
	~Calculator() = default;
	//! Read characters to compose tokens
	Token get_token();
	//! Deals with operators (+ and -)
	double evaluate_expression();
	//! Deals with *, / and %
	double next_term();
	//! Deals with numbers and parentheses - calls expression() and get_token()
	double next_primary();
	//!  Puts a token back to the stream
	void putback_token(Token token);
	//! Calculates the factorial of a given number
	int factorial(int number);
	//! Deals with factorial ! and numbers
	int next_value(int number);

private:
	TokenStream ts;
};