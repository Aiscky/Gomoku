#pragma once

#include "Model.h"
#include "EventManager.h"
#include "GameEngine.h"

#include <iostream>
#include <vector>
#include <Windows.h>

class PlayerVsAIModel : public Model
{

private:
	const static unsigned int squareNumber = 19;

	sf::FloatRect _gridBackgroundRect;
	char _grid[squareNumber][squareNumber];
	sf::Vector2f _squareSize;

	bool _playerTurn;
	bool _winningStates[2];
	char _playersPawnsLeft[2];

	sf::Texture _pawnsTexture[2];
	sf::Sprite _pawnsSprites[2];
	sf::Texture _gridBackgroundTexture;
	sf::Sprite _gridBackground;

	sf::RenderWindow *_window;
	EventManager **_eventManagerAddr;

public:
	PlayerVsAIModel(sf::RenderWindow *, EventManager **);
	~PlayerVsAIModel() {};
	void Display(sf::RenderWindow *window);
	bool Clicked(float x, float y);
};