#include "Grid.h"

Grid::Grid()
{
	memset(_grid, 0, squareNumber * squareNumber);
}

unsigned int Grid::getSideSize()
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
	for (unsigned int y = 0; y < squareNumber; y++)
	{
		for (unsigned int x = 0; x < squareNumber; x++)
		{
			std::cout << _grid[x][y];
		}
		std::cout << std::endl;
	}
}