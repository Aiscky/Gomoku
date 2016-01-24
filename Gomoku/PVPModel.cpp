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

	_backgroundTexture.loadFromFile("Images/wood_background.bmp");
	_background.setTexture(_backgroundTexture);
	_background.setPosition(0, 0);

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

	_isGameFinished = false;

	/* SETTING BLACK AND WHITE WINNING TEXT */

	if (!_font.loadFromFile("Fonts/Track.TTF"))
	{
		char *error = (char *)malloc(265);

		strerror_s(error, 256, errno);
		std::cout << error << std::endl;
		exit(EXIT_FAILURE);
	}

	_whiteWinningText.setString("White Player Won");
	_whiteWinningText.setFont(_font);
	_whiteWinningText.setPosition(400.f, 180.f);
	_whiteWinningText.setCharacterSize(50);
	_whiteWinningText.setColor(sf::Color::White);

	_blackWinningText.setString("Black Player Won");
	_blackWinningText.setFont(_font);
	_blackWinningText.setPosition(400.f, 180.f);
	_blackWinningText.setCharacterSize(50);
	_blackWinningText.setColor(sf::Color::Black);

	/* SETTING HUD */

	SettingHUD();
}

void PVPModel::SettingHUD()
{
	_HUD = new InGameHUD(_grid->getPlayersPawnsCaptured(), _grid->getPlayersPawnsLeft(), _currentTurnNumber);
}

// Convert coordinates to grid coordinates and check send it to arbiter

bool PVPModel::Clicked(float x, float y)
{
	if (_isGameFinished)
		return true;

	if (_gridBackgroundRect.contains(x, y))
	{
		int X;
		int Y;

		X = floor((x - _gridBackgroundRect.left) / _squareSize.x);
		Y = floor((y - _gridBackgroundRect.top) / _squareSize.y);
		if (_arbiter.CheckPlayable(_currentPlayerColor, _grid, X, Y))
		{
			_grid->addPawn(X, Y, _currentPlayerColor);
			_grid->cleanCapture();
			_grid->RemovePawnFromPlayerPawnsLeft(_currentPlayer);
			_HUD->setPawnsLeftField((char)_currentPlayer, _grid->getPlayersPawnsLeft()[_currentPlayer]);
			_HUD->setCapturedPawnsField(_currentPlayer, _grid->getPlayersPawnsCaptured()[_currentPlayer]);

			if (_grid->getPlayersPawnsCaptured()[_currentPlayer] >= 10)
			{
				_isGameFinished = true;
				return true;
			}

			if (_arbiter.CheckWinningStateFromCell(_currentPlayerColor, X, Y))
			{
				_winningStates[_currentPlayer] = true;
				_lastWinningPawn[_currentPlayer][0] = X;
				_lastWinningPawn[_currentPlayer][1] = Y;
			}

			ChangePlayerTurn();

			if (_winningStates[_currentPlayer])
			{
				if (_arbiter.CheckWinningStateFromCell(_currentPlayerColor, _lastWinningPawn[_currentPlayer][0], _lastWinningPawn[_currentPlayer][1]))
				{
					_isGameFinished = true;
					return true;
				}
				else
					_winningStates[_currentPlayer] = false;
			}
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
	window->draw(_background);
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

	if (_isGameFinished)
	{
		if (_currentPlayer == WHITE)
		{
			_window->draw(_whiteWinningText);
		}
		else
		{
			_window->draw(_blackWinningText);
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