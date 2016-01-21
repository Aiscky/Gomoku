#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class InGameHUDField
{
private:
	sf::Text labelContent;
	sf::Text fieldContent;

public:
	InGameHUDField();
	~InGameHUDField();

	void setFieldContent(std::string fieldContent);
	void setLabelContent(std::string labelContent);

	void Display(sf::RenderWindow *window);
};

