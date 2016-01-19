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
	_grid[x][y] = color;
	if (x - 1 < _searchSpace.left)
		_searchSpace.left = (x - 1 < 0 ? 0 : x - 1);
	if (y - 1 < _searchSpace.top)
		_searchSpace.top = (y - 1 < 0 ? 0 : y - 1);
	if (x + 1 < _searchSpace.right)
		_searchSpace.right = (x + 1 > squareNumber - 1 ? squareNumber - 1 : x + 1);
	if (y + 1 < _searchSpace.bottom)
		_searchSpace.bottom = (y + 1 > squareNumber - 1 ? squareNumber - 1 : y + 1);
}

char Grid::getCell(char x, char y)
{
	return (_grid[x][y]);
}

/* void Grid::affGrid()
{
	for (unsigned char y = 0; y < squareNumber; y++)
	{
		for (unsigned char x = 0; x < squareNumber; x++)
		{
			std::cout << (int)_grid[x][y];
		}
		std::cout << std::endl;
	}
} */
