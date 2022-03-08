#include <iostream>
#include <string>

#include "Game.h"
#include "sgg/graphics.h"
#include "defines.h"

using namespace std;

Game* Game::m_instance = nullptr;

Game::Game() : current_question(0), current_player(0) {
	cout << "Game constructing ..." << endl;

	graphics::preloadBitmaps(ASSET_PATH);
	graphics::setFont(ASSET_PATH + string("font.ttf"));

	float m_posA[] = { 4.5 , 13.5 };
	float m_posB[] = { 18, 13.5 };

	players.push_back(new Player("A", m_posA));
	players.push_back(new Player("B", m_posB));

	cout << "Game constructed ... " << endl;

	graphics::playSound(ASSET_PATH + string("background.mp3"), 0.5, true);

	questions.push_back(new Question("How many prefectures does Greece have?", "51", "54", 1));
	questions.push_back(new Question("How many districs does Greece have?", "13", "14", 1));
	questions.push_back(new Question("How many member states does the EU have?", "25", "27", 2));
	questions.push_back(new Question("What is the capital of Switzerland?", "Berne", "Zurich", 1));
	questions.push_back(new Question("What is the largest river in Europe?", "Rhine", "Volga", 2));
	questions.push_back(new Question("What is the second largest river in Europe?", "Rhine", "Danube", 2));
	questions.push_back(new Question("Which country is known for the fjords?", "Sweden", "Norway", 2));
	questions.push_back(new Question("Which color does not belong to the flag of Italy?", "green", "blue", 2));
	questions.push_back(new Question("When was the Eiffel Tower built?", "1889", "1920", 1));
	questions.push_back(new Question("In which country is the city of Guadalajara located?", "Chile", "Mexico", 2));
}

Game::~Game() {
	cout << "Game destructing ..." << endl;

	for (unsigned i = 0; i < questions.size(); i++) {
		delete questions[i];
	}

	for (unsigned i = 0; i < players.size(); i++) {
		delete players[i];
	}

	cout << "Game destructed ..." << endl;
}

void Game::drawBackground() {
	graphics::Brush br;

	br.outline_opacity = 0;
	br.texture = ASSET_PATH + string("background.png");

	SETCOLOR(br.fill_color, 1, 1, 1);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	graphics::drawText(CANVAS_WIDTH / 2 - 3, CANVAS_HEIGHT / 10, 1.2, "Quiz Time", br);
}

void Game::init() {
	for (auto p : players) {
		p->init();
	}	

	current_player = 0;
	current_question = 0;

	m_state = STATE_PLAYING;
}

void Game::abortGame() {
	m_state = STATE_MENU;
}

void Game::next() {
	current_question++;

	current_player = 0;
	players[0]->setActive(true);
	players[1]->setActive(false);

	cout << "Question chagned to " << current_question << endl;
}

Player* Game::findWinner() {
	if (players[0]->score == players[1]->score) {
		return nullptr;
	} else if (players[0]->score > players[1]->score) {
		return players[0];
	} else {
		return players[1];
	}
}

void Game::draw() {
	drawBackground();

	if (m_state == STATE_MENU) {
		playButton.draw();
		exitButton.draw();
	}

	if (m_state == STATE_PLAYING) {
		for (auto p : players) {
			p->draw();
		}
		abortGameButton.draw();
		nextButton.draw();
		if (current_question < questions.size()) {
			questions[current_question]->draw();
		}
	}

	if (m_state == STATE_GAMEOVER) {
		winner.draw();
		abortGameButton.draw();
	}
}

void Game::update() {
	graphics::MouseState ms;
	graphics::getMouseState(ms);

	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	if (m_state == STATE_MENU) {
		if (playButton.clicked(mx, my)) {
			playButton.activate(this);
		}

		if (exitButton.clicked(mx, my)) {
			exitButton.activate(this);
		}
	} else if (m_state == STATE_PLAYING) {
		if (abortGameButton.clicked(mx, my)) {
			abortGameButton.activate(this);
		} else if (nextButton.clicked(mx, my)) {
			nextButton.activate(this);
		}

		if (current_question >= questions.size()) {
			m_state = STATE_GAMEOVER;

			Player* p = findWinner();
			if (p != nullptr) {
				winner.setWinner(p->getWho());
			} else {
				winner.setWinner("BOTH!");
			}
			graphics::playMusic(ASSET_PATH + string("clapping.mp3"), 0.7, false);
		} else {
			Question* current = questions[current_question];

			bool correct = current->correctClicked(mx, my);
			bool incorrect = current->incorrectClicked(mx, my);

			if (correct || incorrect) { // choice taken				
				if (correct) {
					cout << "correct for " << current_player << endl;
					roundresults[current_player] = true;					
				} else {
					cout << "wrong for " << current_player << endl;
					roundresults[current_player] = false;
				}
				if (current_player == 0) {
					current_player = 1;
				} else {
					// start new round
					current_player = 0;

					if (roundresults[0] == true) {
						players[0]->score++;
					}
					if (roundresults[1] == true) {
						players[1]->score++;
					}
					next();
				}


				
			}

			players[0]->setActive(current_player == 0);
			players[1]->setActive(current_player == 1);
		}
	} else if (m_state == STATE_GAMEOVER) {
		if (abortGameButton.clicked(mx, my)) {
			abortGameButton.activate(this);
		}
	}
}

Game* Game::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Game();			 
	}
	return m_instance;
}

void Game::releaseInstance() {
	if (m_instance != nullptr) {
		delete m_instance;
	}

	m_instance = nullptr;		 
}