#include <iostream>
#include <vector>
#include "../../K2d_tree.hpp"
#include "../../Point2d.hpp"


int main(int argc, char* argv[])
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(2,1));
	vec.push_back(Point2d(1,0));
	vec.push_back(Point2d(3,-5));
	vec.push_back(Point2d(-1,2));
	vec.push_back(Point2d(4,-3));
	K2d_tree tree(vec);
	K2d_tree::tree_iterator it = tree.begin();
	std::cout << "root : value :" << it.getSplitValue() << "\n";
	std::cout << "root : coord :" << it.getSplitCoord() << "\n";
	std::cout << "Has left child ? " << it.hasLeftChild() <<"\n"; 
	std::cout << "---------------------\n";
	
	it.goLeftChild();
	std::cout << "Is it an internal node? " << it.isInternalNode() << "\n"; 
	std::cout << " value :" << it.getSplitValue() << "\n";
	std::cout << " coord :" << it.getSplitCoord() << "\n";
	std::cout << "Has left child ? " << it.hasLeftChild() <<"\n"; 
	std::cout << "---------------------\n";
	
	it.goLeftChild();
	std::cout << "Is it an internal node?" << it.isInternalNode() << "\n";
	std::cout << " value :" << it.getSplitValue() << "\n";
	std::cout << " coord :" << it.getSplitCoord() << "\n";
	std::cout << "Has left child ? " << it.hasLeftChild() <<"\n"; 
	std::cout << "---------------------\n";
	
	it.goLeftChild();
	std::cout << "Is it an internal node?" << it.isInternalNode() << "\n";	
	std::cout << " value :" << it.getSplitValue() << "\n";
	std::cout << " coord :" << it.getSplitCoord() << "\n";
	std::cout << "Has left child ? " << it.hasLeftChild() <<"\n"; 

}