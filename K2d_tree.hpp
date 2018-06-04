/**
 *   Purpose: To implement algorithms that are using this class. It is a balanced binary search tree with the 
 *   data on the leaves. 
 * 
 * 
 * 
 */

#ifndef K2D_TREEDEF
#define K2D_TREEDEF

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include "Point2d.hpp"

/**
 *   auxiliary functions that are used for sorting
 */
bool comp_func_by_x(Point2d a, Point2d b) { return a.GetX() < b.GetX(); }
bool comp_func_by_y(Point2d a, Point2d b) { return a.GetY() < b.GetY(); }



class K2d_tree{
	struct Node{
		Node* left;
		Node* right;
		int split_coord; // 1 for x coordinate , 2 for y coordinate, 0if it is a leaf
		double split_val;
		bool is_leaf;
		Point2d data_leaf;
	};
private:	
	Node* root;
	std::vector<Point2d> sort_by_x;// the points of the tree sorted by x
	std::vector<Point2d> sort_by_y;// the points of the tree sorted by y

	
	Node* BuildTree(int split, std::vector<Point2d> points_by_x, std::vector<Point2d> points_by_y)
	{
		assert(points_by_x.size() == points_by_y.size());
		int siz = points_by_x.size();
		std::vector<Point2d> left_by_x;
		std::vector<Point2d> left_by_y;
		std::vector<Point2d> right_by_x;
		std::vector<Point2d> right_by_y;
		Node* nod = new Node;
		if( points_by_x.size() == 0)
		{
			delete nod;
			return 0;
		}else if(points_by_x.size() == 1)
		{
			nod->left = 0;
			nod->right = 0;
			nod->split_coord = 0;
			nod->split_val = 0;
			nod->is_leaf = true;
			nod->data_leaf = points_by_x[0];
			return nod;
		}else
		{
			if(split%2 == 1)
			{
				//then we split by x coordinate
				
				int index_median = ceil(siz/2.0)-1;
				for(int i = 0; i < siz; i++)
				{
					if( i <= index_median )
					{
						left_by_x.push_back(points_by_x[i]);
					}else
					{
						right_by_x.push_back(points_by_x[i]);
					}
					if( points_by_y[i].GetX() <= points_by_x[index_median].GetX() )
					{
						left_by_y.push_back(points_by_y[i]);
					}else
					{
						right_by_y.push_back(points_by_y[i]);
					}
				}
				
				nod->left = BuildTree(split+1,left_by_x,left_by_y);
				nod->right = BuildTree(split+1,right_by_x,right_by_y);
				nod->split_coord = 1;
				nod->split_val = points_by_x[index_median].GetX();
				nod->is_leaf = false;
				return nod;
			}else
			{
				//then we split by y coordinate
				
				int index_median = ceil(siz/2.0)-1;
				for(int i = 0; i < siz; i++)
				{
					if( i <= index_median )
					{
						left_by_y.push_back(points_by_y[i]);
					}else
					{
						right_by_y.push_back(points_by_y[i]);
					}
					if( points_by_x[i].GetY() <= points_by_y[index_median].GetY() )
					{
						left_by_x.push_back(points_by_x[i]);
					}else
					{
						right_by_x.push_back(points_by_x[i]);
					}
				}
				
				nod->left = BuildTree(split+1,left_by_x,left_by_y);
				nod->right = BuildTree(split+1,right_by_x,right_by_y);
				nod->split_coord = 2;
				nod->split_val = points_by_y[index_median].GetY();
				nod->is_leaf = false;
				return nod;
			}
		}
	}
	
	/**
	 *  The below is a auxiliary function for the deletion of all the nodes 
	 *  of the  tree
	 */
	std::vector<Node*> getAllNodes(Node* node)
	{
		std::vector<Node*> vec;
		vec.push_back(node);
		if( node->left != 0 )
		{
			std::vector<Node*> vec_left = getAllNodes(node->left);
			for(std::vector<Node*>::iterator it = vec_left.begin(); it != vec_left.end(); it++)
			{
				vec.push_back(*it);
			}
		}
		if( node->right != 0 )
		{
			std::vector<Node*> vec_right = getAllNodes(node->right);
			for(std::vector<Node*>::iterator it = vec_right.begin(); it != vec_right.end(); it++)
			{
				vec.push_back(*it);
			}
		}
		return vec;
	}
	
	
public:
	
