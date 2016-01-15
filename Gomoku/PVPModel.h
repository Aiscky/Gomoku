#pragma once
#include "Model.h"
#include "GameEngine.h"

class PVPModel :
	public Model
{
private:
	std::vector<std::string> _grid;
	bool _playerTurn;
	bool _winningStates[2];
	char _playersPawnsLeft[2];
	//sf::Sprite _blackPawn
	//sf::Sprite _whitePawn
	sf::Texture _gridBackgroundTexture;
	sf::Sprite _gridBackground;

public:
	PVPModel();
	~PVPModel();
	void Display(sf::RenderWindow *window);
	bool CheckPlayable(sf::Vector2f);
};

