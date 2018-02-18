#include "stdafx.h"

#include <iostream>
#include <sstream>

#include "QuestionsCategory.h"

using namespace std;

QuestionsCategory::QuestionsCategory( string categoryName) : nameOfCategory( categoryName )
{
	for (int i = 0; i < 50; i++)
	{

		ostringstream oss(ostringstream::out);
		oss << categoryName << " Question " << i;

		questions.push_back(oss.str());
	}
}

QuestionsCategory::QuestionsCategory(const char * categoryName)
{
	QuestionsCategory(string(categoryName));
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