#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#define FIELD_TEXT_COLOR = sf::Color::Black

class InGameHUDField
{
private:
	sf::Text labelContent;
	sf::Text fieldContent;
	sf::Vector2f FieldPosition;
	sf::Font textFont;

	static const int FieldFontSize = 15;

public:
	InGameHUDField(std::string labelContent, char fieldContentValue, sf::Vector2f fieldPosition);
	~InGameHUDField();

	void setLabelContent(std::string labelContent);
	void setFieldContent(char value);

	void Display(sf::RenderWindow *window);
};

