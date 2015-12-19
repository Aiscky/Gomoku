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
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				((MenuModel *)this->_model)->GoPrevious();
				break;
			case sf::Keyboard::Down:
				((MenuModel *)this->_model)->GoNext();
				break;
			case sf::Keyboard::Space:
				((MenuModel *)this->_model)->Execute();
				break;
			case sf::Keyboard::Escape:
				exit(EXIT_SUCCESS);
				break;
			}
		}
		_model->Display(_window);
	}

	return false;
}
