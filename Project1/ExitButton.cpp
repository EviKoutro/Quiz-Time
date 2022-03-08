#include <iostream>

using namespace std;

#include "ExitButton.h"

#include "defines.h"
#include "sgg/graphics.h"

#define EX_WIDTH  (CANVAS_WIDTH / 6)
#define EX_MIN_X (6 - EX_WIDTH / 2)
#define EX_MAX_X (6 + EX_WIDTH / 2)

#define EX_HEIGHT  (CANVAS_HEIGHT / 8)
#define EX_MIN_Y (13 - EX_HEIGHT / 2)
#define EX_MAX_Y (13 + EX_HEIGHT / 2)

ExitButton::ExitButton() : Button("button.png", "Exit", EX_MIN_X , EX_MAX_X, EX_MIN_Y, EX_MAX_Y) {

}

void ExitButton::activate(class Game* game) {
	cout << "Exit clicked! " << endl;
	graphics::stopMessageLoop();
}

void ExitButton::draw() {
	graphics::Brush br;
	br.outline_opacity = 0;	
	br.texture = ASSET_PATH + texture;	
	graphics::drawRect(6, 13, EX_WIDTH, EX_HEIGHT, br);
	graphics::drawText(4.5, 13.5, 1.5, "Exit", br);
}

