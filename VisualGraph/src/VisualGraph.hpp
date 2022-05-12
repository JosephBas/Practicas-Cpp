#if !defined(VISUAL_GRAPH_HPP)
#define VISUAL_GRAPH_HPP

#include <SFML/Graphics.hpp>

class VisualGraph
{
public:
	// Constructor
	VisualGraph(int width, int height);
	// Destructor
	~VisualGraph();

	// Run Visual Graph
	void run();

	// Views

	sf::View mainLayer;
	sf::View foreLayer;

	// Node Shape
	static sf::CircleShape	s_nodeShape;
	static sf::Text			s_nodeText;

private:
	sf::RenderWindow m_window;
};

#endif // VISUAL_GRAPH_HPP
