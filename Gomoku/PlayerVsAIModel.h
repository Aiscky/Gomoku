#pragma once

#include "Grid.h"
#include "AI.h"
#include "GameEngine.h"
#include "Arbiter.h"

class Grid;
class AI;

class PlayerVsAIModel : public Model
{

private:
	sf::FloatRect _gridBackgroundRect;
	sf::Vector2f _squareSize;

	bool _winningStates[2];
	char _playersPawnsLeft[2];
	Grid *_grid;
	AI *_bot;

	sf::Texture _pawnsTexture[2];
	sf::Sprite _pawnsSprites[2];
	sf::Texture _gridBackgroundTexture;
	sf::Sprite _gridBackground;

	sf::RenderWindow *_window;
	EventManager **_eventManagerAddr;
	Arbiter _arbiter;

public:
	PlayerVsAIModel(sf::RenderWindow *, EventManager **);
	~PlayerVsAIModel() {};
	void Display(sf::RenderWindow *window);
	bool Clicked(float x, float y);
	bool BackToMenu();
};