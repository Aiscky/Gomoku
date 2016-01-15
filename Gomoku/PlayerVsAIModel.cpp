#include "PlayerVsAIModel.h"

void PlayerVsAIModel::Init()
{
	_gridBackgroundTexture.loadFromFile("Images/Goban.bmp");
	_gridBackground.setTexture(_gridBackgroundTexture);
	_gridBackground.setPosition(sf::Vector2f(240, 0));
	_blackTexture.loadFromFile("Images/Black.png");
	_pawnColor[0].setTexture(_blackTexture);
	_whiteTexture.loadFromFile("Images/White.png");
	_pawnColor[1].setTexture(_whiteTexture);
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
	for (int i = 0; i < _pawns.size(); i++)
		_window->draw(_pawns[i]);
	_window->display();
}

void PlayerVsAIModel::Clicked(sf::Vector2i position)
{
	_pawnColor[_playerTurn].setPosition((sf::Vector2f)position);
	if (_playerTurn)
		_pawnColor[_playerTurn].move(sf::Vector2f(-46, -16));
	else
		_pawnColor[_playerTurn].move(sf::Vector2f(-68, -36));
	_pawns.push_back(_pawnColor[_playerTurn]);
	_playerTurn = !_playerTurn;
}