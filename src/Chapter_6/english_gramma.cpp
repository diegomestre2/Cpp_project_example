#include "english_gramma.hpp"

EnglishEvaluator::EnglishEvaluator() {
}

bool EnglishEvaluator::evaluate_sentence() {
	string word;
	std::cin >> word;
	auto is_article = evaluate_article(word);
	if (!is_article)
		return false;

	std::cin >> word;
	auto is_noun = evaluate_noun(word);
	if (!is_noun)
		return false;
	std::cin >> word;
	auto is_verb = evaluate_verb(word);
	if (!is_verb)
		return false;

	std::cin >> word;
	if (word == ".")
		return true;
	auto is_conjunction = evaluate_conjunction(word);
	if (!is_conjunction)
		return false;
	return evaluate_sentence();
}
bool EnglishEvaluator::evaluate_conjunction(string word) {
	for (auto conjunction : conjunctions) {
		if (conjunction.compare(word) == 0) {
			return true;
		}
	}
	return false;
}
bool EnglishEvaluator::evaluate_noun(string word) {
	for (auto noun : nouns) {
		if (noun.compare(word) == 0) {
			return true;
		}
	}
	return false;
}
bool EnglishEvaluator::evaluate_verb(string word) {
	for (auto verb : verbs) {
		if (verb.compare(word) == 0) {
			return true;
		}
	}
	return false;
}
bool EnglishEvaluator::evaluate_article(string word) {
	for (auto article : articles) {
		if (article.compare(word) == 0) {
			return true;
		}
	}
	return false;
}

void EnglishEvaluator::init() {
	articles.push_back("The");
	articles.push_back("a");
	articles.push_back("an");

	nouns.push_back("birds");
	nouns.push_back("fish");
	nouns.push_back("C++");

	conjunctions.push_back("and");
	conjunctions.push_back("or");
	conjunctions.push_back("but");

	verbs.push_back("rules");
	verbs.push_back("fly");
	verbs.push_back("swim");
}