#pragma once
#include "std_lib_facilities.hpp"

class EnglishEvaluator {
public:
	EnglishEvaluator();
	bool evaluate_sentence();
	bool evaluate_conjunction(string word);
	bool evaluate_noun(string word);
	bool evaluate_verb(string word);
	bool evaluate_article(string word);
	void init();

private:
	vector<string> verbs;
	vector<string> nouns;
	vector<string> articles;
	vector<string> conjunctions;
};