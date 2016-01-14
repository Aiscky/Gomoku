#include "MenuModel.h"

void MenuModel::Init()
{
	_buttonList.push_back(new ExitButton(_window));
	_buttonList.push_back(new PlayerVsPlayerButton(_eventManagerAddr, _window));
	_buttonList.push_back(new PlayerVsIAButton(_eventManagerAddr, _window));
}

MenuModel::MenuModel(sf::RenderWindow *window, EventManager **eventManager)
{
	this->_eventManagerAddr = eventManager;
	this->_window = window;
	this->_index = 0;

	this->Init();
}

MenuModel::~MenuModel()
{

}

void MenuModel::Display(sf::RenderWindow *window)
{
	_window->clear();
	OutputDebugString("Display function\n");
	for (size_t i = 0; i != _buttonList.size(); i++)
	{
		OutputDebugString("Iteration display loop\n");
		_buttonList[i]->Display(window);
	}
	_window->display();
	return;
}

void MenuModel::GoPrevious()
{
	this->_buttonList[_index]->setButtonIdle();
	if (_index == 0)
		_index = _buttonList.size() - 1;
	else
		_index -= 1;
	this->_buttonList[_index]->setButtonActive();
	if (this->_buttonList[_index]->_isEnabled)
	{
		this->GoPrevious();
	}
}

void MenuModel::GoNext()
{
	this->_buttonList[_index]->setButtonIdle();
	if (_index == _buttonList.size() - 1)
		_index = 0;
	else
		_index += 1;
	this->_buttonList[_index]->setButtonActive();
	if (this->_buttonList[_index]->_isEnabled)
	{
		this->GoNext();
	}
}

void MenuModel::Execute()
{
	this->_buttonList[_index]->ButtonPressed();
}
