#pragma once
#include "Model.h"
#include "GameEngine.h"

class PVPModel :
	public Model
{
private:
	//const static unsigned int _gridBackgroundSize = 800;

	sf::IntRect _gridBackgroundRect;
	std::vector<std::string> _grid;
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
	PVPModel(sf::RenderWindow *, EventManager **);
	~PVPModel();
	void Display(sf::RenderWindow *window);
	bool Clicked(float x, float y);
};

