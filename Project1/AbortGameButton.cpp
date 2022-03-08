#include <iostream>

using namespace std;

#include "AbortGameButton.h"

#include "defines.h"
#include "sgg/graphics.h"
#include "Game.h"

#define AB_WIDTH 4
#define AB_MIN_X (1 - AB_WIDTH / 2)
#define AB_MAX_X (1 + AB_WIDTH / 2)

#define AB_HEIGHT 3
#define AB_MIN_Y (1 - AB_HEIGHT / 2)
#define AB_MAX_Y (1 + AB_HEIGHT / 2)

AbortGameButton::AbortGameButton() : Button("", "Exit", AB_MIN_X, AB_MAX_X, AB_MIN_Y, AB_MAX_Y) {

}

void AbortGameButton::activate(class Game* game) {
	cout << "Abort game clicked! " << endl;
	game->abortGame();
}

void AbortGameButton::draw() {
	graphics::Brush br;		
	graphics::drawText(1, 1, 1, "EXIT", br);
}

