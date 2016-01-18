#include "PlayerVsAIModel.h"

PlayerVsAIModel::PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManagerAddr)
{	
	_window = window;
	_eventManagerAddr = eventManagerAddr;

	/* INSTANCNG GRID */

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

	_pawnsTexture[0].loadFromFile("Images/Black.png");
	_pawnsTexture[1].loadFromFile("Images/White.png");

	_pawnsSprites[0].setTexture(_pawnsTexture[0]);
	_pawnsSprites[1].setTexture(_pawnsTexture[1]);

	_winningStates[0] = false;
	_winningStates[1] = false;
}

bool PlayerVsAIModel::Clicked(float x, float y)
{
	if (_gridBackgroundRect.contains(x, y))
	{
		int X;
		int Y;

		X = floor((x - _gridBackgroundRect.left) / _squareSize.x);
		Y = floor((y - _gridBackgroundRect.top) / _squareSize.y);
		std::cout << X << " : " << Y << std::endl;
		_grid->addPaw(x, y, 1);
	}
	return true;
}

void PlayerVsAIModel::Display(sf::RenderWindow *window)
{
	window->clear();
	window->draw(_gridBackground);
	for (unsigned int y = 0; y < _grid->getSideSize(); y++)
	{
		for (unsigned int x = 0; x < _grid->getSideSize(); x++)
		{
			if (_grid->getCell(x, y) == 1)
			{
				_pawnsSprites[0].setPosition(_gridBackgroundRect.left + _squareSize.x * x, _gridBackgroundRect.top + _squareSize.y * y);
				window->draw(_pawnsSprites[0]);
			}
			if (_grid->getCell(x, y) == 2)
			{
				_pawnsSprites[1].setPosition(_gridBackgroundRect.left + _squareSize.x * x, _gridBackgroundRect.top + _squareSize.y * y);
				window->draw(_pawnsSprites[1]);
			}
		}
	}
	window->display();
}