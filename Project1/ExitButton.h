#pragma once

#include "Button.h"

class ExitButton : public Button {
public:
	ExitButton();

	virtual void draw();
	virtual void activate(class Game* game);	
};

