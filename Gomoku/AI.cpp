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
			if (_grid->getCell(x, y) == Grid::NONE && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
			{
				_grid->addPawn(x, y, Grid::BLACK);
				int tmp = Min(depth - 1);
				std::cout << "TMP = " << tmp << std::endl;
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
	std::cout << "Max = " << max << std::endl;
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
			if (_grid->getCell(x, y) == Grid::NONE && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
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
			if (_grid->getCell(x, y) == Grid::NONE && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
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
	int value = 0;
	int white = 0;
	int black = 0;

	// EN LIGNE

	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		white = 0;
		black = 0;
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			// ALIGNEMENT DE WHITE
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				white++;
				black = 0;
				if (white == 5)
					value -= 1000;
				else if (white == 4)
				{
					if (_grid->getCell(x - 4, y) == Grid::NONE && _grid->getCell(x + 1, y) == Grid::NONE)
						value -= 400;
					else if (_grid->getCell(x - 4, y) == Grid::NONE || _grid->getCell(x + 1, y) == Grid::NONE)
						value -= 100;
				}
				else if (white == 3)
				{
					if (_grid->getCell(x - 3, y) == Grid::NONE && _grid->getCell(x + 1, y) == Grid::NONE)
						value -= 50;
				}
			}
			// ALIGNEMENT DE BLACK
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				white = 0;
				black++;
				if (black == 5)
					value += 1000;
				else if (black == 4)
				{
					if (_grid->getCell(x - 4, y) == Grid::NONE && _grid->getCell(x + 1, y) == Grid::NONE)
						value += 400;
					else if (_grid->getCell(x - 4, y) == Grid::NONE || _grid->getCell(x + 1, y) == Grid::NONE)
						value += 100;
				}
				else if (black == 3)
				{
					if (_grid->getCell(x - 3, y) == 0 && _grid->getCell(x + 1, y) == Grid::NONE)
						value += 50;
					else if (_grid->getCell(x - 3, y) == Grid::NONE && _grid->getCell(x - 4, y) == Grid::NONE
						|| _grid->getCell(x + 1, y) == Grid::NONE && _grid->getCell(x + 2, y) == Grid::NONE)
						value += 10;
				}
				else if (black == 2)
				{
					if (_grid->getCell(x + 1, y) == Grid::NONE && _grid->getCell(x + 2, y) == Grid::NONE
						&& (_grid->getCell(x + 3, y) == Grid::NONE || _grid->getCell(x - 2, y) == Grid::NONE))
					{
						value += 2;
					}
					else if (_grid->getCell(x - 2, y) == Grid::NONE && _grid->getCell(x - 3, y) == Grid::NONE
						&& (_grid->getCell(x - 4, y) == Grid::NONE || _grid->getCell(x + 1, y) == Grid::NONE))
					{
						value += 2;
					}
				}
			}
			else
			{
				white = 0;
				black = 0;
			}
		}
	}

	// EN COLONNE

	for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
	{
		white = 0;
		black = 0;
		for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
		{
			// ALIGNEMENT DE WHITE
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				black = 0;
				white++;
				if (white == 5)
					value -= 1000;
				else if (white == 4)
				{
					if (_grid->getCell(x, y - 4) == Grid::NONE && _grid->getCell(x, y + 1) == Grid::NONE)
						value -= 400;
					else if (_grid->getCell(x, y - 4) == Grid::NONE || _grid->getCell(x, y + 1) == Grid::NONE)
						value -= 100;
				}
				else if (white == 3)
				{
					if (_grid->getCell(x, y - 3) == Grid::NONE && _grid->getCell(x, y + 1) == Grid::NONE)
						value -= 50;
				}
			}
			// ALIGNEMENT DE BLACK
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				white = 0;
				black++;
				if (black == 5)
					value += 1000;
				else if (black == 4)
				{
					if (_grid->getCell(x, y - 4) == Grid::NONE && _grid->getCell(x, y + 1) == Grid::NONE)
						value += 400;
					else if (_grid->getCell(x, y - 4) == Grid::NONE || _grid->getCell(x, y + 1) == Grid::NONE)
						value += 100;
				}
				else if (black == 3)
				{
					if (_grid->getCell(x, y - 3) == Grid::NONE && _grid->getCell(x, y + 1) == Grid::NONE)
						value += 50;
					else if (_grid->getCell(x, y - 3) == Grid::NONE && _grid->getCell(x, y - 4) == Grid::NONE
						|| _grid->getCell(x, y + 1) == Grid::NONE && _grid->getCell(x, y + 2) == Grid::NONE)
						value += 10;
				}
				else if (black == 2)
				{
					if (_grid->getCell(x, y + 1) == Grid::NONE && _grid->getCell(x, y + 2) == Grid::NONE
						&& (_grid->getCell(x, y + 3) == Grid::NONE || _grid->getCell(x, y - 2) == Grid::NONE))
					{
						value += 2;
					}
					else if (_grid->getCell(x, y - 2) == Grid::NONE && _grid->getCell(x, y - 3) == Grid::NONE
						&& (_grid->getCell(x, y - 4) == Grid::NONE || _grid->getCell(x, y + 1) == Grid::NONE))
					{
						value += 2;
					}
				}
			}
			else
			{
				white = 0;
				black = 0;
			}
		}
	}

	// EN DIAG MONTANTE

	char Y = _grid->getTop();
	char X = _grid->getLeft();
	while (X < _grid->getRight())
	{
		black = 0;
		white = 0;
		char x = X;
		char y = Y;
		while (_grid->getCell(x, y) != Grid::EDGE)
		{
			// ALIGNEMENT DE WHITE
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				black = 0;
				white++;
				if (white == 5)
					value -= 1000;
				else if (white == 4)
				{
					if (_grid->getCell(x - 4, y + 4) == Grid::NONE && _grid->getCell(x + 1, y - 1) == Grid::NONE)
						value -= 400;
					else if (_grid->getCell(x - 4, y + 4) == Grid::NONE || _grid->getCell(x + 1, y - 1) == Grid::NONE)
						value -= 100;
				}
				else if (white == 3)
				{
					if (_grid->getCell(x - 3, y + 3) == Grid::NONE && _grid->getCell(x + 1, y - 1) == Grid::NONE)
						value -= 50;
				}
			}
			// ALIGNEMENT DE BLACK
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				white = 0;
				black++;
				if (black == 5)
					value += 1000;
				else if (black == 4)
				{
					if (_grid->getCell(x - 4, y + 4) == Grid::NONE && _grid->getCell(x + 1, y - 1) == Grid::NONE)
						value += 400;
					else if (_grid->getCell(x - 4, y + 4) == Grid::NONE || _grid->getCell(x + 1, y - 1) == Grid::NONE)
						value += 100;
				}
				else if (black == 3)
				{
					if (_grid->getCell(x - 3, y + 3) == Grid::NONE && _grid->getCell(x + 1, y - 1) == Grid::NONE)
						value += 50;
					else if (_grid->getCell(x - 3, y + 3) == Grid::NONE && _grid->getCell(x - 4, y + 4) == Grid::NONE
						|| _grid->getCell(x + 1, y - 1) == Grid::NONE && _grid->getCell(x + 2, y - 2) == Grid::NONE)
						value += 10;
				}
				else if (black == 2)
				{
					if (_grid->getCell(x + 1, y - 1) == Grid::NONE && _grid->getCell(x + 2, y - 2) == Grid::NONE
						&& (_grid->getCell(x + 3, y - 3) == Grid::NONE || _grid->getCell(x - 2, y + 2) == Grid::NONE))
					{
						value += 2;
					}
					else if (_grid->getCell(x - 2, y + 2) == Grid::NONE && _grid->getCell(x - 3, y + 3) == Grid::NONE
						&& (_grid->getCell(x - 4, y + 4) == Grid::NONE || _grid->getCell(x + 1, y - 1) == Grid::NONE))
					{
						value += 2;
					}
				}
			}
			else
			{
				white = 0;
				black = 0;
			}
			y--;
			x++;
		}
		if (Y < _grid->getBottom())
			Y++;
		else
			X++;
	}

	// EN DIAG DESCENDANTE

	char Y = _grid->getBottom();
	char X = _grid->getLeft();
	while (X < _grid->getRight())
	{
		black = 0;
		white = 0;
		char x = X;
		char y = Y;
		while (_grid->getCell(x, y) != Grid::EDGE)
		{
			// ALIGNEMENT DE WHITE
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				black = 0;
				white++;
				if (white == 5)
					value -= 1000;
				else if (white == 4)
				{
					if (_grid->getCell(x - 4, y - 4) == Grid::NONE && _grid->getCell(x + 1, y + 1) == Grid::NONE)
						value -= 400;
					else if (_grid->getCell(x - 4, y - 4) == Grid::NONE || _grid->getCell(x + 1, y + 1) == Grid::NONE)
						value -= 100;
				}
				else if (white == 3)
				{
					if (_grid->getCell(x - 3, y - 3) == Grid::NONE && _grid->getCell(x + 1, y + 1) == Grid::NONE)
						value -= 50;
				}
			}
			// ALIGNEMENT DE BLACK
			else if (_grid->getCell(x, y) == Grid::BLACK)
			{
				white = 0;
				black++;
				if (black == 5)
					value += 1000;
				else if (black == 4)
				{
					if (_grid->getCell(x - 4, y - 4) == Grid::NONE && _grid->getCell(x + 1, y + 1) == Grid::NONE)
						value += 400;
					else if (_grid->getCell(x - 4, y - 4) == Grid::NONE || _grid->getCell(x + 1, y + 1) == Grid::NONE)
						value += 100;
				}
				else if (black == 3)
				{
					if (_grid->getCell(x - 3, y - 3) == Grid::NONE && _grid->getCell(x + 1, y + 1) == Grid::NONE)
						value += 50;
					else if (_grid->getCell(x - 3, y - 3) == Grid::NONE && _grid->getCell(x - 4, y - 4) == Grid::NONE
						|| _grid->getCell(x + 1, y + 1) == Grid::NONE && _grid->getCell(x + 2, y + 2) == Grid::NONE)
						value += 10;
				}
				else if (black == 2)
				{
					if (_grid->getCell(x + 1, y + 1) == Grid::NONE && _grid->getCell(x + 2, y + 2) == Grid::NONE
						&& (_grid->getCell(x + 3, y + 3) == Grid::NONE || _grid->getCell(x - 2, y - 2) == Grid::NONE))
					{
						value += 2;
					}
					else if (_grid->getCell(x - 2, y - 2) == Grid::NONE && _grid->getCell(x - 3, y - 3) == Grid::NONE
						&& (_grid->getCell(x - 4, y - 4) == Grid::NONE || _grid->getCell(x + 1, y + 1) == Grid::NONE))
					{
						value += 2;
					}
				}
			}
			else
			{
				white = 0;
				black = 0;
			}
			y++;
			x++;
		}
		if (Y > _grid->getTop())
			Y--;
		else
			X++;
	}

	return (value);
}