#include "Grid.h"

Grid::Grid()
{
	memset(_grid, 0, squareNumber * squareNumber);
}

unsigned int Grid::getSideSize()
{
	return (squareNumber);
}

void Grid::addPawn(int x, int y, int color)
{
	_grid[x][y] = color;
}

int Grid::getCell(int x, int y)
{
	return (_grid[x][y]);
}