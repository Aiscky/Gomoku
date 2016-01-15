#include "PVPEventManager.h"

PVPEventManager::PVPEventManager(EventManager **eventManagerAddr, sf::RenderWindow *window)
{
	_eventManagerAddr = eventManagerAddr;
	_window = window;
	_model = new PVPModel();
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
				exit(EXIT_SUCCESS);
				break;
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			switch (event.mouseButton.button)
			{
			case sf::Mouse::Left:
				std::cout << "MouseLeftButtonClicked" << std::endl;
				break;
			}
		}
		_model->Display(_window);
	}

	return false;
}
