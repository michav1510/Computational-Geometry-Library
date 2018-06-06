#include <iostream>
#include <vector>
#include "../../K2d_tree.hpp"
#include "../../Point2d.hpp"



void testing_constructor()
{
	std::cout << "Start---Testing: (constructor) K2d_tree(std::vector<Point2d> )----------" << "\n\n";

	int cas = 1;
	while( cas <= 10)
	{
		if( cas == 1 )
		{
			std::vector<Point2d> vec;
			vec.push_back(Point2d(2,1));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(3,-5));
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(4,-3));
			K2d_tree tree(vec);
			K2d_tree::tree_iterator it = tree.begin();
			
			std::cout << " left child : " << it.hasLeftChild() << "\n";
			std::cout << " right child : " << it.hasRightChild() << "\n";
			std::cout << " split value : " << it.getSplitValue() << "\n";
			if( it.getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
			
			
			std::cout << " left child : " << it.getLeftChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getLeftChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getLeftChild().getSplitValue() << "\n";
			if( it.getLeftChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getLeftChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getLeftChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getLeftChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
			
			
			std::cout << " left child : " << it.getRightChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getRightChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getRightChild().getSplitValue() << "\n";
			if( it.getRightChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getRightChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getRightChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getRightChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
			
			
			std::cout << " left child : " << it.getLeftChild().getLeftChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getLeftChild().getLeftChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getLeftChild().getLeftChild().getSplitValue() << "\n";
			if( it.getLeftChild().getLeftChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getLeftChild().getLeftChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getLeftChild().getLeftChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getLeftChild().getLeftChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
			
			
			std::cout << " left child : " << it.getLeftChild().getRightChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getLeftChild().getRightChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getLeftChild().getRightChild().getSplitValue() << "\n";
			if( it.getLeftChild().getRightChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getLeftChild().getRightChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getLeftChild().getRightChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getLeftChild().getRightChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
			
			
			std::cout << " left child : " << it.getRightChild().getLeftChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getRightChild().getLeftChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getRightChild().getLeftChild().getSplitValue() << "\n";
			if( it.getRightChild().getLeftChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getRightChild().getLeftChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getRightChild().getLeftChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getRightChild().getLeftChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
			
			
			std::cout << " left child : " << it.getRightChild().getRightChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getRightChild().getRightChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getRightChild().getRightChild().getSplitValue() << "\n";
			if( it.getRightChild().getRightChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getRightChild().getRightChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getRightChild().getRightChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getRightChild().getRightChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
			
			
			std::cout << " left child : " << it.getLeftChild().getLeftChild().getLeftChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getLeftChild().getLeftChild().getLeftChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getLeftChild().getLeftChild().getLeftChild().getSplitValue() << "\n";
			if( it.getLeftChild().getLeftChild().getLeftChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getLeftChild().getLeftChild().getLeftChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getLeftChild().getLeftChild().getLeftChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getLeftChild().getLeftChild().getLeftChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";

			
			std::cout << " left child : " << it.getLeftChild().getLeftChild().getRightChild().hasLeftChild() << "\n";
			std::cout << " right child : " << it.getLeftChild().getLeftChild().getRightChild().hasRightChild() << "\n";
			std::cout << " split value : " << it.getLeftChild().getLeftChild().getRightChild().getSplitValue() << "\n";
			if( it.getLeftChild().getLeftChild().getRightChild().getSplitCoord() == 1 )
			{
				std::cout << " split coord : x\n"; 
			}else if( it.getLeftChild().getLeftChild().getRightChild().getSplitCoord() == 2 )
			{
				std::cout << " split coord : y\n"; 
			}else 
			{
				std::cout << " split coord : 0\n"; 
			}
			std::cout << " is leaf : " << !it.getLeftChild().getLeftChild().getRightChild().isInternalNode() << "\n";
			std::cout << " Point2d : " << it.getLeftChild().getLeftChild().getRightChild().getLeafPoint() << "\n"; 
			std::cout << "------------------------\n";
		}else if( cas == 2 )
		{
			
		}
		cas++;
	}
	
	std::cout << "End---Testing: (constructor) K2d_tree(std::vector<Point2d> )-----------" << "\n\n";
}



void testing_getAllPoints()
{
	std::cout << "Start---Testing: static std::vector<Point2d> getAllPoints(tree_iterator )----------" << "\n\n";
	std::vector<Point2d> vec;
	vec.push_back(Point2d(2,1));
	vec.push_back(Point2d(1,0));
	vec.push_back(Point2d(3,-5));
	vec.push_back(Point2d(-1,2));
	vec.push_back(Point2d(4,-3));
	K2d_tree tree(vec);
	
	K2d_tree::tree_iterator it = tree.begin();
	std::vector<Point2d> vec_leaves = K2d_tree::getAllPoints(it);
	std::cout << "Below we see the leaves of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getLeftChild());
	std::cout << "Below we see the leaves of the left child of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	
		it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getLeftChild().getLeftChild());
	std::cout << "Below we see the leaves of the left-left child of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	
	it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getLeftChild().getLeftChild().getLeftChild());
	std::cout << "Below we see the leaves of the left-left-left child of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	
	it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getLeftChild().getLeftChild().getRightChild());
	std::cout << "Below we see the leaves of the left-left-right child of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getLeftChild().getRightChild());
	std::cout << "Below we see the leaves of the left-right of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	
	it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getRightChild());
	std::cout << "Below we see the leaves of the right child of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	
	it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getRightChild().getLeftChild());
	std::cout << "Below we see the leaves of the right-left child of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	
	it = tree.begin();
	vec_leaves = K2d_tree::getAllPoints(it.getRightChild().getRightChild());
	std::cout << "Below we see the leaves of the right-right child of the root\n";
	for(int i = 0; i < vec_leaves.size(); i++)
	{
		std::cout << " " << vec_leaves[i] << "\n" ;
	}
	
	std::cout << "End---Testing: static std::vector<Point2d> getAllPoints(tree_iterator )----------" << "\n\n";

}


void testing_addPoint()
{
	std::cout << "Start---Testing: getAllNodes----------" << "\n\n";
	std::vector<Point2d> vec;
	vec.push_back(Point2d(2,1));
	vec.push_back(Point2d(1,0));
	vec.push_back(Point2d(3,-5));
	vec.push_back(Point2d(-1,2));
	vec.push_back(Point2d(4,-3));
	K2d_tree tree(vec);
	tree.addPoint(Point2d(-2,-2));
	
	std::cout << "Start---Testing: getAllNodes----------" << "\n\n";
}

int main(int argc, char* argv[])
{
//	testing_constructor();
//	testing_getAllPoints();
	testing_addPoint();
}