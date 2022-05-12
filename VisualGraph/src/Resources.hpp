#if !defined(RESOURCES_HPP)
#define RESOURCES_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

struct Resources
{
	// Initializer
	static void Initialize();
	// Static Members
	static sf::Font font;
};

void Resources::Initialize()
{
	if (!Resources::font.loadFromFile("resources/Roboto-Regular.ttf"))
		std::cerr << "Font not Found!";
}

// Definition
sf::Font Resources::font;

#endif // RESOURCES_HPP
