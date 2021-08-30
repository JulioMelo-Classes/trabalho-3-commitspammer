#ifndef AI_H
#define AI_H
#include <vector>
#include "snake.h"
#include "level.h"

using namespace std;

class AI {
private:
	const Snake* snake;
	const Level* level;
	vector<Snake::Direction> solution;
	vector<pair<int,int>> track;

public:
	AI(Snake* snake, Level* level);

	bool has_solution() const;
	void random_direction();
	bool find_solution();
	bool find_solution(int y, int x);
	Snake::Direction next_move();
};

#endif

