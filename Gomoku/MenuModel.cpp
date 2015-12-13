#include "MenuModel.h"



void MenuModel::Init()
{
	buttonList.push_back(new ExitButton(_window));
}

MenuModel::MenuModel(sf::RenderWindow *window, EventManager **eventManager)
{
	this->_eventManagerAddr = eventManager;
	this->_window = window;
	this->Init();
}

MenuModel::~MenuModel()
{

}

void MenuModel::Display(sf::RenderWindow *window)
{
	for (size_t i = 0; i != buttonList.size(); i++)
	{
		buttonList[i]->Display();
	}
	return;
}