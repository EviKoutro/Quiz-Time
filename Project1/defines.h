#pragma once

#include <cmath>

#define CANVAS_WIDTH 28.0f
#define CANVAS_HEIGHT 16.0f
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define CANVAS_WIDTH 30.0f
#define PLAYER_SIZE 2.0f
#define PLAYER_MOTION_RANGE 6.0f
#define PLAYER_ATTACK_RANGE 3.0f

#define SETCOLOR(c,r,g,b) { c[0] =r; c[1] = g; c[2] = b;}
#define RAND0TO1() (rand()/(float)RAND_MAX)

#define ASSET_PATH ".\\assets\\"

inline float distance(float x1, float y1, float x2, float y2) {
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}