#pragma once

#include "Model.h"
#include "Button.h"
#include "EventManager.h"
#include "ExitButton.h"
#include "PlayerVsAIButton.h"
#include "PlayerVSPlayerButton.h"

#include <iostream>
#include <vector>
#include <Windows.h>

class MenuModel : public Model
{

private:
	std::vector<Button *> _buttonList;
	EventManager **_eventManagerAddr;
	sf::RenderWindow *_window;
	unsigned int _index;
	
public:
	MenuModel(sf::RenderWindow *window, EventManager **eventManager);
	virtual ~MenuModel() {};
	virtual void Display(sf::RenderWindow *);
	void Init();
	void GoPrevious();
	void GoNext();
	void Execute();
};