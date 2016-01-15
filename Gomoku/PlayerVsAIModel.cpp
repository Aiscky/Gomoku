#include "PlayerVsAIModel.h"

PlayerVsAIModel::PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManager)
{
	this->_eventManagerAddr = eventManager;
	this->_window = window;
	
}

void PlayerVsAIModel::clicked()
{
	sf::Texture texture;

	texture.loadFromFile("../Gomoku/grille.gif");
	sf::Sprite sprite(texture);
	sprite.setScale(sf::Vector2f(2.f, 2.f));

	std::cout << "Clicked" << std::endl;

	_window->draw(sprite);
	_window->display();
}