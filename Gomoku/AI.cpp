#include "AI.h"

AI::AI(Grid *grid)
{
	_grid = grid;
	srand(time(NULL));
}

void AI::play()
{
	int depth = 3;
	char bestX = _grid->getLeft();
	char bestY = _grid->getTop();
	int tmp;
	_alpha = -1000;
	_beta = 1000;

	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == 0)
			{
				_grid->addPawn(x, y, Grid::BLACK);
				tmp = Min(depth - 1);
				if (tmp > _alpha)
				{
					_alpha = tmp;
					bestX = x;
					bestY = y;
				}
				_grid->deletePawn(x, y);
			}
		}
	}
	_grid->addPawn(bestX, bestY, Grid::BLACK);
}

int AI::Min(int depth)
{
	int tmp;
	if (depth == 0)
		return (Eval());
	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == 0)
			{
				_grid->addPawn(x, y, Grid::BLACK);
				tmp = Max(depth - 1);
				_grid->deletePawn(x, y);
				if (tmp < _beta)
					_beta = tmp;
				if (_beta <= _alpha)
					return (_beta);
			}
		}
	}
	return (_beta);
}

int AI::Max(int depth)
{
	int tmp;
	if (depth == 0)
		return (Eval());
	for (char y = _grid->getTop(); y <= _grid->getBottom(); y++)
	{
		for (char x = _grid->getLeft(); x <= _grid->getRight(); x++)
		{
			if (_grid->getCell(x, y) == 0)
			{
				_grid->addPawn(x, y, Grid::BLACK);
				tmp = Min(depth - 1);
				_grid->deletePawn(x, y);
				if (tmp > _alpha)
					_alpha = tmp;
				if (_beta < _alpha)
					return (_alpha);
			}
		}
	}
	return (_alpha);
}

int AI::Eval()
{
	return (1);
}

