#pragma once
#include<string>
#include<fstream>

using std::string;

class Answer
{
private:
	string paragraph;
	string firstAnswer;
	string secondAnswer;

public:
	//constructor and destructor
	Answer();
	~Answer();

	//setters
	void setParagraph(string);
	void setFirstAnswer(string);
	void setSecondAnswer(string);

	//getters
	string getParagraph();
	string getFirstAnswer();
	string getSecondAnswer();

};
