#pragma once
#include "token.hpp"

#include <iostream>

class TokenStream {
public:
	TokenStream() : buffer_full(false), buffer(0) {
	}
	~TokenStream() = default;
	Token get();
	void putback(Token token);

private:
	bool buffer_full; // flag to indicate whether there is a token in the buffer
	Token buffer;
};