#include "PVPModel.h"

PVPModel::PVPModel(sf::RenderWindow *window, EventManager **eventManagerAddr)
{
	_window = window;
	_eventManagerAddr = eventManagerAddr;

	/* SETTING GRID */

	_grid = new Grid();

	/* SETTING GRID RECT */

	_gridBackgroundRect.width = 800;
	_gridBackgroundRect.height = 800;
	_gridBackgroundRect.top = 0;
	_gridBackgroundRect.left = (WINDOW_WIDTH - _gridBackgroundRect.width) / 2;

	_squareSize.x = _gridBackgroundRect.width / 19;
	_squareSize.y = _gridBackgroundRect.height / 19;

	/* CREATING SPRITES AND TEXTURES */

	_gridBackgroundTexture.loadFromFile("Images/Goban.bmp");
	_gridBackground.setTexture(_gridBackgroundTexture);
	_gridBackground.setPosition(_gridBackgroundRect.left, _gridBackgroundRect.top);

	_pawnsTexture[BLACK].loadFromFile("Images/Black.png");
	_pawnsTexture[WHITE].loadFromFile("Images/White.png");

	_pawnsSprites[BLACK].setTexture(_pawnsTexture[BLACK]);
	_pawnsSprites[WHITE].setTexture(_pawnsTexture[WHITE]);

	_currentPlayerColor = Grid::WHITE;
	_currentPlayer = WHITE;

	_winningStates[BLACK] = false;
	_winningStates[WHITE] = false;

	SettingHUD();
}

void PVPModel::SettingHUD()
{
	_HUD = new InGameHUD(_grid->getPlayersPawnsCaptured(), _grid->getPlayersPawnsLeft(), _currentTurnNumber);
}

// Convert coordinates to grid coordinates and check send it to arbiter

bool PVPModel::Clicked(float x, float y)
{
	if (_gridBackgroundRect.contains(x, y))
	{
		int X;
		int Y;

		X = floor((x - _gridBackgroundRect.left) / _squareSize.x);
		Y = floor((y - _gridBackgroundRect.top) / _squareSize.y);
		if (_arbiter.CheckPlayable(_currentPlayerColor, _grid, X, Y))
		{
			/* CHECK IF STILL WINNING IF WINNING STATE = TRUE */

			/*
			if (_winningStates[0])
			{
				if (_arbiter->CheckWinningStateFromBoard(grid, currentPlayer))
					-> winning
			}
			*/

			_grid->addPawn(X, Y, _currentPlayerColor);
			_grid->RemovePawnFromPlayerPawnsLeft(_currentPlayer);
			_HUD->setPawnsLeftField((char)_currentPlayer, _grid->getPlayersPawnsLeft()[_currentPlayer]);

			/* DO CAPTURE AND CHECK IF WON SET WINNING STATE */

			/*
			_arbiter->DoCaptureFromCell();
			if (_pairsCaptured[player] >= numberOfPairsToWin)
				->win
				if (_arbiter->CheckWinningStateFromCell(grid, currentPlayer, cellX, cellY))
					winningStates[player] = true;
			*/

			ChangePlayerTurn();
		}
	}
	return true;
}

void PVPModel::ChangePlayerTurn()
{
	_currentPlayer = (Player)(_currentPlayer ^ 1);
	_currentPlayerColor = _grid->getOpponentColor(_currentPlayerColor);
	if (_currentPlayer == WHITE)
	{
		_currentTurnNumber++;
		_HUD->setCurrentTurnNumberField(_currentTurnNumber);

	}
}

void PVPModel::Display(sf::RenderWindow *window)
{
	Grid::PlayerColor cellPlayerColor;

	window->clear();
	window->draw(_gridBackground);

	for (unsigned char x = 0; x < _grid->getSideSize(); x++)
	{
		for (unsigned char y = 0; y < _grid->getSideSize(); y++)
		{
			cellPlayerColor = (Grid::PlayerColor)_grid->getCell(x, y);

			if (cellPlayerColor == Grid::BLACK)
			{
				_pawnsSprites[BLACK].setPosition(_gridBackgroundRect.left + _squareSize.x * x, _gridBackgroundRect.top + _squareSize.y * y);
				window->draw(_pawnsSprites[BLACK]);
			}
			if (cellPlayerColor == Grid::WHITE)
			{
				_pawnsSprites[WHITE].setPosition(_gridBackgroundRect.left + _squareSize.x * x, _gridBackgroundRect.top + _squareSize.y * y);
				window->draw(_pawnsSprites[WHITE]);
			}
		}
	}

	_HUD->Display(window);

	window->display();
}

bool PVPModel::BackToMenu()
{
	delete (*_eventManagerAddr);
	(*_eventManagerAddr) = new MenuEventManager(_window, _eventManagerAddr);
	return true;
}