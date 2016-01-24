#pragma once
#include "Model.h"
#include "GameEngine.h"
#include "Arbiter.h"
#include "InGameHUD.h"

class Grid;

class PVPModel :
	public Model
{
private:

	sf::FloatRect _gridBackgroundRect;
	sf::Vector2f _squareSize;
	Grid *_grid;

	enum Player
	{
		BLACK,
		WHITE
	};

	Grid::PlayerColor _currentPlayerColor;
	Player _currentPlayer;
	bool _winningStates[2];
	char _lastWinningPawn[2][2];
	
	bool _isGameFinished;

	char _currentTurnNumber;

	sf::Texture _pawnsTexture[2];
	sf::Sprite _pawnsSprites[2];
	sf::Texture _gridBackgroundTexture;
	sf::Sprite _gridBackground;
	sf::Texture _backgroundTexture;
	sf::Sprite _background;

	sf::Font _font;
	sf::Text _blackWinningText;
	sf::Text _whiteWinningText;

	InGameHUD *_HUD;

	sf::RenderWindow *_window;
	EventManager **_eventManagerAddr;
	Arbiter _arbiter;

public:
	PVPModel(sf::RenderWindow *, EventManager **);
	~PVPModel() {};
	void Display(sf::RenderWindow *window);
	bool Clicked(float x, float y);
	void ChangePlayerTurn();
	bool BackToMenu();
	void SettingHUD();
};

