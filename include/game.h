#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include <string>
#include "level.h"
#include "snake.h"
#include "ai.h"

using namespace std;

class Game {
public:
	enum GameStates {
	    RUNNING,
	    GAME_OVER,
	    WAITING_USER
	};

private:
	AI* ai;
	Snake* snake;
	Level* level;
	vector<string> maze;
	string mode;
	int frame_count;
	string user_input;
	GameStates state;

public:
	Game(string mode, Snake* snake, Level* level, AI* ai);

	void loop();

private:
	void get_input();
	void update();
	void render();
	void game_over();
};

#endif

