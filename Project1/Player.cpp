#include <string>
#include <iostream>
#include <cmath>
#include <sstream>

#include "Player.h"
#include "defines.h"

#include "sgg/graphics.h"

using namespace std;

Player::Player(string who, float m_pos[2]) : who(who), m_active(false), score(0) {
	this->m_pos[0] = m_pos[0];
	this->m_pos[1] = m_pos[1];

	init();
}

string Player::getWho() {
	return who;
}

void Player::init() {
	if (who == "A") {
		m_active = true;
	} else {
		m_active = false;
	}
	score = 0;	
}

void Player::draw()
{
	stringstream ss;

	float t = graphics::getGlobalTime()*0.001;

	ss << "PLAYER" << who << ":" << score;

	string label = ss.str();

	graphics::Brush br;
	
	if (m_active) {
		float s = 1 + 0.3*fabs(sin(t));
		graphics::setScale(s,s);
	}

	graphics::drawText(m_pos[0], m_pos[1], 1, label, br);

	if (m_active) {
		graphics::resetPose();
	}

}

void Player::update() {
	
}
