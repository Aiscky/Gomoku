#pragma once
#include "Model.h"
#include "GameEngine.h"

class PVPModel :
	public Model
{
private:
	const static unsigned int _gridBackgroundSize = 800;

	std::vector<std::string> _grid;
	bool _playerTurn;
	bool _winningStates[2];
	char _playersPawnsLeft[2];
	std::vector<sf::Sprite*> _pawns;
	sf::Texture _gridBackgroundTexture;
	sf::Sprite _gridBackground;
	sf::RenderWindow *_window;
	EventManager **_eventManagerAddr;

public:
	PVPModel(sf::RenderWindow *, EventManager **);
	~PVPModel();
	void Display(sf::RenderWindow *window);
	bool CheckPlayable(float x, float y);
};

