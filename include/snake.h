#ifndef SNAKE_H
#define SNAKE_H
#include <vector>

using namespace std;

class Snake {
public:
	enum Direction {
		NORTH,
		SOUTH,
		EAST,
		WEST
	};

private:
	Direction facing;
	pair<int,int> spawn;
	pair<int,int> head;
	vector<pair<int,int>> tail;
	int lifes;
	int food_eaten;

public:
	Snake(vector<string> layout);

	Direction get_facing() const;
	Direction get_opposite_facing() const;
	int get_head_y() const;
	int get_head_x() const;
	int get_lifes() const;
	int get_food_eaten() const;
	char get_head_icon() const;
	bool is_head(int y, int x) const;
	bool is_tail(int y, int x) const;
	void move_tail(bool eat);
	void move(Direction direction, string mode, bool eat);
	void respawn();
};

#endif

