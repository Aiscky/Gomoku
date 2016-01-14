#include <iostream>
#include <vector>

using namespace std;

#pragma once
class Goban
{
public:
	Goban();
	~Goban() {};

	void run(char);

private:
	vector<string> _board;
};

