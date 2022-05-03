#if !defined(NODE_HPP)
#define NODE_HPP

#include <vector>
#include <iostream>

template <typename T>
struct Node
{
    Node(T value, Node * parent) : value(value), parent(parent) {}
    ~Node()
    {
        for (int i = 0; i < leafs.size(); i++)
        {
            leafs.pop_back();
        }
    }

    T value;
    Node * parent;
    std::vector<Node*> leafs;
};
#endif // NODE_HPP
