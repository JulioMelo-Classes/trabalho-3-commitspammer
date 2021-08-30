#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include "validator.h"

using namespace std;

bool Validator::try_open_file(string name)
{
	ifstream level_file(name);
	if (!level_file.is_open())
		return false;
	level_file.close();
	return true;
}

bool Validator::parse_mode(string mode)
{
	if (mode != "snake" && mode != "pacman")
		return false;
	return true;
}

bool Validator::parse_level_file(string name)
{
	//TODO
	return false;
}

void Validator::separate_levels_from_level_file(string name)
{
	ifstream level_file(name);
	if (!try_open_file(name))
		return;
	vector<string> layout;
	string line;
	while (getline(level_file, line)) {
		if (line == "END") {
			levels.push_back(layout);
			layout.clear();
			continue;
		}
		layout.push_back(line);
	}
	level_file.close();
}

bool Validator::get_next_level(vector<string>* buffer)
{
	if (levels.empty())
		return false;
	buffer->clear();
	for (auto& s : levels.front())
		buffer->push_back(s);
	levels.erase(levels.begin());
	return true;
}
