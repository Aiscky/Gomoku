#include "PVPModel.h"

PVPModel::PVPModel(sf::RenderWindow *window, EventManager **eventManagerAddr)
{
	_window = window;
	_eventManagerAddr = eventManagerAddr;

	/* SETTING GRID RECT */

	_gridBackgroundRect.width = 800;
	_gridBackgroundRect.height = 800;
	_gridBackgroundRect.top = 0;
	_gridBackgroundRect.left = (WINDOW_WIDTH - _gridBackgroundRect.width) / 2;

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

PVPModel::~PVPModel()
{
}

// Convert coordinates to grid coordinates and check send it to arbiter

bool PVPModel::Clicked(float x, float y)
{
	if (_gridBackgroundRect.contains(x, y))
		std::cout << "Click on grid" << std::endl;
	return true;
}

void PVPModel::Display(sf::RenderWindow *window)
{
	window->clear();
	window->draw(_gridBackground);
	window->display();
}