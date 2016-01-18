#pragma once
#include "GameEngine.h"

class Grid
{
private:
	const static unsigned int squareNumber = 19;
	char _grid[squareNumber][squareNumber];

public:
	Grid();
	~Grid() {};
	void addPawn(int x, int y, int color);
	int getCell(int x, int y);
	unsigned int getSideSize();
};

