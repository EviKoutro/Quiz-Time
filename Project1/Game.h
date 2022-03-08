#pragma once

#include <vector>
#include <iterator>

#include "Player.h"
#include "PlayButton.h"
#include "ExitButton.h"
#include "AbortGameButton.h"
#include "NextButton.h"
#include "WinnerBanner.h"
#include "Question.h"

using namespace std;

class Game {
private:
	PlayButton playButton;
	ExitButton exitButton;
	AbortGameButton abortGameButton;
	NextButton nextButton;
	WinnerBanner winner;
	vector<Question*> questions;	
	vector<Player*> players;
	bool roundresults[2];
public:
	enum game_state_t { STATE_MENU, STATE_PLAYING, STATE_GAMEOVER };
protected:
	static Game* m_instance;	
	game_state_t m_state;

	int current_question;
	int current_player;

	Game();
	~Game();

	void drawBackground();	
	Player* findWinner();
public:
	void init();
	void draw();
	void update();

	void abortGame();	
	void next();


	//void cmdVote


	static void releaseInstance();
	static Game* getInstance();
};

