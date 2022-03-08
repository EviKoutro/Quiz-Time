#pragma once

#include <string>

using namespace std;

class WinnerBanner {
protected:
	string texture;
	string text;
	string winner;
public:
	WinnerBanner();
	void draw();

	void setWinner(string who);
};

