#pragma once

#include "Button.h"

class PlayButton : public Button {
public:
	PlayButton();

	virtual void activate(class Game* game);

	virtual void draw();
};

