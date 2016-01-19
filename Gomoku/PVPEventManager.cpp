#include "PVPEventManager.h"

PVPEventManager::PVPEventManager(EventManager **eventManagerAddr, sf::RenderWindow *window)
{
	_eventManagerAddr = eventManagerAddr;
	_window = window;
	_model = new PVPModel(window, eventManagerAddr);
	_model->Display(window);
}

PVPEventManager::~PVPEventManager()
{

}

bool PVPEventManager::HandleEvent()
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
			case sf::Keyboard::Escape:
				((PVPModel *)this->_model)->BackToMenu();
				return true;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			switch (event.mouseButton.button)
			{
			case sf::Mouse::Left:
				((PVPModel*)_model)->Clicked(event.mouseButton.x, event.mouseButton.y);
				_model->Display(_window);
				break;
			}
		}
	}

	return false;
}
