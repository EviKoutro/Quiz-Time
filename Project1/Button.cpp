#include "Button.h"
#include "defines.h"
#include "sgg/graphics.h"

Button::Button(string texture, string text, float min_x, float max_x, float min_y, float max_y) 
	:texture(texture), text(text), min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y) {

}

bool Button::clicked(float mx, float my) {
	graphics::MouseState ms;
	graphics::getMouseState(ms);


	bool clicked =ms.button_left_released && mx >= min_x && mx <= max_x && my >= min_y && my <= max_y;

	if (clicked) {
		graphics::playSound(ASSET_PATH + string("click.mp3"), 1, false);
	}

	return clicked;
}
