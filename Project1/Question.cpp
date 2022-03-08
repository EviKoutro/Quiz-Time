#include "Question.h"

#include "sgg/graphics.h"
#include "defines.h"
#include <sstream>
#include <iostream>

using namespace std;

Question::Question(string text, string ans1, string ans2, int correct)
:text(text), ans1(ans1), ans2(ans2), correct(correct) {
	
}

void Question::draw() {
	graphics::Brush br;
	br.outline_width = 0;
	br.outline_opacity = 0;
	br.texture = ASSET_PATH + string("button.png");

	SETCOLOR(br.fill_color, 1, 1, 1);

	// Question
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 4, 20, 3, br);
	graphics::drawText(CANVAS_WIDTH / 5, CANVAS_HEIGHT / 4, 1, text, br);

	// Answer 1:
	graphics::drawText(CANVAS_WIDTH / 5, CANVAS_HEIGHT * 2.0f / 4, 1, ans1, br);

	// Answer 2:
	graphics::drawText(CANVAS_WIDTH / 2, CANVAS_HEIGHT * 2.0f/ 4, 1, ans2, br);

}

int Question::findAnswerNumber(float mx, float my) {
	float ex = 2;
	float ey = 2;
	float y = CANVAS_HEIGHT * 2.0f / 4;

	{
		float x = CANVAS_WIDTH / 5;
		
		if (mx >= x - ex && mx <= x + ex && my >= y - ey && my <= y + ey) {
			cout << "Clicked: 1 \n";
			return 1;
		}
	}
	
	{
		float x = CANVAS_WIDTH / 2;
		
		if (mx >= x - ex && mx <= x + ex && my >= y - ey && my <= y + ey) {
			cout << "Clicked: 2 \n";
			return 2;
		}		
	}

	cout << "Clicked: nowhere \n";

	return -1;
}

bool Question::correctClicked(float mx, float my) {
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	if (!ms.button_left_released) {
		return false;
	}

	int n = findAnswerNumber(mx, my);

	return n == correct;
}

bool Question::incorrectClicked(float mx, float my) {
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	if (!ms.button_left_released) {
		return false;
	}

	int n = findAnswerNumber(mx, my);

	return n != correct && n != -1;
	
}