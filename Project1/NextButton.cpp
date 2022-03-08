#include <iostream>

using namespace std;

#include "NextButton.h"

#include "defines.h"
#include "sgg/graphics.h"
#include "Game.h"

#define AB_WIDTH 4
#define AB_MIN_X (25 - AB_WIDTH / 2)
#define AB_MAX_X (25 + AB_WIDTH / 2)

#define AB_HEIGHT 3
#define AB_MIN_Y (1 - AB_HEIGHT / 2)
#define AB_MAX_Y (1 + AB_HEIGHT / 2)

NextButton::NextButton() : Button("", "Exit", AB_MIN_X, AB_MAX_X, AB_MIN_Y, AB_MAX_Y) {

}

void NextButton::activate(class Game* game) {
	cout << "Next question clicked! " << endl;
	game->next();
}

void NextButton::draw() {
	graphics::Brush br;
	graphics::drawText(25, 1, 1, "NEXT", br);
}

