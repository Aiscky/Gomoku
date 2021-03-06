#include "Grid.h"

Grid::Grid()
{
	memset(_grid, 0, squareNumber * squareNumber);
	int mid = floor(squareNumber / 2);
	_searchSpace.left = mid - 1;
	_searchSpace.right = mid + 1;
	_searchSpace.top = mid - 1;
	_searchSpace.bottom = mid + 1;
	_playersPawnsLeft[0] = StartingPawnsLeft;
	_playersPawnsLeft[1] = StartingPawnsLeft;
	_playersPawnsCaptured[0] = StartingPawnsCaptured;
	_playersPawnsCaptured[1] = StartingPawnsCaptured;

	addPawn(mid, mid, BLACK);
	_playersPawnsLeft[0]--;
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

	checkCapture(x, y, color);
}

void Grid::deletePawn(char x, char y)
{
	_grid[y][x] = NONE;
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

void Grid::checkCapture(char x, char y, PlayerColor color)
{
	if (getCell(x - 1, y - 1) == getOpponentColor(color) && getCell(x - 2, y - 2) == getOpponentColor(color) && getCell(x - 3, y - 3) == color)
		capturePawns(x - 1, y - 1, x - 2, y - 2, color);
	if (getCell(x, y - 1) == getOpponentColor(color) && getCell(x, y - 2) == getOpponentColor(color) && getCell(x, y - 3) == color)
		capturePawns(x, y - 1, x, y - 2, color);
	if (getCell(x + 1, y - 1) == getOpponentColor(color) && getCell(x + 2, y - 2) == getOpponentColor(color) && getCell(x + 3, y - 3) == color)
		capturePawns(x + 1, y - 1, x + 2, y - 2, color);
	if (getCell(x + 1, y) == getOpponentColor(color) && getCell(x + 2, y) == getOpponentColor(color) && getCell(x + 3, y) == color)
		capturePawns(x + 1, y, x + 2, y, color);
	if (getCell(x + 1, y + 1) == getOpponentColor(color) && getCell(x + 2, y + 2) == getOpponentColor(color) && getCell(x + 3, y + 3) == color)
		capturePawns(x + 1, y + 1, x + 2, y + 2, color);
	if (getCell(x, y + 1) == getOpponentColor(color) && getCell(x, y + 2) == getOpponentColor(color) && getCell(x, y + 3) == color)
		capturePawns(x, y + 1, x, y + 2, color);
	if (getCell(x - 1, y + 1) == getOpponentColor(color) && getCell(x - 2, y + 2) == getOpponentColor(color) && getCell(x - 3, y + 3) == color)
		capturePawns(x - 1, y + 1, x - 2, y + 2, color);
	if (getCell(x - 1, y) == getOpponentColor(color) && getCell(x - 2, y) == getOpponentColor(color) && getCell(x - 3, y) == color)
		capturePawns(x - 1, y, x - 2, y, color);
}

void Grid::capturePawns(char x1, char y1, char x2, char y2, PlayerColor color)
{
	if (color == BLACK)
	{
		_grid[y1][x1] = WHITECAPTURED;
		_grid[y2][x2] = WHITECAPTURED;
	}
	if (color == WHITE)
	{
		_grid[y1][x1] = BLACKCAPTURED;
		_grid[y2][x2] = BLACKCAPTURED;
	}
	_playersPawnsCaptured[color - 1] += 2;
}

void Grid::cancelCapture(PlayerColor color)
{
	for (unsigned char y = _searchSpace.top; y < _searchSpace.bottom; y++)
	{
		for (unsigned char x = _searchSpace.left; x < _searchSpace.right; x++)
		{
			if (color == WHITE)
			{
				if (_grid[y][x] == BLACKCAPTURED)
				{
					_grid[y][x] = BLACK;
					_playersPawnsCaptured[1] -= 1;
				}
			}
			if (color == BLACK)
			{
				if (_grid[y][x] == WHITECAPTURED)
				{
					_grid[y][x] = WHITE;
					_playersPawnsCaptured[0] -= 1;
				}
			}
		}
	}
}

void Grid::cleanCapture()
{
	for (unsigned char y = _searchSpace.top; y < _searchSpace.bottom; y++)
	{
		for (unsigned char x = _searchSpace.left; x < _searchSpace.right; x++)
		{
			if (_grid[y][x] == BLACKCAPTURED || _grid[y][x] == WHITECAPTURED)
				_grid[y][x] = NONE;
		}
	}
}

char Grid::getCell(char x, char y)
{
	if (x < 0 || x > squareNumber - 1 || y < 0 || y > squareNumber - 1)
		return (EDGE);
	return (_grid[y][x]);
}

char Grid::getNextCell(char x, char y, char directionX, char directionY)
{
	x += directionX;
	y += directionY;
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

char *Grid::getPlayersPawnsLeft()
{
	return _playersPawnsLeft;
}

char *Grid::getPlayersPawnsCaptured()
{
	return _playersPawnsCaptured;
}

void Grid::RemovePawnFromPlayerPawnsLeft(char playerNumber)
{
	_playersPawnsLeft[playerNumber] = _playersPawnsLeft[playerNumber] - 1;
}
