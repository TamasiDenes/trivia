#pragma once

#include "QuestionsCategory.h"

#include <string>
#include <vector>


class QuestionCategoryContainer : public std::vector<QuestionsCategory>
{
public:
	QuestionCategoryContainer() {};
	~QuestionCategoryContainer() {};

	std::string GetCurrentQuestionCategoryName( int index )
	{
		return (*this)[index].GetName();
	}

	std::string PopNextQuestion(int index )
	{
		return (*this)[index].PopNextQuestion();
	}
};
