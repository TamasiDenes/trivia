#pragma once

#include "QuestionsCategory.h"

#include <string>
#include <vector>


class QuestionCategoryContainer : public vector<QuestionsCategory>
{
public:
	QuestionCategoryContainer();
	~QuestionCategoryContainer();

	string GetCurrentQuestionCategoryName( int index )
	{
		return (*this)[index].GetName();
	}

	string PopNextQuestion(int index )
	{
		return (*this)[index].PopNextQuestion();
	}
};

