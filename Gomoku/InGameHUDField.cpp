#include "InGameHUDField.h"



InGameHUDField::InGameHUDField(std::string labelContent, char fieldContentValue, sf::Vector2f fieldPosition)
{
	if (!textFont.loadFromFile("Fonts/Track.TTF"))
	{
		char *error = (char *)malloc(265);

		strerror_s(error, 256, errno);
		std::cout << error << std::endl;
		exit(EXIT_FAILURE);
	}

	this->labelContent.setString(labelContent);
	this->labelContent.setFont(textFont);
	this->labelContent.setPosition(fieldPosition);
	this->labelContent.setCharacterSize(FieldFontSize);

	this->fieldContent.setString(std::to_string((int)fieldContentValue));
	this->fieldContent.setFont(textFont);
	this->fieldContent.setPosition(fieldPosition.x, fieldPosition.y + this->labelContent.getLocalBounds().height + 8.f);
	this->fieldContent.setCharacterSize(FieldFontSize);
}


InGameHUDField::~InGameHUDField()
{
}

void InGameHUDField::Display(sf::RenderWindow *window)
{
	window->draw(this->labelContent);
	window->draw(this->fieldContent);
}

void InGameHUDField::setLabelContent(std::string labelContent)
{
	this->labelContent.setString(labelContent);
}

void InGameHUDField::setFieldContent(char value)
{
	this->fieldContent.setString(std::to_string(value));
}

