#include "PVPModel.h"

PVPModel::PVPModel(sf::RenderWindow *window, EventManager **eventManagerAddr)
{
	_window = window;
	_eventManagerAddr = eventManagerAddr;
	_gridBackgroundTexture.loadFromFile("Images/Goban.bmp");
	_gridBackground.setTexture(_gridBackgroundTexture);
	_gridBackground.setPosition(sf::Vector2f((WINDOW_WIDTH - _gridBackgroundSize) / 2, 0));
}

PVPModel::~PVPModel()
{
}

// Convert coordinates to grid coordinates and check send it to arbiter

bool PVPModel::CheckPlayable(float x, float y)
{
	std::cout << x << " : " << y << std::endl;
	return true;
}

void PVPModel::Display(sf::RenderWindow *window)
{
	window->clear();
	window->draw(_gridBackground);
	window->display();
}