#pragma once

#include "Grid.h"

class Grid;

class AI
{
private:
	Grid *_grid;

public:
	AI(Grid *grid);
	~AI() {};
	void play();
};

