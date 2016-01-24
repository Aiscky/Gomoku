#pragma once

#include "Grid.h"
#include "Arbiter.h"
#include <time.h>

class Grid;

class AI
{
private:
	Grid *_grid;
	int _alpha;
	int _beta;
	Arbiter _arbiter;

public:
	AI(Grid *grid);
	~AI() {};
	void play(char &X, char &Y);
	int Min(int);
	int Max(int);
	int Eval();
};

