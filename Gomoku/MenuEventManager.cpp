#include "MenuEventManager.h"

MenuEventManager::MenuEventManager(sf::RenderWindow *window, EventManager **gameEngineAddr)
{
	_window = window;
	_model = new MenuModel(window, gameEngineAddr);
	_model->Display(window);
}


MenuEventManager::~MenuEventManager()
{
}

bool MenuEventManager::HandleEvent()
{
	sf::Event event;
	while ((*_window).pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			(*_window).close();
		_model->Display(_window);
	}

	return false;
}
