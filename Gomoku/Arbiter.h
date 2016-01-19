#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"

class Arbiter
{
private:
	Arbiter();

	enum Orientation
	{
		HORIZONTAL,
		VERTICAL
	};

	static const char DoubleFreeLineNumber = 3;

public:
	~Arbiter();
	static bool CheckPlayable(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y);
	static bool CheckSideFreeLine(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y, char &count, char xStep, char yStep);
	//static bool CheckFreeLineHorizontal(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y);
	//static bool CheckFreeLineVertical(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y);
};

