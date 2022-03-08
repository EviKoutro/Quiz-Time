#pragma once
#include <string>

using namespace std;

class Question {
private:
	string text;
	string ans1;
	string ans2;
	int correct;

	int findAnswerNumber(float mx, float my);
public:

	Question(string text, string ans1, string ans2, int correct);

	void draw();

	bool correctClicked(float mx, float my);
	bool incorrectClicked(float mx, float my);
};

