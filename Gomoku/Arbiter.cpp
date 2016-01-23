 #include "Arbiter.h"

Arbiter::Arbiter()
{
	/* SETTING HORIZONTAL COEFFICIENT */

	orientationCoefficients[0].x = 0;
	orientationCoefficients[0].y = -1;

	orientationCoefficients[1].x = -1;
	orientationCoefficients[1].y = -1;

	orientationCoefficients[2].x = -1;
	orientationCoefficients[2].y = 0;

	orientationCoefficients[3].x = -1;
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
		!isDoubleThree())
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
				grid->getCell(selectedPawnX + i, selectedPawnY + j) != Grid::EDGE)
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

bool Arbiter::isDoubleThree()
{
	int nbFreeThree = 0;
	for (unsigned char n = 0; n < orientationCoefficientsNumber; n++)
	{
		if (CheckFreeThree(selectedPawnX, selectedPawnY, orientationCoefficients[n]))
			nbFreeThree += 1;
	}
	if (nbFreeThree > 1)
		return true;
	return false;
}

bool Arbiter::CheckFreeThree(char cellX, char cellY, t_orientation orientationSteps)
{
	t_orientation oppositeDirection = getOrientationCoefficientOpposite(orientationSteps);

	for (int maxFree = 0; maxFree < 4; maxFree++)
	{
		int PawnsCount = 0;
		int FreeCell = 0;
		bool isFreeCell = true;
		isFreeCell = CheckFreeCellForThree(cellX, cellY, orientationSteps, maxFree, &PawnsCount, &FreeCell);
		if (isFreeCell)
			isFreeCell = CheckFreeCellForThree(cellX, cellY, oppositeDirection, 3 - maxFree, &PawnsCount, &FreeCell);
		if (isFreeCell && PawnsCount == 2 && FreeCell == 1)
		{
			char cell = grid->getCell(cellX + ((maxFree + 1) * orientationSteps.x), cellY + ((maxFree + 1) * orientationSteps.y));
			char oppositeCell = grid->getCell(cellX - ((4 - maxFree) * orientationSteps.x), cellY - ((4 - maxFree) * orientationSteps.y));
			if (cell != opponentColor && oppositeCell != opponentColor)
			{
				return true;
				break;
			}
		}
	}
	return false;
}

bool Arbiter::CheckFreeCellForThree(char cellX, char cellY, t_orientation orientationSteps, int limit,int *PawnsCount, int *FreeCell)
{
	for (int move = 1; move <= limit; move++)
	{
		char cell = grid->getCell(cellX + (move * orientationSteps.x), cellY + (move * orientationSteps.y));
		if (cell == Grid::EDGE)
			break;
		else if (cell == Grid::NONE)
			*FreeCell += 1;
		else if (cell == currentPlayer)
			*PawnsCount += 1;
		else
			return false;
	}
	return true;
}

Arbiter::t_orientation Arbiter::getOrientationCoefficientOpposite(t_orientation orientationCoefficient)
{
	orientationCoefficient.x = -orientationCoefficient.x;
	orientationCoefficient.y = -orientationCoefficient.y;
	
	return orientationCoefficient;
}

/* CHECKING FOR WIN */

bool Arbiter::CheckWinningStateFromCell(Grid::PlayerColor playerColor, char cellX, char cellY)
{
	currentPlayer = playerColor;

	for (unsigned char n = 0; n < orientationCoefficientsNumber; n++)
	{
		if (CheckWinningStateForOrientation(cellX, cellY, orientationCoefficients[n]))
		{
			std::cout << "WINNING" << std::endl;
			return true;
		}
	}

	return false;
}

bool Arbiter::CheckWinningStateForOrientation(char cellX, char cellY, t_orientation orientationCoefficient)
{
	linePawnsCount = 0;

	CheckWinningStateForDirection(cellX, cellY, orientationCoefficient, NORMAL);
	CheckWinningStateForDirection(cellX - orientationCoefficient.x, cellY - orientationCoefficient.y, orientationCoefficient, OPPOSITE);
	
	if (linePawnsCount >= 5)
		return true;
	return false;
}

void Arbiter::CheckWinningStateForDirection(char startingCellX, char startingCellY, t_orientation orientationCoefficient, Direction direction)
{
	char cellX = startingCellX;
	char cellY = startingCellY;

	Grid::PlayerColor pawnColor;

	if (direction == OPPOSITE)
		orientationCoefficient = getOrientationCoefficientOpposite(orientationCoefficient);

	while ((pawnColor = (Grid::PlayerColor)grid->getCell(cellX, cellY)) != Grid::EDGE)
	{
		if (pawnColor != currentPlayer)
			return;

		linePawnsCount++;
		cellX += orientationCoefficient.x;
		cellY += orientationCoefficient.y;
	}
}