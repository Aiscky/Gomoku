#include "AI.h"

AI::AI(Grid *grid)
{
	_grid = grid;
	srand(time(NULL));
}

void AI::play(char &X, char &Y)
{
	int depth = 2;
	_alpha = -10000;
	int max = _alpha;

	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == Grid::NONE && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
			{
				_grid->addPawn(x, y, Grid::BLACK);
				int tmp = Min(depth - 1);
				if (tmp >= max)
				{
					max = tmp;
					X = x;
					Y = y;
				}
				_grid->cancelCapture(Grid::BLACK);
				_grid->deletePawn(x, y);
			}
		}
	}
	_grid->addPawn(X, Y, Grid::BLACK);
	_grid->cleanCapture();
}

int AI::Min(int depth)
{
	if (depth == 0)
		return (Eval());
	_beta = 10000;
	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == Grid::NONE && _arbiter.CheckPlayable(Grid::WHITE, _grid, x, y))
			{
				_grid->addPawn(x, y, Grid::WHITE);
				_beta = std::min(_beta, Max(depth - 1));
				_grid->cancelCapture(Grid::WHITE);
				_grid->deletePawn(x, y);
				if (_beta <= _alpha)
					return (_alpha);
			}
		}
	}
	return (_beta);
}

int AI::Max(int depth)
{
	if (depth == 0)
		return (Eval());
	_alpha = -10000;
	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == Grid::NONE && _arbiter.CheckPlayable(Grid::BLACK, _grid, x, y))
			{
				_grid->addPawn(x, y, Grid::BLACK);
				_alpha = std::max(_alpha, Min(depth - 1));
				_grid->cancelCapture(Grid::BLACK);
				_grid->deletePawn(x, y);
				
			}
		}
	}
	return (_alpha);
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
					value -= 3000;
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
					value += 5000;
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
					value -= 5000;
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
					value += 5000;
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
					value -= 5000;
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
					value += 5000;
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

	Y = _grid->getBottom();
	X = _grid->getLeft();
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
					value -= 5000;
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
					value += 5000;
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

	// CAPTURES

	//WHITE
	if (_grid->getPlayersPawnsCaptured()[1] == 2)
		value -= 100;
	else if (_grid->getPlayersPawnsCaptured()[1] == 4)
		value -= 200;
	else if (_grid->getPlayersPawnsCaptured()[1] == 6)
		value -= 300;
	else if (_grid->getPlayersPawnsCaptured()[1] == 8)
		value -= 500;
	else if (_grid->getPlayersPawnsCaptured()[1] == 10)
		value -= 8000;

	//BLACK
	if (_grid->getPlayersPawnsCaptured()[0] == 2)
		value += 100;
	else if (_grid->getPlayersPawnsCaptured()[0] == 4)
		value += 200;
	else if (_grid->getPlayersPawnsCaptured()[0] == 6)
		value += 300;
	else if (_grid->getPlayersPawnsCaptured()[0] == 8)
		value += 500;
	else if (_grid->getPlayersPawnsCaptured()[0] == 10)
		value += 8000;

	return (value);
}