#include "Arbiter.h"

Arbiter::Arbiter()
{
	/* SETTING HORIZONTAL COEFFICIENT */

	orientationCoefficients[0].x = 1;
	orientationCoefficients[0].y = 0;

	orientationCoefficients[1].x = 1;
	orientationCoefficients[1].y = 1;

	orientationCoefficients[2].x = 1;
	orientationCoefficients[2].y = -1;

	orientationCoefficients[3].x = 0;
	orientationCoefficients[3].y = 1;
}

Arbiter::~Arbiter()
{
}

bool Arbiter::CheckPlayable(Grid::PlayerColor currentPlayer, Grid *grid, char selectedPawnX, char selectedPawnY)
{
	this->currentPlayer = currentPlayer;
	this->grid = grid;
	this->opponentColor = grid->getOpponentColor(currentPlayer);
	this->selectedPawnX = selectedPawnX;
	this->selectedPawnY = selectedPawnY;

	if (grid->isCellEmpty(this->selectedPawnX, this->selectedPawnY) &&
		isAdjacentToExistingPawn() &&
		!doesCreateDoubleTree())
	{
		return true;
	}

	return false;
}

bool Arbiter::isAdjacentToExistingPawn()
{
	/* CHECK ALL ADJACENT SQUARES FOR PLAYERS PAWNS */

	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if (!(i == 0 && j == 0) && 
				selectedPawnX + i >= 0 &&
				selectedPawnX + i < grid->getSideSize() &&
				selectedPawnY + j >= 0 &&
				selectedPawnY + j < grid->getSideSize())
			{
				if (grid->getCell(selectedPawnX + i, selectedPawnY + j) != Grid::NONE)
				{
					return true;
				}
			}
		}
	}

	return false;
}

bool Arbiter::doesCreateDoubleTree()
{
	/* CHECK EVERY DIRECTION AND POSSIBIBLY CROSSING LINES FOR FREELINE  */

	bool isAlreadyFreeLine = false;

	for (unsigned char n = 0; n < orientationCoefficientsNumber; n++) //A MODIF
	{
		if (CheckFreeLine(selectedPawnX, selectedPawnY, orientationCoefficients[n]))
		{
			//CheckCrossingFreeLines();
			return true;
		}
	}

	return false;
}

bool Arbiter::CheckFreeLine(char startCellX, char startCellY, t_orientation orientationSteps)
{
	linePawnsCount = 1;

	if (!CheckFreeLineSide(startCellX, startCellY, orientationSteps, NORMAL) &&
		!CheckFreeLineSide(startCellX - orientationSteps.x, startCellY - orientationSteps.y, orientationSteps, OPPOSITE) && //NOT CHECKING TWICE THE STARTING CELL OF FREELINE
		linePawnsCount >= FreeLinePawnsNumber)
	{
		return true;
	}

	std::cout << (int)linePawnsCount << std::endl;

	return false;
}

bool Arbiter::CheckFreeLineSide(char startCellX, char startCellY, t_orientation orientationSteps, Direction direction)
{
	lineBlocked = false;
	lastCellEmpty = false;
	shouldExit = false;

	int cellX = startCellX;
	int cellY = startCellY;

	if (direction == OPPOSITE)
	{
		orientationSteps.x = -orientationSteps.x;
		orientationSteps.y = -orientationSteps.y;
	}

	while (!lineBlocked && !shouldExit)
	{
		/* TODO CHANGE ALGO SO IT DOESNT GO THROUGH THE WHOLE GRID */

		UpdateCountAndFlagsFromCell(cellX, cellY);

		cellX += orientationSteps.x;
		cellY += orientationSteps.y;
	}

	return (lineBlocked);
}

void Arbiter::UpdateCountAndFlagsFromCell(char cellX, char cellY)
{
	if (cellX < 0 || cellX > grid->getSideSize() || cellY < 0 || cellY > grid->getSideSize())
	{
		if (lastCellEmpty == false)
			lineBlocked = true;
		else
			shouldExit = true;
	}
	else if (grid->getCell(cellX, cellY) == currentPlayer)
	{
		lastCellEmpty = false;
		linePawnsCount++;
	}
	else if (grid->getCell(cellX, cellY) != Grid::NONE)
	{
		if (lastCellEmpty == false)
			lineBlocked = true;
		else
			shouldExit = true;
	}
	else
		lastCellEmpty = true;
}

bool Arbiter::CheckFreeCrossingLinesForLine(char startingCellX, char startingCellY, t_orientation orientationCoefficient) 
{
	if (CheckFreeCrossingLinesForLineSide(startingCellX, startingCellY, orientationCoefficient, Arbiter::NORMAL) ||
		CheckFreeCrossingLinesForLineSide(startingCellX - orientationCoefficient.x, startingCellY - orientationCoefficient.y, orientationCoefficient, Arbiter::OPPOSITE))
	{
		return true;
	}
	return false;
}

bool Arbiter::CheckFreeCrossingLinesForLineSide(char startingCellX, char startingCellY, t_orientation orientationCoefficient, Direction direction)
{
	char cellX = startingCellX;
	char cellY = startingCellY;

	if (direction == OPPOSITE)
	{
		orientationCoefficient.x = -orientationCoefficient.x;
		orientationCoefficient.y = -orientationCoefficient.y;
	}

	while (cellX > 0 &&
		cellX < grid->getSideSize() &&
		cellY > 0 &&
		cellY < grid->getSideSize() &&
		grid->getCell(cellX, cellY) != opponentColor)
	{
		if (CheckFreeCrossingLinesForCell(cellX, cellY, orientationCoefficient))
			return true;

		cellX += orientationCoefficient.x;
		cellY += orientationCoefficient.y;
	}

	return false;
}

bool Arbiter::CheckFreeCrossingLinesForCell(char cellX, char cellY, t_orientation orientationCoefficient)
{
	for (unsigned char n = 0; n < orientationCoefficientsNumber; n++)
	{
		if (orientationCoefficient.x != orientationCoefficients[n].x &&
			orientationCoefficient.y != orientationCoefficients[n].y)
		{
			if (CheckFreeLine(cellX, cellY, orientationCoefficients[n]))
				return true;
		}
	}

	return false;
}