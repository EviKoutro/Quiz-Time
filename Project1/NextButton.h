#pragma once

#include "Button.h"

class NextButton : public Button {
public:
	NextButton();

	virtual void draw();
	virtual void activate(class Game* game);
};

