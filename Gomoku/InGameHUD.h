#pragma once

#include "InGameHUDField.h"

class InGameHUD
{
private:
	InGameHUDField *pawnsCapturedFields[2];
	InGameHUDField *pawnsLeftFields[2];
	InGameHUDField *currentTurnNumberField;
	
	static const sf::Vector2f PawnsCapturedWhiteFieldPosition;
	static const sf::Vector2f PawnsCapturedBlackFieldPosition;
	static const sf::Vector2f PawnsLeftWhiteFieldPosition;
	static const sf::Vector2f PawnsLeftBlackFieldPosition;
	static const sf::Vector2f CurrentTurnNumberFieldPosition;

public:
	InGameHUD(char pairsCaptured[2], char pawnsLeft[2], char currentTurnNumber);
	~InGameHUD();
	void Display(sf::RenderWindow *window);
	void setCapturedPawnsField(char player, char value);
	void setPawnsLeftField(char player, char value);
	void setCurrentTurnNumberField(char value);
};

