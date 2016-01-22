#include "Grid.h"

Grid::Grid()
{
	memset(_grid, 0, squareNumber * squareNumber);
	int mid = floor(squareNumber / 2);
	_searchSpace.left = mid - 1;
	_searchSpace.right = mid + 1;
	_searchSpace.top = mid - 1;
	_searchSpace.bottom = mid + 1;
	addPawn(mid, mid, BLACK);
}

unsigned char Grid::getSideSize()
{
	return (squareNumber);
}

void Grid::addPawn(char x, char y, PlayerColor color)
{
	_grid[y][x] = color;
	if (x - 1 < _searchSpace.left)
		_searchSpace.left = (x - 1 < 0 ? 0 : x - 1);
	if (y - 1 < _searchSpace.top)
		_searchSpace.top = (y - 1 < 0 ? 0 : y - 1);
	if (x + 1 > _searchSpace.right)
		_searchSpace.right = (x + 1 > squareNumber - 1 ? squareNumber - 1 : x + 1);
	if (y + 1 > _searchSpace.bottom)
		_searchSpace.bottom = (y + 1 > squareNumber - 1 ? squareNumber - 1 : y + 1);
}

void Grid::deletePawn(char x, char y)
{
	_grid[y][x] = 0;
	if (x == _searchSpace.left + 1)
	{
		_searchSpace.left += 1;
		for (char i = 0; i < squareNumber - 1; i++)
		{
			if (_grid[i][x] != 0)
			{
				_searchSpace.left -= 1;
				break;
			}
		}
	}
	if (x == _searchSpace.right - 1)
	{
		_searchSpace.right -= 1;
		for (char i = 0; i < squareNumber - 1; i++)
		{
			if (_grid[i][x] != 0)
			{
				_searchSpace.right += 1;
				break;
			}
		}
	}
	if (y == _searchSpace.top + 1)
	{
		_searchSpace.top += 1;
		for (char i = 0; i < squareNumber - 1; i++)
		{
			if (_grid[y][i] != 0)
			{
				_searchSpace.top -= 1;
				break;
			}
		}
	}
	if (y == _searchSpace.bottom - 1)
	{
		_searchSpace.bottom -= 1;
		for (char i = 0; i < squareNumber - 1; i++)
		{
			if (_grid[y][i] != 0)
			{
				_searchSpace.bottom += 1;
				break;
			}
		}
	}
}

char Grid::getCell(char x, char y)
{
	if (x < 0 || x > squareNumber - 1 || y < 0 || y > squareNumber - 1)
		return (EDGE);
	return (_grid[y][x]);
}

bool Grid::isCellEmpty(char x, char y)
{
	if (_grid[y][x] == NONE)
	{
		return true;
	}
	return false;
}

char Grid::getLeft()
{
	return (_searchSpace.left);
}

char Grid::getRight()
{
	return (_searchSpace.right);
}

char Grid::getTop()
{
	return (_searchSpace.top);
}

char Grid::getBottom()
{
	return (_searchSpace.bottom);
}

Grid::PlayerColor Grid::getOpponentColor(Grid::PlayerColor playerColor)
{
	if (playerColor == WHITE)
		return BLACK;
	else if (playerColor == BLACK)
		return WHITE;
	else
		return NONE;
}

char Grid::capturedPairs(PlayerColor playerColor)
{
	return (_playersPairsCaptured[playerColor-1]);
}

void Grid::affGrid()
{
	for (unsigned char y = 0; y < squareNumber; y++)
	{
		for (unsigned char x = 0; x < squareNumber; x++)
		{
			std::cout << (int)_grid[y][x];
		}
		std::cout << std::endl;
	}
}