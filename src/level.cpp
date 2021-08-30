#include <vector>
#include <fstream>
#include <sstream>
#include "level.h"
#include "randengine.h"

using namespace std;

Level::Level(vector<string> layout, Snake* snake)
{
	this->snake = snake;

	stringstream ss;
	ss << layout[0];
	ss >> this->lines >> this->columns >> this->food_count;
	layout.erase(layout.begin());
	for (auto& l : layout)
		this->map.push_back(l);

	for (int i = 0; i < this->lines; ++i) {
		for (int j = 0; j < this->columns; ++j) {
			if (this->map[i][j] == '*') {
				this->spawn = make_pair(i, j);
				this->map[i][j] = ' ';
			}
		}
	}
	spawn_food();
}

int Level::get_spawn_y() const
{
	return this->spawn.first;
}

int Level::get_spawn_x() const
{
	return this->spawn.second;
}

int Level::get_lines() const
{
	return this->lines;
}

int Level::get_columns() const
{
	return this->columns;
}

int Level::get_food_count() const
{
	return this->food_count;
}

char Level::get_position(int i, int j) const
{
	return map[i][j];
}

string Level::generate_map() const
{
	stringstream ss;
	for (int i = 0; i < this->lines; i++) {
		for (int j = 0; j < this->columns; j++) {
			if (this->snake->is_head(i, j))
				ss << this->snake->get_head_icon();
			else if (this->snake->is_tail(i, j))
				ss << 'o';
			else if (this->map[i][j] == '*')
				ss << ' ';
			else
				ss << this->map[i][j];
		}
		ss << endl;
	}
	return ss.str();
}

void Level::spawn_food()
{
	for (int i = 0; i < this->lines; ++i) {
		for (int j = 0; j < this->columns; ++j) {
			if (this->map[i][j] == '@')
				this->map[i][j] = ' ';
		}
	}

	RandEngine line(0, (this->lines-1));
	RandEngine column(0, (this->columns-1));
	int l, c;
	do {
		l = line.generate_int();
		c = column.generate_int();
	} while (this->map[l][c] != ' ');
	this->map[l][c] = '@';
}

bool Level::snake_died() const
{
	int y = this->snake->get_head_y();
	int x = this->snake->get_head_x();
	if (map[y][x] == '#' || map[y][x] == '.' || this->snake->is_tail(y, x))
		return true;
	return false;
}

bool Level::snake_ate() const
{
	int y = this->snake->get_head_y();
	int x = this->snake->get_head_x();
	if (this->map[y][x] == '@')
		return true;
	return false;
}
