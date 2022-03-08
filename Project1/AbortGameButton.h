#pragma once

#include "Button.h"

class AbortGameButton : public Button {
public:
	AbortGameButton();

	virtual void draw();
	virtual void activate(class Game* game);
};

