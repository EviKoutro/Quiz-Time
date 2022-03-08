#include "WinnerBanner.h"

#include "sgg/graphics.h"
#include "defines.h"

#include <sstream>

using namespace std;

WinnerBanner::WinnerBanner() :texture("winner.png"), text("WINNER: ") {

} 

void WinnerBanner::setWinner(string who) {
	this->winner = who;
}

void WinnerBanner::draw() {
	graphics::Brush br;

	br.outline_opacity = 0;
	br.texture = ASSET_PATH + texture;

	SETCOLOR(br.fill_color, 1, 1, 1);

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 13, 10, br);	


	stringstream ss;

	ss << text << winner;

	string label = ss.str();

	graphics::drawText(CANVAS_WIDTH / 2 - 4, CANVAS_HEIGHT / 2 + 0.5, 1, label, br);
}