#include "PVPModel.h"

PVPModel::PVPModel(sf::RenderWindow *window, EventManager **eventManagerAddr)
{
	_window = window;
	_eventManagerAddr = eventManagerAddr;

	/* SETTING GRID */

	memset(_grid, 0, squareNumber * squareNumber);

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

	_playerTurn = false;
	_winningStates[0] = false;
	_winningStates[1] = false;
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
		std::cout << X << " : " << Y << std::endl;
		std::cout << "1" << std::endl;
		_grid[X][Y] = 1;
		std::cout << "2" << std::endl;
	}
	return true;
}

void PVPModel::Display(sf::RenderWindow *window)
{
	window->clear();
	window->draw(_gridBackground);
	for (unsigned int y = 0; y < squareNumber; y++)
	{
		for (unsigned int x = 0; x < squareNumber; x++)
		{
			if (_grid[x][y] == 1)
			{
				_pawnsSprites[0].setPosition(_gridBackgroundRect.left + _squareSize.x * x, _gridBackgroundRect.top + _squareSize.y * y);
				window->draw(_pawnsSprites[0]);
			}
		}
	}
	window->display();
}