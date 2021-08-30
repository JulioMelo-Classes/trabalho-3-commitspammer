#ifndef RANDENGINE_H
#define RANDENGINE_H
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class RandEngine {
public:
	RandEngine(int lowest, int highest);

	int generate_int();
	vector<int> generate_permutation();

private:
	int lowest;
	int highest;
	std::random_device rd;
	std::mt19937 mt;
	std::uniform_int_distribution<int> dist;
};

#endif

