#include "Tilemap.hpp"

Tilemap::Tilemap(sf::Vector2f map_size, sf::Texture * texture, sf::Vector2f cell_size) : m_CellSize(cell_size)
{
    // Inicializa Nodo Raiz en posicion 0,0
    m_Root = new Node<sf::Vector2f>(sf::Vector2f(0,0));
    m_Root->leafs.push_back(new Node<sf::Vector2f>(sf::Vector2f(2,2)));
    m_Root->leafs[0]->leafs.push_back(new Node<sf::Vector2f>(sf::Vector2f(2,3)));
    m_Root->leafs[0]->leafs[0]->walls = (NORTH + SOUTH);

    // Recorta los Tiles a partir de la Textura
    for (int rows = 0; rows < texture->getSize().y / cell_size.y; rows++)
    {
        for (int columns = 0; columns < texture->getSize().x / cell_size.x; columns++)
        {
            m_Tiles.push_back(sf::Sprite(*texture, sf::IntRect(columns * cell_size.x, rows * cell_size.y, cell_size.x, cell_size.y)));
        }
    }
}

Tilemap::~Tilemap()
{
    // Libera Nodo raiz
    delete m_Root;
}

std::vector<sf::Sprite>& Tilemap::getTiles()
{
    return m_Tiles;
}

void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    drawNodes(m_Root, target, states.transform);
}


void Tilemap::drawNodes(Node<sf::Vector2f> * node, sf::RenderTarget& target, sf::Transform& t) const
{
    if (node == nullptr)
        return;
    t.translate(sf::Vector2f(node->value.x * m_CellSize.x, node->value.y * m_CellSize.y));
    target.draw(m_Tiles[node->walls], t);
    // Node Position: transform.translate(node->value)
    // Draw Node: target.draw(m_Tiles[node->walls], transform);
    std::cout << "North " << (node->walls & NORTH) << "\nEast " << (node->walls & EAST) << "\nSouth" << (node->walls & SOUTH) << "\nWest" << (node->walls & WEST) << std::endl;
    for(auto && i : node->leafs)
    {
        drawNodes(i, target, t);
    }
}