#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Validator {
	private:
		vector<vector<string>> levels;

	public:
		bool try_open_file(string name);
		bool parse_mode(string mode);
		bool parse_level_file(string name);
		void separate_levels_from_level_file(string name);
		bool get_next_level(vector<string>* buffer);
};

#endif

