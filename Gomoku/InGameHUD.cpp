#include "InGameHUD.h"

/* A VOMIR BLURPS */

const sf::Vector2f InGameHUD::PawnsCapturedWhiteFieldPosition((1280 - 800) / 2 + 800 + 2, 0.f);
const sf::Vector2f InGameHUD::PawnsCapturedBlackFieldPosition((1280 - 800) / 2 + 800 + 2, 40.f);
const sf::Vector2f InGameHUD::PawnsLeftWhiteFieldPosition((1280 - 800) / 2 + 800 + 2, 80.f);
const sf::Vector2f InGameHUD::PawnsLeftBlackFieldPosition((1280 - 800) / 2 + 800 + 2, 120.f);
const sf::Vector2f InGameHUD::CurrentTurnNumberFieldPosition(2.f, 0.f);
	
InGameHUD::InGameHUD(char pawnsCaptured[2], char pawnsLeft[2], char currentTurnNumber)
{
	/* SETTING CONTENT AND POSITION OF FIELDS */

	pawnsCapturedFields[1] = new InGameHUDField("White Pawns Captured", pawnsCaptured[1], PawnsCapturedWhiteFieldPosition);
	pawnsCapturedFields[0] = new InGameHUDField("Black Pawns Captured", pawnsCaptured[0], PawnsCapturedBlackFieldPosition);
	pawnsLeftFields[1] = new InGameHUDField("White Pawns Left", pawnsLeft[1], PawnsLeftWhiteFieldPosition);
	pawnsLeftFields[0] = new InGameHUDField("Black Pawns Left", pawnsLeft[0], PawnsLeftBlackFieldPosition);
	currentTurnNumberField = new InGameHUDField("Current Turn", currentTurnNumber, CurrentTurnNumberFieldPosition);
}

InGameHUD::~InGameHUD()
{
}

void InGameHUD::Display(sf::RenderWindow *window)
{
	pawnsCapturedFields[0]->Display(window);
	pawnsCapturedFields[1]->Display(window);
	pawnsLeftFields[0]->Display(window);
	pawnsLeftFields[1]->Display(window);
	currentTurnNumberField->Display(window);
}

void InGameHUD::setCapturedPawnsField(char player, char value)
{
	pawnsCapturedFields[player]->setFieldContent(value);
}

void InGameHUD::setPawnsLeftField(char player, char value)
{
	pawnsLeftFields[player]->setFieldContent(value);
}

void InGameHUD::setCurrentTurnNumberField(char value)
{
	currentTurnNumberField->setFieldContent(value);
}
