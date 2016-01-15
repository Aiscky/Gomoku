#include "PlayerVsAIModel.h"

PlayerVsAIModel::PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManager)
{
	this->_eventManagerAddr = eventManager;
	this->_window = window;
	
}

void PlayerVsAIModel::clicked()
{
	sf::Image background;
	background.loadFromFile("grille.gif");
	_window->display();
}