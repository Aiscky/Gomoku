#include "PVPModel.h"

PVPModel::PVPModel()
{
	_gridBackgroundTexture.loadFromFile("Images/Goban.bmp");
	_gridBackground.setTexture(_gridBackgroundTexture);
	_gridBackground.setPosition(sf::Vector2f(240, 0));
}

PVPModel::~PVPModel()
{
}

void PVPModel::Display(sf::RenderWindow *window)
{
	window->clear();
	window->draw(_gridBackground);
	window->display();
}

// Convert coordinates to grid coordinates and check send it to arbiter

bool PVPModel::CheckPlayable(sf::Vector2f xy)
{
	return true;
}