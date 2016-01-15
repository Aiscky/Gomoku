#pragma once

#include "Model.h"
#include "EventManager.h"

#include <iostream>
#include <vector>
#include <Windows.h>

class PlayerVsAIModel : public Model
{

private:
	bool _playerTurn;
	sf::Texture _gridBackgroundTexture;
	sf::Sprite _gridBackground;
	sf::Texture _whiteTexture;
	sf::Texture _blackTexture;
	sf::Sprite _pawnColor[2];
	std::vector<sf::Sprite> _pawns;

	EventManager **_eventManagerAddr;
	sf::RenderWindow *_window;

public:
	PlayerVsAIModel(sf::RenderWindow *window, EventManager **eventManager);
	virtual ~PlayerVsAIModel() {};
	virtual void Display(sf::RenderWindow *);
	void Init();
	void Clicked(sf::Vector2i);
};