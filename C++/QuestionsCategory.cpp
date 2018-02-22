#include <iostream>
#include <sstream>

#include "QuestionsCategory.h"



QuestionsCategory::QuestionsCategory(const char * categoryName)
{
	std::ostringstream oss(std::ostringstream::out);
	for (int i = 0; i < 50; i++)
	{
		oss << categoryName << " Question " << i;

		questions.push_back(oss.str());
		oss.str("");
	}
}

QuestionsCategory::~QuestionsCategory()
{
}

std::string QuestionsCategory::PopNextQuestion()
{
	bool isEmpty = questions.empty();
	std::string result = isEmpty ? "There is no more question in this category!" : questions.front();
	if(!isEmpty)
		questions.pop_front();
	return result;
}

std::string QuestionsCategory::GetName()
{
	return nameOfCategory;
}
