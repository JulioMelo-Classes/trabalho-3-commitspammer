#include <iostream>
#include <fstream>
#include "ai.h"
#include "randengine.h"

using namespace std;

AI::AI(Snake* snake, Level* level)
{
	this->snake = snake;
	this->level = level;
}

bool AI::has_solution() const
{
	if (this->solution.empty())
		return false;
	return true;
}

void AI::random_direction()
{
	RandEngine engine(Snake::Direction::NORTH, Snake::Direction::WEST);
	int i, j;
	vector<int> perm = engine.generate_permutation();
	for (auto& n : perm) {
		if (n == this->snake->get_opposite_facing())
			continue;
		i = this->snake->get_head_y();
		j = this->snake->get_head_x();
		switch (n) {
		case Snake::Direction::NORTH:
			i--; break;
		case Snake::Direction::SOUTH:
			i++; break;
		case Snake::Direction::EAST:
			j++; break;
		case Snake::Direction::WEST:
			j--; break;
		}
		//if (level->get_position(i, j) == ' ' || level->get_position(i, j) == '@') {
		if (level->get_position(i, j) != '#' && !snake->is_tail(i, j)) {
			this->solution.push_back((Snake::Direction)n);
			return;
		}
	}
	this->solution.push_back(this->snake->get_facing());
}

bool AI::find_solution()
{
	this->track.clear();
	this->solution.clear();
	int i = 0, j = 0;
	switch (this->snake->get_facing()) {
	case Snake::Direction::NORTH:
		i++; break;
	case Snake::Direction::SOUTH:
		i--; break;
	case Snake::Direction::EAST:
		j--; break;
	case Snake::Direction::WEST:
		j++; break;
	}
	this->track.push_back(make_pair(this->snake->get_head_y()+i, this->snake->get_head_x()+j));
	return find_solution(this->snake->get_head_y(), this->snake->get_head_x());
}

bool AI::find_solution(int y, int x)
{
	int l = this->level->get_lines();
	int c = this->level->get_columns();
	if (y < 0 || y >= l || x < 0 || x >= c)
		return false;
	if (this->level->get_position(y, x) == '@')
		return true;
	if (find(this->track.begin(), this->track.end(), make_pair(y, x)) != this->track.end())
		return false;
	if (level->get_position(y, x) != ' ')
		return false;

	this->track.push_back(make_pair(y, x));

	if (find_solution(y-1, x)) {
		this->solution.push_back(Snake::Direction::NORTH);
		return true;
	}
	if (find_solution(y+1, x)) {
		this->solution.push_back(Snake::Direction::SOUTH);
		return true;
	}
	if (find_solution(y, x+1)) {
		this->solution.push_back(Snake::Direction::EAST);
		return true;
	}
	if (find_solution(y, x-1)) {
		this->solution.push_back(Snake::Direction::WEST);
		return true;
	}

	this->track.pop_back();
	return false;
}

Snake::Direction AI::next_move()
{
	Snake::Direction move = this->solution.back();
	this->solution.pop_back();
	return move;
}
