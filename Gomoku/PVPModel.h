#pragma once
#include "Model.h"
#include "GameEngine.h"
#include "Arbiter.h"

class Grid;

class PVPModel :
	public Model
{
private:

	sf::FloatRect _gridBackgroundRect;
	sf::Vector2f _squareSize;

	Grid *_grid;

	Grid::PlayerColor _playerTurn;
	bool _winningStates[2];

	sf::Texture _pawnsTexture[2];
	sf::Sprite _pawnsSprites[2];
	sf::Texture _gridBackgroundTexture;
	sf::Sprite _gridBackground;

	sf::RenderWindow *_window;
	EventManager **_eventManagerAddr;

public:
	PVPModel(sf::RenderWindow *, EventManager **);
	~PVPModel() {};
	void Display(sf::RenderWindow *window);
	bool Clicked(float x, float y);
	bool BackToMenu();
};

