#include "PlayerVsAIModel.h"

void PlayerVsAIModel::Init()
{
	_gridBackgroundTexture.loadFromFile("Images/Goban.bmp");
	_gridBackground.setTexture(_gridBackgroundTexture);
	_gridBackground.setPosition(sf::Vector2f(240, 0));
	_blackTexture.loadFromFile("Images/Black.png");
	_black.setTexture(_blackTexture);
	_whiteTexture.loadFromFile("Images/White.png");
	_white.setTexture(_whiteTexture);
}

PlayerVsAIModel::PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManager)
{	
	this->_eventManagerAddr = eventManager;
	this->_window = window;
	
	this->Init();
}

void PlayerVsAIModel::Display(sf::RenderWindow *window)
{
	_window->clear();
	_window->draw(_gridBackground);
	_window->draw(_white);
	_window->display();
}

void PlayerVsAIModel::Clicked(sf::Vector2i position)
{
	_white.setPosition((sf::Vector2f)position);
	_white.move(sf::Vector2f(-46, -16));
}