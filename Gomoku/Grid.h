#ifndef GRID_H
# define GRID_H

#include "GameEngine.h"

class Grid
{
private:
	const static unsigned int squareNumber = 19;
	char _grid[squareNumber][squareNumber];

public:
	Grid();
	~Grid() {};
	void addPaw(int x, int y, int color);
	int getCell(int x, int y);
	unsigned int getSideSize();
};

#endif
