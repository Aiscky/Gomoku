#include "InGameHUD.h"

/* A VOMIR BLURPS */

const sf::Vector2f InGameHUD::PairsCapturedWhiteFieldPosition((1280 - 800) / 2 + 800 + 2, 0.f);
const sf::Vector2f InGameHUD::PairsCapturedBlackFieldPosition((1280 - 800) / 2 + 800 + 2, 40.f);
const sf::Vector2f InGameHUD::PawnsLeftWhiteFieldPosition((1280 - 800) / 2 + 800 + 2, 80.f);
const sf::Vector2f InGameHUD::PawnsLeftBlackFieldPosition((1280 - 800) / 2 + 800 + 2, 120.f);
const sf::Vector2f InGameHUD::CurrentTurnNumberFieldPosition(2.f, 0.f);
	
InGameHUD::InGameHUD(char pairsCaptured[2], char pawnsLeft[2], char currentTurnNumber)
{
	/* SETTING CONTENT AND POSITION OF FIELDS */

	pairsCapturedFields[1] = new InGameHUDField("White Pawns Captured", 2 * pairsCaptured[1], PairsCapturedWhiteFieldPosition);
	pairsCapturedFields[0] = new InGameHUDField("Black Pawns Captured", 2 * pairsCaptured[0], PairsCapturedBlackFieldPosition);
	pawnsLeftFields[1] = new InGameHUDField("White Pawns Left", pawnsLeft[1], PawnsLeftWhiteFieldPosition);
	pawnsLeftFields[0] = new InGameHUDField("Black Pawns Left", pawnsLeft[0], PawnsLeftBlackFieldPosition);
	currentTurnNumberField = new InGameHUDField("Current Turn", currentTurnNumber, CurrentTurnNumberFieldPosition);
}

InGameHUD::~InGameHUD()
{
}

void InGameHUD::Display(sf::RenderWindow *window)
{
	pairsCapturedFields[0]->Display(window);
	pairsCapturedFields[1]->Display(window);
	pawnsLeftFields[0]->Display(window);
	pawnsLeftFields[1]->Display(window);
	currentTurnNumberField->Display(window);
}

void InGameHUD::setPairsField(char player, char value)
{
	pairsCapturedFields[player]->setFieldContent(value);
}

void InGameHUD::setPawnsLeftField(char player, char value)
{
	pawnsLeftFields[player]->setFieldContent(value);
}

void InGameHUD::setCurrentTurnNumberField(char value)
{
	currentTurnNumberField->setFieldContent(value);
}
