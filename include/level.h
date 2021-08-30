#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include <string>
#include "snake.h"

using namespace std;

class Level {
private:
	const Snake* snake;
	vector<string> map;
	pair<int,int> spawn;
	int lines;
	int columns;
	int food_count;

public:
	Level(vector<string> layout, Snake* snake);

	int get_spawn_y() const;
	int get_spawn_x() const;
	int get_lines() const;
	int get_columns() const;
	int get_food_count() const;
	char get_position(int y, int x) const;
	string generate_map() const;
	void spawn_food();
	void set_parameters(string line);
	bool snake_died() const;
	bool snake_ate() const;
};

#endif

