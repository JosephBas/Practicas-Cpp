#include "VisualGraph.hpp"
#include "Resources.hpp"

// Constructor
VisualGraph::VisualGraph(int width, int height)
{
	//////////////////////////////
	// Initialize Resources
	Resources::Initialize();

	//////////////////////////////
	// Init Text
	s_nodeText.setFont(Resources::font);
	s_nodeText.setString("Texto");
	s_nodeText.setFillColor(sf::Color::Red);

	//////////////////////////////
	// Initialize SFML Window
	m_window.create(sf::VideoMode(width, height), "VisualGraph");
	m_window.setFramerateLimit(60);

	foreLayer.setViewport(sf::FloatRect(0.25f, 0.25f, 0.5f,0.5f));
}

// Destructor
VisualGraph::~VisualGraph()
{

}

// Run Visual Graph
void VisualGraph::run()
{
	bool viewFlag = false;
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			viewFlag = !viewFlag;
		}
		m_window.clear();
		m_window.draw(s_nodeShape);
		if (viewFlag)
		{
			m_window.setView(foreLayer);
		}
		m_window.draw(s_nodeText);
		m_window.setView(m_window.getDefaultView());
		m_window.display();
	}
}

// Static Member Definition
sf::CircleShape	VisualGraph::s_nodeShape(10);
sf::Text		VisualGraph::s_nodeText;	