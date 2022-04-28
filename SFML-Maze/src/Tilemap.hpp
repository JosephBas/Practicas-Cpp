#if !defined(TILEMAP_HPP)
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>
#include "Node.hpp"

/**
 * @brief Mapa de Tiles
 * 
 */
class Tilemap : public sf::Drawable, sf::Transformable
{
public:
	Tilemap(sf::Vector2f map_size, sf::Texture * texture, sf::Vector2f cell_size);
	~Tilemap();
	std::vector<sf::Sprite>& getTiles();
private:
	// Funcion virtual heredada de sf::Drawable
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void drawNodes(Node<sf::Vector2f> * node, sf::RenderTarget& target, sf::Transform& t) const;

	sf::Vector2f m_CellSize;			// Tamaño de las celdas
	std::vector<sf::Sprite> m_Tiles;	// Set de Tiles	
	Node<sf::Vector2f> * m_Root;		// Estructura que almacena la informacion de las celdas del mapa
	bool m_IsRunning;					// Bandera de control
};

#endif // TILEMAP_HPP
