#pragma once

#include "Model.h"
#include "Button.h"
#include "EventManager.h"
#include "ExitButton.h"
#include "PlayerVsIAButton.h"
#include "PlayerVsIAButton.h"

#include <iostream>
#include <vector>

class MenuModel : public Model
{
private:
	std::vector<Button *> buttonList;
	EventManager **_eventManagerAddr;
	sf::RenderWindow *_window;
	void Init();
	
public:
	MenuModel(sf::RenderWindow *window, EventManager **eventManager);
	virtual ~MenuModel();
	virtual void Display(sf::RenderWindow *);
};