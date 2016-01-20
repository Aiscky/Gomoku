#pragma once

#include "Grid.h"
#include <time.h>

class Grid;

class AI
{
private:
	Grid *_grid;
	int _alpha;
	int _beta;
	int _value;

public:
	AI(Grid *grid);
	~AI() {};
	void play();
	int Min(int);
	int Max(int);
	int Eval();
	void getSeries();
};

