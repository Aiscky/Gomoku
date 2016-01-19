#include "AI.h"

AI::AI(Grid *grid)
{
	_grid = grid;
	srand(time(NULL));
}

void AI::play()
{
//	eval();
//	minmax();
	static int x = 10;
	int y = 9;
	_grid->addPawn(x, y, Grid::BLACK);
	x++;
}

void eval()
{
}

void minmax()
{
}