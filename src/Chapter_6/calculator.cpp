#include <calculator.hpp>

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void TokenStream::putback(Token t) {
	if (full)
		error("putback() into a full buffer");
	buffer = t;  // copy t to buffer
	full = true; // buffer is now full
}

Token TokenStream::get() {
	if (full) { // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch; // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case print: // for "print"
	case quit:  // for "quit"
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case result_char:
		return Token(ch); // let each character represent itself
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9': {
		cin.putback(ch); // put digit back into the input stream
		double val;
		cin >> val; // read a floating-point number
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
				s += ch;
			cin.putback(ch);
			if (s == decllet) {
				return Token(let);
			} else if (s == declfrom) {
				return Token(from);
			} else if (s == declto) {
				return Token(to);
			}
			return Token(name, s);
		}
		error("Bad token");
	}
	return Token(0, 0);
}

void TokenStream::ignore(char c) {
	// first look in buffer
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;
	// now search input
	char ch{'\0'};
	while (cin >> ch)
		if (ch == 0)
			return;
}

void Calculator::run() {
	try {
		// pre defined names
		define_name("pi", 3.1415926535);
		define_name("e", 2.7182818284);
		define_name("k", 1000);

		run_cli();
	} catch (runtime_error &e) {
		cerr << e.what() << '\n';
		cout << "Please enter the character ~ to close the window\n";
		for (char ch; cin >> ch;) {
			if (ch == '~')
				exit(1);
		}
		exit(1);
	} catch (exception &e) {
		cerr << "error: " << e.what() << '\n';
		clean_up();
	} catch (...) {
		cerr << "Oops: unknown exception!\n";
		keep_window_open("~~");
		exit(2);
	}
}

void Calculator::run_cli() {
	while (cin) {
		cout << prompt;

		Token t = ts.get();
		while (t.kind == print) // eat ';'
			t = ts.get();
		if (t.kind == quit) { // 'q' for quiting
			keep_window_open();
			exit(0);
		}
		ts.putback(t);
		cout << result_char << statement() << '\n';
	}
	keep_window_open();
}

double Calculator::statement() {
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	case name: {
		if (is_declared(t.name)) {
			t = get_token_for_name(t.name);
			ts.putback(t);
			return get_expression();
		}
		error("variable name not declared!");
	}
	case from: {
		return get_input_from_file();
	}
	case to: {
		write_output_to_file();
	}
	default:
		ts.putback(t);
		return get_expression();
	}
}

double Calculator::declaration() {
	auto token = ts.get();
	if (token.kind != name) {
		error("name expected in declaration");
	}
	string var_name = token.name;
	auto next_token = ts.get();
	if (next_token.kind != result_char) {
		error("= missing in declaration");
	}

	auto exp = get_expression();
	define_name(var_name, exp);
	return exp;
}
// deal with + and -
double Calculator::get_expression() {
	double left = get_term(); // read and evaluate a Term
	Token t = ts.get();       // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += get_term(); // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= get_term(); // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t); // put t back into the token stream
			return left;   // finally: no more + or -: return the answer
		}
	}
}

// deal with *, /, and %
double Calculator::get_term() {
	double left = get_primary();
	Token t = ts.get(); // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= get_primary();
			t = ts.get();
			break;
		case '/': {
			double d = get_primary();
			if (d == 0)
				error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%': {
			double d = get_primary();
			if (d == 0)
				error("%: divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t); // put t back into the token stream
			return left;
		}
	}
}

double Calculator::get_primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(': // handle '(' expression ')'
	{
		double d = get_expression();
		t = ts.get();
		if (t.kind != ')')
			error("'), expected");
		return d;
	}
	case number:        // we use '8' to represent a number
		return t.value; // return the number's value
	case '-': {
		return -get_primary();
	}
	case '+': {
		return get_primary();
	}
	default:
		error("primary expected");
	}
	return 0.0;
}

void Calculator::clean_up() {
	ts.ignore(print);
}

bool Calculator::is_declared(const string &var) {
	for (auto &v : var_table) {
		if (v.name == var) {
			return true;
		}
	}
	return false;
}

double Calculator::define_name(const string &var_name, double value) {
	if (is_declared(var_name)) {
		error(var_name, "declared twice");
	}
	var_table.emplace_back(var_name, value);
	return value;
}

Token Calculator::get_token_for_name(const string &name) {
	if (is_declared(name)) {
		for (auto &v : var_table) {
			if (v.name == name) {
				return Token(number, v.value);
			}
		}
	}
	error("Name not declared");
	return Token(quit);
}

double Calculator::get_input_from_file() {
	auto token = ts.get();
	if (token.kind != name) {
		error("name expected in from file");
	}
	string file_name = token.name + ".txt";
	ifstream input_file(file_name);
	char ch{'\0'};
	while (true) {
		if (!(input_file >> ch))
			break;
		ts.putback(ch);
	}
	auto exp = get_expression();
	return exp;
}
void Calculator::write_output_to_file() {
	auto token = ts.get();
	if (token.kind != name) {
		error("name expected in from file");
	}
	string file_name = token.name + ".txt";
	ofstream output{file_name};
	auto exp = get_expression();
	output << "=" << exp << '\n';
	keep_window_open();
	exit(0);
}