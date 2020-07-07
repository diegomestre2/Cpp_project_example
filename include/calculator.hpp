
#include "std_lib_facilities.hpp"

constexpr const char quit = 'q';
constexpr const char print = ';';
constexpr const char number = '8';
constexpr const char prompt = '>';
constexpr const char result_char = '=';
constexpr const char let = 'L';
constexpr const char from = 'F';
constexpr const char to = 'T';
constexpr const char name = 'n';
constexpr const char *decllet = "let";
constexpr const char *declfrom = "from";
constexpr const char *declto = "to";

//------------------------------------------------------------------------------

class Variable {
public:
	Variable() = default;
	Variable(string name_, double value_) : name(name_), value(value_) {
	}
	~Variable() = default;
	string name;
	double value;
};

class Token {
public:
	Token(char ch) // make a Token from a char
	    : kind(ch), value(0.0) {
	}
	Token(char ch, double val) // make a Token from a char and a double
	    : kind(ch), value(val) {
	}
	Token(char kind_, string name_) // make a token for a variable
	    : kind(kind_), name(name_) {
	}
	char kind{0};      // what kind of token
	double value{0.0}; // for numbers: a value
	string name{"\0"}; // name for variable
};

//------------------------------------------------------------------------------

class TokenStream {
public:
	// The constructor just sets full to indicate that the buffer is empty:
	TokenStream() = default; // make a Token_stream that reads from cin
	Token get();             // get a Token (get() is defined elsewhere)
	void putback(Token t);   // put a Token back
	void ignore(char c);

private:
	bool full{false}; // is there a Token in the buffer?
	Token buffer{0};  // here is where we keep a Token put back using putback()
};

class Calculator {
public:
	Calculator() = default;
	~Calculator() = default;
	void run();
	void run_cli();
	// deal with (,), and numbers
	double get_primary();
	// deal with *, /, and %
	double get_term();
	// deal with + and -
	double get_expression();
	void clean_up();
	double statement();
	double declaration();
	double get_input_from_file();
	void write_output_to_file();
	bool is_declared(const string &var);
	double define_name(const string &var_name, double value);
	Token get_token_for_name(const string &name);

private:
	TokenStream ts; // provides get() and putback()
	vector<Variable> var_table;
};
