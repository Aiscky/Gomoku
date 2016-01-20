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
			if (_grid->getCell(x, y) == 0 && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
			{
				_grid->addPawn(x, y, Grid::BLACK);
				int tmp = Min(depth - 1);
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
			if (_grid->getCell(x, y) == 0 && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
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
			if (_grid->getCell(x, y) == 0 && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
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
		int black = 0;
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				white++;
				black = 0;
				if (white == 5)
					_value -= 1000;
				else if (white == 4)
				{
					if (_grid->getCell(x - 5, y) == 0 && _grid->getCell(x + 1, y) == 0)
						_value -= 400;
					else if (_grid->getCell(x - 5, y) == 0 || _grid->getCell(x + 1, y) == 0)
						_value -= 100;
				}
				else if (white == 3)
				{
					if (_grid->getCell(x - 4, y) == 0 && _grid->getCell(x + 1, y) == 0)
						_value -= 50;
				}
			}
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				white = 0;
				black++;
				if (black == 5)
					_value += 1000;
				else if (black == 4)
				{
					if (_grid->getCell(x - 5, y) == 0 && _grid->getCell(x + 1, y) == 0)
						_value += 400;
					else if (_grid->getCell(x - 5, y) == 0 || _grid->getCell(x + 1, y) == 0)
						_value += 100;
				}
				else if (black == 3)
				{
					if (_grid->getCell(x - 4, y) == 0 && _grid->getCell(x + 1, y) == 0)
						_value += 50;
					else if (_grid->getCell(x - 4, y) == 0 && _grid->getCell(x - 5, y) == 0
						|| _grid->getCell(x + 1, y) == 0 && _grid->getCell(x + 2, y) == 0)
						_value += 10;
				}
				else if (black == 2 && _grid->getCell(x + 1, y) == 0 && _grid->getCell(x + 2, y) == 0 && _grid->getCell(x + 3, y) == 0)
				{
					_value += 1;
				}
			}
			else
			{
				white = 0;
				black = 0;
			}
		}
	}
	// En Colonne
	for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
	{
		int white = 0;
		int black = 0;
		for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
		{
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				black = 0;
				white++;
				if (white == 5)
					_value -= 1000;
				else if (white == 4)
				{
					if (_grid->getCell(x, y - 5) == 0 && _grid->getCell(x, y + 1) == 0)
						_value -= 400;
					else if (_grid->getCell(x, y - 5) == 0 || _grid->getCell(x, y + 1) == 0)
						_value -= 100;
				}
				else if (white == 3)
				{
					if (_grid->getCell(x, y - 4) == 0 && _grid->getCell(x, y + 1) == 0)
						_value -= 50;
				}
			}
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				white = 0;
				black++;
				if (black == 5)
					_value += 1000;
				else if (black == 4)
				{
					if (_grid->getCell(x, y - 5) == 0 && _grid->getCell(x, y + 1) == 0)
						_value += 400;
					else if (_grid->getCell(x, y - 5) == 0 || _grid->getCell(x, y + 1) == 0)
						_value += 100;
				}
				else if (black == 3)
				{
					if (_grid->getCell(x, y - 4) == 0 && _grid->getCell(x, y + 1) == 0)
						_value += 50;
					else if (_grid->getCell(x, y - 4) == 0 && _grid->getCell(x, y - 5) == 0 
							|| _grid->getCell(x, y + 1) == 0 && _grid->getCell(x, y + 2) == 0)
						_value += 10;
				}
				else if (black == 2 && _grid->getCell(x, y + 1) == 0 && _grid->getCell(x, y + 2) == 0 && _grid->getCell(x, y + 3) == 0)
				{
					_value += 1;
				}
			}
			else
			{
				white = 0;
				black = 0;
			}
		}
	}
}