#include "MenuEventManager.h"

MenuEventManager::MenuEventManager(sf::RenderWindow *window, EventManager **gameEngineAddr)
{
	_window = window;
	_model = new MenuModel(window, gameEngineAddr);
	_model->Display(window);
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
				return true;
			case sf::Keyboard::Escape:
				exit(EXIT_SUCCESS);
				break;
			}
		}
		if (event.type == sf::Event::MouseMoved)
		{
			if (event.mouseMove.x > 400 && event.mouseMove.x < 880 && event.mouseMove.y > 100 && event.mouseMove.y < 200)
			{
				((MenuModel *)this->_model)->moveCursor(0);
			}
			if (event.mouseMove.x > 380 && event.mouseMove.x < 900 && event.mouseMove.y > 320 && event.mouseMove.y < 420)
			{
				((MenuModel *)this->_model)->moveCursor(1);
			}
			if (event.mouseMove.x > 500 && event.mouseMove.x < 780 && event.mouseMove.y > 540 && event.mouseMove.y < 640)
			{
				((MenuModel *)this->_model)->moveCursor(2);
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			switch (event.mouseButton.button)
			{
			case sf::Mouse::Left:
				if (event.mouseButton.x > 400 && event.mouseButton.x < 880 && event.mouseButton.y > 100 && event.mouseButton.y < 200)
				{
					((MenuModel *)this->_model)->Execute(0);
					return (true);
				}
				if (event.mouseButton.x > 380 && event.mouseButton.x < 900 && event.mouseButton.y > 320 && event.mouseButton.y < 420)
				{
					((MenuModel *)this->_model)->Execute(1);
					return (true);
				}
				if (event.mouseButton.x > 500 && event.mouseButton.x < 780 && event.mouseButton.y > 540 && event.mouseButton.y < 640)
				{
					exit(EXIT_SUCCESS);
					break;
				}
			}
		}
	_model->Display(_window);
	}
	return false;
}
