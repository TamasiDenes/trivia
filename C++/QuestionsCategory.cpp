#include "stdafx.h"

#include <iostream>
#include <sstream>

#include "QuestionsCategory.h"

using namespace std;



QuestionsCategory::QuestionsCategory(const char * categoryName)
{
	ostringstream oss(ostringstream::out);
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

string QuestionsCategory::PopNextQuestion()
{
	bool isEmpty = questions.empty();
	string result = isEmpty ? "There is no more question in this category!" : questions.front();
	if(!isEmpty)
		questions.pop_front();
	return result;
}

string QuestionsCategory::GetName()
{
	return nameOfCategory;
}
