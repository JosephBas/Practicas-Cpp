#include "Tree.hpp"
/**
 * @author Javier Lozano
 * Contact: https://github.com/JosephBas
 */
int main(int argc, char const *argv[])
{
	Tree<int> generalTree(50);
	generalTree.Add(50, 0);
	generalTree.Add(0, 20);
	generalTree.Add(20, 20); // Invalid Addition : Duplicate Value
	generalTree.Add(20, 100);
	generalTree.Add(20, 200);
	generalTree.Add(20, 300);
	generalTree.Trace();
	return 0;
}
