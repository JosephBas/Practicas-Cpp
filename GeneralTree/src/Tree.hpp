#if !defined(TREE_HPP)
#define TREE_HPP

#include "Node.hpp"

template <typename T>
class Tree
{
public:
	Tree(T value)
	{
		// Initialize Root
		m_root = new Node<T>(value, nullptr);
		// Set size to 1
		m_size = 1;
	}

	~Tree()
	{
		// Free Root Node
		delete m_root;
	}

	Node<T> * Search(T value)
	{
		// Call Helper Function
		return Search(value, m_root);
	}

	Node<T> * Add(T search_value, T new_value)
	{
		// Serach for and existing Node
		Node<T> * parent = Search(search_value, m_root);

		// Search for a Node containing the new value
		Node<T> * check_node = Search(new_value, m_root);

		// If parent node exist and check node doesn't (to prevent duplicate values)
		if (parent != nullptr && check_node == nullptr)
		{
			// Instanciate a new node.
			Node<T> * new_node = new Node<T>(new_value, parent);

			// Add Node as leaf for the searched Node
			parent->leafs.emplace_back(new_node);

			// Increase Size by 1
			m_size++;
			
			//std::cout << "Node Added: " <<new_value.x << " , " << new_value.y << std::endl;
			// Return New Node pointer
			return new_node;
		}
		else
		{
			std::cout << "Invalid." << std::endl;
			// Return NULL
			return nullptr;
		}
	}

	void Remove(T value)
	{
		// Serach Node by Value
		Node<T> * node = Search(value, m_root);

		// If Node is not NULL...
		if (node != nullptr)
		{
			// Get Node number and substract from total
			m_size -= Count(node, 0);

			// If Parent Node is not NULL..
			if (node->parent != nullptr)
			{
				// Reference to Leaf vector
				std::vector<Node<T> *> & vec = node->parent->leafs;

				// Search for Node index on it's parent Leaf vector
				for (int i = 0; i < vec.size(); i++)
				{
					if (vec[i] == node)
						vec.erase(vec.begin() + i);
				}

				delete node;
			}
			else
			{
				// Node is Root: delete Root
				delete node;
			}
		}
	}

	void Trace()
	{
		Trace(m_root);
	}

	int Size()
	{
		return m_size;
	}

	Node<T> * GetRoot()
	{
		return m_root;
	}

private:
	Node <T> * m_root;
	int m_size;

	int Count(Node<T> * node, int counter)
	{
		// If Node is NULL return NULL
		if (node == nullptr)
			return counter;

		// Increase counter
		counter++;

		// For each leaf
		for (auto &&n : node->leafs)
		{
			// Count leaf nodes
			counter = Count(n, counter);
		}

		// Return final count
		return counter;
	}

	Node<T> * Search(T value, Node<T> * node)
	{
		// If Node is NULL return NULL
		if (node == nullptr)
			return nullptr;

		// If Value is found return Node
		if (value == node->value)
			return node;

		// Search value on every leaf
		for (auto &&n : node->leafs)
		{
			Node<T> * found = Search(value, n);
			// If Value is found return true
			if (found != nullptr)
				return found;
		}

		// If nothing was found return NULL
		return nullptr;
	}
	
	void Trace(Node<T> * node)
	{
		// If Node Parent is NULL then it's Root Node, print it's value
		if (node->parent == nullptr)
			std::cout << "Root ("<< node->value <<")" << std::endl;
		else // Print Parent's Value and then Node's Value
			std::cout << "Parent ("<< node->parent->value <<")\t-> Node (" << node->value << ")" << std::endl;

		// Trace Leaf Nodes
		for (auto &&n : node->leafs)
		{
			Trace(n);
		}
		
	}
};


#endif // TREE_HPP