	class tree_iterator{
		private:
			Node* p;
		public:
			tree_iterator(){p=0;}
			tree_iterator(Node* x){p=x;}
			tree_iterator(const tree_iterator& other_it) {p = other_it.p;}
			
			bool operator==(const tree_iterator& other_it) const {return p == other_it.p ;}
			bool operator!=(const tree_iterator& other_it) const {return p != other_it.p;}
			tree_iterator& operator=(const tree_iterator& other_ch_it){p = other_ch_it.p; return *this;}
			double getSplitValue(){return p->split_val;}// the median of the set by x or y, it depends on the split_val
			int getSplitCoord(){return p->split_coord;}//returns 1 for x coordinate and 2 for y coordinate
			bool hasRightChild(){return p->right != 0;}
			bool hasLeftChild(){return p->left != 0;}
			bool hasChildren(){return (p->right != 0) || (p->left != 0);}
			tree_iterator getLeftChild(){return tree_iterator(p->left);}
			tree_iterator getRightChild(){return tree_iterator(p->right);}
			void goRightChild() {p = p->right;} 
			void goLeftChild() {p = p->left;}
			bool isInternalNode(){return !(p->is_leaf);}
			Point2d getLeafPoint(){return p->data_leaf;}
			
			

	
		
	};
	
	
	/**
	 *  This method returns all the leaf via transverse all the nodes 
	 *  and get the leaves.
	 * 
	 */
	static std::vector<Point2d> getAllPoints(tree_iterator it_node)
	{
		std::vector<Point2d> leaves;
		if(!it_node.isInternalNode())
		{
			leaves.push_back(it_node.getLeafPoint());
			return leaves;
		}
		std::vector<Point2d> left = getAllPoints(it_node.getLeftChild());
		std::vector<Point2d> right = getAllPoints(it_node.getRightChild());
		for(std::vector<Point2d>::iterator it = left.begin(); it != left.end(); it++)
		{
			leaves.push_back(*it);
		}
		for(std::vector<Point2d>::iterator it = right.begin(); it != right.end(); it++)
		{
			leaves.push_back(*it);
		}
		return leaves;
	}
	
	
	K2d_tree(std::vector<Point2d> points)
	{
		// here must do the sort of points and call the Buildtree 
		std::sort (points.begin(), points.end(), comp_func_by_x);
		sort_by_x = points;
		std::sort (points.begin(), points.end(), comp_func_by_y);
		sort_by_y= points;
		root = BuildTree(1,sort_by_x,sort_by_y);
	}
	
	
	tree_iterator begin() const
	{
		assert(root!=0);
		return tree_iterator(root);
	}
	
	
	void addPoint(const Point2d poi) 
	{
		//firtst step we have to destroy all the old nodes
		std::vector<Node*> nodes = getAllNodes(root);
		for(std::vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++)
		{
			delete *it;
		}
		
		//second step : we have to add to the sort_by_x and sort_by_y the new point 
		for(std::vector<Point2d>::iterator it = sort_by_x.begin(); it != sort_by_x.end(); it++)
		{
			if( poi.GetX() <= (*it).GetX() )
			{
				sort_by_x.insert(it,poi);
			}
		}
		for(std::vector<Point2d>::iterator it = sort_by_y.begin(); it != sort_by_y.end(); it++)
		{
			if( poi.GetY() <= (*it).GetY() )
			{
				sort_by_y.insert(it,poi);
			}
		}
		
		//third step rebuild the tree with the calling of the BuildTree
		root = BuildTree(1,sort_by_x,sort_by_y);
	}
	
	
};

	

#endif