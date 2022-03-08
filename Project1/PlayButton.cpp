#include <iostream>

#include "PlayButton.h"
#include "defines.h"
#include "sgg/graphics.h"
#include "Game.h"

using namespace std;

#define PL_WIDTH  (CANVAS_WIDTH / 5)
#define PL_MIN_X (CANVAS_WIDTH / 2 - PL_WIDTH / 2)
#define PL_MAX_X (CANVAS_WIDTH / 2 + PL_WIDTH / 2)
#define PL_HEIGHT  (CANVAS_HEIGHT / 5)
#define PL_MIN_Y (CANVAS_HEIGHT / 2 - PL_WIDTH / 2)
#define PL_MAX_Y (CANVAS_HEIGHT / 2 + PL_WIDTH / 2)

PlayButton::PlayButton() : Button("button.png", "Play", PL_MIN_X, PL_MAX_X, PL_MIN_Y, PL_MAX_Y) {

}

void PlayButton::activate(class Game* game) {
	cout << "Play clicked! " << endl;
	game->init();
}

void PlayButton::draw() {
	graphics::Brush br;

	br.outline_opacity = 0;
	br.texture = ASSET_PATH + texture;

	SETCOLOR(br.fill_color, 1, 1, 1);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, PL_WIDTH, PL_HEIGHT, br);
	graphics::drawText(CANVAS_WIDTH / 2 - 2, CANVAS_HEIGHT / 2 + 0.5, 2, "Play", br);
}

