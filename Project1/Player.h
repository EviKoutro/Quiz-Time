#pragma once

#include <string>

using namespace std;

class Player {
private:
	string who;
	float m_pos[2];	
	bool m_active;	
public:
	int score;

	Player(string who, float m_pos[2]);

	string getWho();

	void init();
	void draw();
	void update();

	void setActive(bool h) { m_active = h; };
	
};

