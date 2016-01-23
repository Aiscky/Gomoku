#include "PlayerVsAIModel.h"

PlayerVsAIModel::PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManagerAddr)
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

	_winningStates[BLACK] = false;
	_winningStates[WHITE] = false;

	//	SETTING HUD

	SettingHUD();

	/* CREATING AI */

	_bot = new AI(_grid);
}

void PlayerVsAIModel::SettingHUD()
{
	_HUD = new InGameHUD(_grid->getPlayersPawnsCaptured(), _grid->getPlayersPawnsLeft(), _currentTurnNumber);
}


bool PlayerVsAIModel::Clicked(float x, float y)
{
	if (_gridBackgroundRect.contains(x, y))
	{
		int X;
		int Y;

		X = floor((x - _gridBackgroundRect.left) / _squareSize.x);
		Y = floor((y - _gridBackgroundRect.top) / _squareSize.y);
		if (_arbiter.CheckPlayable(Grid::WHITE, _grid, X, Y))
		{
			_grid->addPawn(X, Y, Grid::WHITE);
			_grid->cleanCapture();
			_grid->RemovePawnFromPlayerPawnsLeft(WHITE);
			_HUD->setPawnsLeftField((char)WHITE, _grid->getPlayersPawnsLeft()[WHITE]);
			Display(_window);

			_bot->play();
			_grid->RemovePawnFromPlayerPawnsLeft(BLACK);
			_HUD->setPawnsLeftField((char)BLACK, _grid->getPlayersPawnsLeft()[BLACK]);

			_currentTurnNumber += 1;
			_HUD->setCurrentTurnNumberField(_currentTurnNumber);
			_HUD->setCapturedPawnsField(BLACK, _grid->getPlayersPawnsCaptured()[BLACK]);
			_HUD->setCapturedPawnsField(WHITE, _grid->getPlayersPawnsCaptured()[WHITE]);
		}
	}
	return true;
}

void PlayerVsAIModel::Display(sf::RenderWindow *window)
{
	window->clear();
	window->draw(_background);
	window->draw(_gridBackground);
	for (unsigned int y = 0; y < _grid->getSideSize(); y++)
	{
		for (unsigned int x = 0; x < _grid->getSideSize(); x++)
		{
			if (_grid->getCell(x, y) == Grid::BLACK)
			{
				_pawnsSprites[BLACK].setPosition(_gridBackgroundRect.left + _squareSize.x * x, _gridBackgroundRect.top + _squareSize.y * y);
				window->draw(_pawnsSprites[BLACK]);
			}
			if (_grid->getCell(x, y) == Grid::WHITE)
			{
				_pawnsSprites[WHITE].setPosition(_gridBackgroundRect.left + _squareSize.x * x, _gridBackgroundRect.top + _squareSize.y * y);
				window->draw(_pawnsSprites[WHITE]);
			}
		}
	}
	_HUD->Display(window);

	window->display();
}

bool PlayerVsAIModel::BackToMenu()
{
	delete (*_eventManagerAddr);
	(*_eventManagerAddr) = new MenuEventManager(_window, _eventManagerAddr);
	return true;
}