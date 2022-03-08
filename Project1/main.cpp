#include <iostream>
#include <string>

#include "sgg/graphics.h"
#include "defines.h"
#include "Game.h"

using namespace std;

void draw() {
	Game* game = Game::getInstance();
	game->draw();
}
void update(float ms) {
	Game* game = Game::getInstance();
	game->update();
}

int main(int argc, char* argv[]) {
	graphics::createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Quiz Time!!!");

	Game* game = Game::getInstance();
	
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop();
	graphics::destroyWindow();

	Game::releaseInstance();

	return 0;
}