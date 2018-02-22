#pragma once

#include <string>
#include <list>

class QuestionsCategory
{
	std::string nameOfCategory;

	std::list<std::string> questions;
public:
	QuestionsCategory(char const * categoryName);
	~QuestionsCategory();

	std::string PopNextQuestion();
	std::string GetName();
};

