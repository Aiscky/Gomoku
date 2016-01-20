#include "AI.h"

AI::AI(Grid *grid)
{
	_grid = grid;
	srand(time(NULL));
}

void AI::play()
{
	int depth = 2;
	char bestX = 0;
	char bestY = 0;
	int max = -1000;

	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == 0)
			{
				_grid->addPawn(x, y, Grid::BLACK);
				int tmp = Min(depth - 1);
				// std::cout << "Max = " << (int)y << ":" << (int)x << " -  " << tmp << std::endl;
				if (tmp > max)
				{
					max = tmp;
					bestX = x;
					bestY = y;
				}
				_grid->deletePawn(x, y);
			}
		}
	}
	std::cout << "Value = " << _value << std::endl;
	_grid->addPawn(bestX, bestY, Grid::BLACK);
}

int AI::Min(int depth)
{
	int min = 1000;
	if (depth == 0)
		return (Eval());
	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == 0)
			{
				_grid->addPawn(x, y, Grid::WHITE);
				int tmp = Max(depth - 1);
				if (tmp < min)
					min = tmp;
				_grid->deletePawn(x, y);
			}
		}
	}
	return (min);
}

int AI::Max(int depth)
{
	int max = -1000;
	if (depth == 0)
		return (Eval());
	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == 0)
			{
				_grid->addPawn(x, y, Grid::BLACK);
				int tmp = Min(depth - 1);
				if (tmp > max)
					max = tmp;
				_grid->deletePawn(x, y);
			}
		}
	}
	return (max);
}

/* EVALUATION AI */

int AI::Eval()
{
	_value = 0;
	getSeries();
	return (_value);
}

void AI::getSeries()
{
	//En ligne;
	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		int white = 0;
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				white++;
				if (white == 3)
					_value -= 50;
			}
			else
				white = 0;
		}
	}
}

/*
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				black++;
				white = 0;
				if (black == 3)
					_value += 50;
			}
			else
			{
				black = 0;
				white = 0;
			}
		}	
	}
	//En Colonne;
	for (char x = _grid->getTop(); x <= _grid->getBottom(); x++)
	{
		black = 0;
		white = 0;
		for (char y = _grid->getLeft(); y <= _grid->getRight(); y++)
		{
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				white++;
				black = 0;
				if (white == 3)
					_value += 50;
				if (white == 4)
					_value += 100;
			}
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				black++;
				white = 0;
				if (black == 3)
					_value += 50;
			}
			else
			{
				black = 0;
				white = 0;
			}
		}
	}
}
*/
