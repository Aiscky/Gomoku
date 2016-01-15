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

void PlayerVsAIModel::Clicked(sf::Vector2i position)
{
	_window->clear();
	sf::Texture texture;

	texture.loadFromFile("../Images/Goban.bmp");
	sf::Sprite sprite(texture);
	sprite.setPosition(sf::Vector2f(240, 0));
	_window->draw(sprite);

	texture.loadFromFile("../Images/White.png");
	sf::Sprite sprite2(texture);
	sprite2.setPosition((sf::Vector2f)position);
	_window->draw(sprite2);
	_window->display();
}