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
 *  An auxiliary function that is used for sorting
 */
bool comp_func_by_x(Point2d a, Point2d b) { return a.GetX() < b.GetX(); }
bool comp_func_by_y(Point2d a, Point2d b) { return a.GetY() < b.GetY(); }



class K2d_tree{
	struct Node{
		Node* left;
		Node* right;
		int split_coord; // 1 for x coordinate , 2 for y coordinate
		double split_val;
		bool is_leaf;
		Point2d data_leaf;
	};
private:	
	Node* root;
	
	
	Node* BuildTree(int split, std::vector<Point2d> points, std::vector<Point2d> by_x, std::vector<Point2d> by_y)
	{
		Node* nod = new Node;
		if( points.size() == 1 )
		{
			nod->left = 0;
			nod->right = 0;
			nod->split_val = 0;
			nod->is_leaf = true;
			nod->data_leaf = points[0];
			return nod;
		}else
		{
			if( split%2 == 1)
			{
				// then we split vector "points" by x
				
				std::vector<Point2d> temp;
				//temp should have the "points" in increasing order
				for( std::vector<Point2d>::iterator it1 = by_x.begin(); it1 != by_x.end(); it1++)
				{
					for( std::vector<Point2d>::iterator it = points.begin(); it != points.end(); it++)
					{
						if( *it == *it1 )
						{
							temp.push_back(*it);
						}
					}
				}
				std::vector<Point2d> left;
				std::vector<Point2d> right;
				int size_temp = temp.size();
				int index_median = ceil(size_temp/2.0)-1;
				for(int i = 0; i < size_temp; i++)
				{
					if(i <= index_median)
					{
						left.push_back(temp[i]);
					}else
					{
						right.push_back(temp[i]);
					}
				}
				nod->left = BuildTree(split+1,left,by_x,by_y);
				nod->right = BuildTree(split+1,right,by_x,by_y);
				nod->split_coord = 1;
				nod->split_val = temp[index_median].GetX();
				nod->is_leaf = false;
				return nod;
			}else
			{
				// then we split vector "points" by y
				
				std::vector<Point2d> temp;
				//temp should have the "points" in increasing order
				for( std::vector<Point2d>::iterator it1 = by_y.begin(); it1 != by_y.end(); it1++)
				{
					for( std::vector<Point2d>::iterator it = points.begin(); it != points.end(); it++)
					{
						if( *it == *it1 )
						{
							temp.push_back(*it);
						}
					}
				}
				std::vector<Point2d> left;
				std::vector<Point2d> right;
				int size_temp = temp.size();
				int index_median = ceil(size_temp/2.0)-1;
				for(int i = 0; i < size_temp; i++)
				{
					if(i <= index_median)
					{
						left.push_back(temp[i]);
					}else
					{
						right.push_back(temp[i]);
					}
				}
				nod->left = BuildTree(split+1,left,by_x,by_y);
				nod->right = BuildTree(split+1,right,by_x,by_y);
				nod->split_coord = 2;
				nod->split_val = temp[index_median].GetY();
				nod->is_leaf = false;
				return nod;
			}
		}
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
			bool operator!=(const tree_iterator& other_it) const {return p!= other_it.p;}
			tree_iterator& operator=(const tree_iterator& other_ch_it){p = other_ch_it.p; return *this;}
			double getSplitValue(){return p->split_val;}// the median of the set by x or y, it depends on the split_val
			int getSplitCoord(){return p->split_coord;}//returns 1 for x coordinate and 2 for y coordinate
			bool hasRightChild(){return p->right != 0;}
			bool hasLeftChild(){return p->left != 0;}
			bool hasChildren(){return (p->right != 0) || (p->left != 0);}
			void goRightChild() {p = p->right;} 
			void goLeftChild() {p = p->left;}
			bool isInternalNode(){!p->is_leaf;}
	};
	
	
	
	K2d_tree(std::vector<Point2d> points)
	{
		// here must do the sort of points and call the Buildtree 
		std::sort (points.begin(), points.end(), comp_func_by_x);
		std::vector<Point2d> sort_by_x(points);
		std::sort (points.begin(), points.end(), comp_func_by_y);
		std::vector<Point2d> sort_by_y(points);
		root = BuildTree(1,points,sort_by_x,sort_by_y);
	}
	
	
	tree_iterator begin() const
	{
		assert(root!=0);
		return tree_iterator(root);
	}
	
	
	
};


#endif