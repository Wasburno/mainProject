#include "Answer.h"
#include<iostream>


//constructor definition
Answer::Answer()
{
	paragraph = "";
	firstAnswer = "";
	secondAnswer = "";
}

//Destructor
Answer::~Answer()
{
}


//Setters definitios
void Answer::setParagraph(string _paragraph)
{
	paragraph = _paragraph;
}

void Answer::setFirstAnswer(string _firstAnswer)
{
	firstAnswer = _firstAnswer;
}

void Answer::setSecondAnswer(string _secondAnswer)
{
	secondAnswer = _secondAnswer;
}


//Getters definitions
string Answer::getParagraph()
{
	return paragraph;
}

string Answer::getFirstAnswer()
{
	return firstAnswer;
}

string Answer::getSecondAnswer()
{
	return secondAnswer;
}

