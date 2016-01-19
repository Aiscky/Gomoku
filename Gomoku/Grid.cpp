#include "Grid.h"

Grid::Grid()
{
	memset(_grid, 0, squareNumber * squareNumber);
}

unsigned char Grid::getSideSize()
{
	return (squareNumber);
}

void Grid::addPawn(char x, char y, PlayerColor color)
{
	_grid[x][y] = color;
}

char Grid::getCell(char x, char y)
{
	return (_grid[x][y]);
}

void Grid::affGrid()
{
	for (unsigned char y = 0; y < squareNumber; y++)
	{
		for (unsigned char x = 0; x < squareNumber; x++)
		{
			std::cout << (int)_grid[x][y];
		}
		std::cout << std::endl;
	}
}