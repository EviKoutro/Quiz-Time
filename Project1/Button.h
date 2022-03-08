#pragma once

#include <string>

using namespace std;

class Button {
protected:
	string texture;
	string text;
	float min_x, max_x, min_y, max_y;
public:
	Button(string texture, string text, float min_x, float max_x, float min_y, float max_y);
	virtual void draw() = 0;

	virtual void activate(class Game * game) = 0;
	virtual bool clicked(float mx, float my);
};

