#include "PlayerVsAIModel.h"

PlayerVsAIModel::PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManager)
{
	this->_eventManagerAddr = eventManager;
	this->_window = window;
}