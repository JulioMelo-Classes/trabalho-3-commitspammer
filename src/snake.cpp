#include <iostream>
#include "snake.h"

using namespace std;

Snake::Snake(vector<string> layout)
{
	this->facing = NORTH;
	this->lifes = 5;
	this->food_eaten = 0;

	layout.erase(layout.begin());
	for (unsigned long int i = 0; i < layout.size(); i++) {
		for (unsigned long int j = 0; j < layout[i].size(); j++) {
			if (layout[i][j] == '*') {
				this->head = make_pair(i, j);
				this->spawn = make_pair(i, j);
			}
		}
	}
}

Snake::Direction Snake::get_facing() const
{
	return this->facing;
}

Snake::Direction Snake::get_opposite_facing() const
{
	switch (this->facing) {
	case NORTH:
		return SOUTH;
	case SOUTH:
		return NORTH;
	case EAST:
		return WEST;
	case WEST:
		return EAST;
	}
	return NORTH;
}

int Snake::get_head_y() const
{
	return this->head.first;
}

int Snake::get_head_x() const
{
	return this->head.second;
}

int Snake::get_lifes() const
{
	return this->lifes;
}

int Snake::get_food_eaten() const
{
	return this->food_eaten;
}

char Snake::get_head_icon() const
{
	switch (this->facing) {
	case NORTH:
		return '^';
	case SOUTH:
		return 'v';
	case EAST:
		return '>';
	case WEST:
		return '<';
	}
	return 'x';
}

bool Snake::is_head(int y, int x) const
{
	if (this->head.first == y && this->head.second == x)
		return true;
	return false;
}

bool Snake::is_tail(int y, int x) const
{
	for (auto& t : this->tail){
		if (t.first == y && t.second == x)
			return true;
	}
	return false;
}

void Snake::move_tail(bool eat)
{
	this->tail.insert(this->tail.begin(), this->head);
	if (!eat)
		this->tail.pop_back();
}

void Snake::move(Snake::Direction direction, string mode, bool eat)
{
	if (mode == "snake")
		move_tail(eat);

	switch (direction) {
	case NORTH:
		if (this->facing == SOUTH)
			return;
		this->head.first--;
		this->facing = NORTH;
		break;
	case SOUTH:
		if (this->facing == NORTH)
			return;
		this->head.first++;
		this->facing = SOUTH;
		break;
	case WEST:
		if (this->facing == EAST)
			return;
		this->head.second--;
		this->facing = WEST;
		break;
	case EAST:
		if (this->facing == WEST)
			return;
		this->head.second++;
		this->facing = EAST;
		break;
	}
	if (eat)
		this->food_eaten++;
}

void Snake::respawn()
{
	this->lifes--;
	this->facing = NORTH;
	this->head.first = this->spawn.first;
	this->head.second = this->spawn.second;
	this->tail.clear();
}
