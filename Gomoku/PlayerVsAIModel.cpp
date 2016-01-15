#include "PlayerVsAIModel.h"

void PlayerVsAIModel::Init()
{
	sf::Texture texture;

	texture.loadFromFile("../Images/Goban.bmp");
	sf::Sprite sprite(texture);
	sprite.setPosition(sf::Vector2f(240, 0));
	_window->draw(sprite);
	_window->display();
}

PlayerVsAIModel::PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManager)
{	
	this->_eventManagerAddr = eventManager;
	this->_window = window;
	
	this->Init();
}

void PlayerVsAIModel::Clicked()
{

}