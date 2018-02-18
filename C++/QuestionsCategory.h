#pragma once

#include <string>
#include <list>

using namespace std;
class QuestionsCategory
{
	string nameOfCategory;

	list<string> questions;
public:
	QuestionsCategory( string categoryName);
	QuestionsCategory(char const * categoryName);
	~QuestionsCategory();

	string PopNextQuestion();
	string GetName();
};

