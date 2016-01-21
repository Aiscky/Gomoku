#pragma once

#include "InGameHUDField.h"

class InGameHUD
{
private:
	InGameHUDField pairsCapturedFields[2];
	InGameHUDField pawnsLeftFields[2];
	InGameHUDField currentTurnNumber;

public:
	InGameHUD();
	~InGameHUD();
	void Display(sf::RenderWindow *window, );
};

