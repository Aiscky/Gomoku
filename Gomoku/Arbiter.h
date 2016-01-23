#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Grid.h"

class Arbiter
{
private:
	enum Orientation
	{
		TORIGHT,
		TOTOP,
		TOTOPRIGHT,
		TOBOTTOMRIGHT
	};

	typedef struct s_orientation {
		char x;
		char y;
	} t_orientation;

	/*typedef struct s_Coefficients
	{
		s_orientation horizontalCoefficient;
		s_orientation verticalCoefficient;
		s_orientation obliqueUpwardCoefficient;
		s_orientation obliqueDownwardCoefficient;
	} Coefficients;*/

	t_orientation orientationCoefficients[4];

	static const unsigned char orientationCoefficientsNumber = 4;

	enum Direction
	{
		NORMAL,
		OPPOSITE
	};

	Grid::PlayerColor currentPlayer;
	Grid::PlayerColor opponentColor;
	Grid *grid;

	char selectedPawnX;
	char selectedPawnY;

	char linePawnsCount;
	bool lastCellEmpty;
	bool lineBlocked;
	bool shouldExit;

	static const char FreeLinePawnsNumber = 3;

public:
	Arbiter();
	~Arbiter();

	/* MAIN FUNCTION TO CHECK IF PAWN LOCATION IS VALID */
	bool CheckPlayable(Grid::PlayerColor currentPlayer, Grid *grid, char x, char y);

	/* FUNCTION TO CHECK IF THE DOUBLE TREE RULE IS FOLLOWED */
	bool doesCreateDoubleThree();

	bool CheckFreeThree(char startCellX, char startCellY, t_orientation orientationSteps);

	bool CheckFreeCellForThree(char cellX, char cellY, t_orientation orientationSteps, int limit, int * PawnsCount, int * FreeCell);

	bool isInsideGrid(int x, int y);

	/* FUNCTION TO CHECK IF ADJACENT RULE IS FOLLOWED */
	bool isAdjacentToExistingPawn();

	bool isDoubleThree();

	/* FUNCTIONS OF INTERNAL FUNCTIONNING OF CheckDoubleTree */
	bool CheckFreeLineSide(char startCellX, char startCellY, t_orientation OrientationSteps, Direction direction);
	bool CheckFreeLine(char startCellX, char startCellY, t_orientation orientationSteps);
	void UpdateCountAndFlagsFromCell(char cellX, char cellY);

	bool CheckFreeCrossingLinesForLine(char startingCellX, char startingCellY, t_orientation orientationCoefficient);
	bool CheckFreeCrossingLinesForLineSide(char startingCellX, char startingCellY, t_orientation orientationCoefficient, Direction direction);
	bool CheckFreeCrossingLinesForCell(char cellX, char cellY, t_orientation orientationCoefficient);
	bool CheckSideFreeCrossingLines(t_orientation orientationCoefficient);

	t_orientation getOrientationCoefficientOpposite(t_orientation orientationCoefficient);
};

