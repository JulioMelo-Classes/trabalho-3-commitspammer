#include <iostream>
#include <fstream>
#include <string>
#include "game.h"
#include "validator.h"

using namespace std;

int error(string description)
{
	cout << "ERROR: " << description << endl;
	return -1;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
		return error("Missing file");

	Validator validator;

	string file(argv[1]);
	if (!validator.try_open_file(file))
		return error("Invalid file path");

	string mode;
	if (argc > 2) {
		string tmp(argv[2]);
		if (!validator.parse_mode(tmp))
			return error("Invalid game mode");
		mode = tmp;
	} else {
		mode = "snake";
	}

	/*
	ifstream level_file(file);
	if (!level_file.is_open())
		return error("Couldn't open file");
	vector<string> layout;
	string line;
	while (getline(level_file, line))
		layout.push_back(line);
	level_file.close();
	*/

	validator.separate_levels_from_level_file(file);
	vector<string> layout;
	while (validator.get_next_level(&layout)) {
		Snake* snake = new Snake(layout);
		Level* level = new Level(layout, snake);
		AI* ai = new AI(snake, level);
		Game* game = new Game(mode, snake, level, ai);

		game->loop();

		delete snake;
		delete level;
		delete ai;
		delete game;
	}
	//validator.get_next_level(&layout);

	//for (auto& l : layout)
		//cout << l << endl;

	/*
	*/
	return 0;
}
