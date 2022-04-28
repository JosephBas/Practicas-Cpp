#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tilemap.hpp"

//////////////////////////////////
//	Generador de laberintos		//
//	Algoritmo:					//
//		Recursive Backtracker	//
//////////////////////////////////
/*
	|
*/

int main(int argc, char const *argv[])
{
	// Crea la Ventana.
	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML");

	// Limita la taza de frames por segundo.
	window.setFramerateLimit(60);

	// Carga Textura.
	sf::Texture tileSet;
	if (!tileSet.loadFromFile("resources/maze-tileset.png"))
		std::cerr << "No se encontró el Archivo";

	// Crea el Tilemap.
	Tilemap map(sf::Vector2f(20,20), &tileSet, sf::Vector2f(8,8));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Actualiza el Tilemap.

		// Dibuja el Tilemap en pantalla.
		window.clear(sf::Color(0xFF0000FF));
		window.draw(map);
		window.display();
	}
	return 0;
}