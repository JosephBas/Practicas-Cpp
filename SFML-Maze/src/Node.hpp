#if !defined(NODE_HPP)
#define NODE_HPP

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Constants.hpp"

/**
 * @brief Nodo de una estructura de Arbol.
 * 
 * @tparam T Valor
 */
template <typename T>
struct Node
{
    // Inicializamos todos los nodos con su valor
    Node(T value) : value(value)
    {
        // El nodo tiene 4 paredes por defecto.
        walls = ALL;
    }

    ~Node()
    {
        // Iteramos el contenedor del Nodo
        for (int i = 0; i < leafs.size(); i++)
        {
            // Liberamos la memoria
            delete leafs[i];
        }
        std::cout << "Nodo Liberado" << std::endl;
    }

    T value;    // Valor inherente al Nodo
    int walls;  // El nodo representa una celda del Mapa de Tiles
    std::vector<Node*> leafs;   // Nodos hijos
};


#endif // NODE_HPP
