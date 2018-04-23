/**
    Purpose: To represent a convex hull of 2d points. It is a list with the vertices of a convex hull of 2d points. I 
    implemented it using a double linked cyclic list in order to read the points in clockwise order and counterclockwise
    order. The iterator I implemented is an iterator that keep the encapsulation and you can't change the list from the 
    iterator. The push(T elem) will add the (elem) into the list and at the right position if it is not interior to the
    current convex hull. So this class provide a unified way to read the points and to add a point keeping in mind that
    this list would represent a convex hul of 2d points, i.e you can't add a point to the list which is not a vertex of
    the convex hull.

    

    @author Chaviaras Michalis
    @version 1.1  2/2018 
*/
#ifndef CONVEXHULL2DDEF
#define CONVEXHULL2DDEF
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include "Point2d.hpp"
#include "Predicates.hpp"


class Convexhull2d{
	struct Node{
		Point2d data;
		Node* back;
		Node* front;
	};
private:
	Node* head;
	Node* tail;
	unsigned int my_size;
	double my_area;

	/**
	 * calculate the area of a triangle.
	 * Purpose :  It is an auxilliary function to be used in the function notify_area.
	 * Maybe it should be in another class as a static class.
	 * @param p1 A point of the triangle
	 * @param p2 A point of the triangle
	 * @param p3 A point of the triangle 
	 * @returns The area of the triangle consistute of the 3 points
	 */
	double area_of_triangle(const Point2d& p1, const Point2d& p2, const Point2d& p3)
	{
		double A_x = p1.GetX();
		double A_y = p1.GetY();
		double B_x = p2.GetX();
		double B_y = p2.GetY();
		double C_x = p3.GetX();
		double C_y = p3.GetY();
		return std::abs( (A_x*(B_y-C_y) + B_x*(C_y-A_y) + C_x*(A_y-B_y))/2.0 );
	}

	/**
	 * This method notify the area of the convex hull.
	 * Purpose : This method was made because of the time complexity of the notification of 
	 * the area which is O(size of convex hull), thus maybe in future edition we change it 
	 * in public in order to give to the user of this class to decide whether or not to notify 
	 * the area. In this way the user of this class can handle whether or not to pay this 
	 * linear time to notify the area.
	 */
	void notify_area ()
	{
		if(my_size == 0 || my_size == 1 || my_size == 2){
			my_area = 0;
		}else 
		{
			//in order to find the area of the convex hull we will divide it 
			//into triangles 
			
			// the below three iterators point to different nodes because
			// there are at least three nodes in the list
			Convexhull2d::ch_iterator it_clo_back = ch_iterator(head);
			Convexhull2d::ch_iterator it_clo_front = it_clo_back + 1;
			Convexhull2d::ch_iterator it_cou_clo = it_clo_back-1;
			
			// at the below variable we will keep the sum of the areas of 
			//every triangle
			double sum = 0;
			sum += area_of_triangle(*it_clo_back,*it_clo_front,*it_cou_clo);
			
			while(++it_clo_front != it_cou_clo)
			{
				it_clo_back++;
				sum += area_of_triangle(*it_clo_back,*it_clo_front,*it_cou_clo);
			}	
			my_area = sum;
		}
		
		
	}
public:
	class ch_iterator{
	private:
		const Node* p;		
	public:
		ch_iterator(){p=0;}
		ch_iterator(Node* x) { p = x; }
		ch_iterator(const ch_iterator& other_it) {p = other_it.p;}
		ch_iterator& operator++() {p = p->front; return *(this);} 
		ch_iterator operator++(int) {ch_iterator tmp(*(this)); operator++(); return tmp; }
		ch_iterator& operator--() {p = p->back; return *(this);}
		ch_iterator operator--(int) {ch_iterator tmp(*(this)); operator--(); return tmp; }
		bool operator==(const ch_iterator& other_it) const {return p == other_it.p ;}
		bool operator!=(const ch_iterator& other_it) const {return p!= other_it.p;}
		ch_iterator& operator=(const ch_iterator& other_ch_it){p = other_ch_it.p; return *this;}
		//the returned type below must remain Point2d instead of Point2d& because I don't want to change the data of the list
		// from the iterator
		Point2d operator*() const {return p->data;}
		ch_iterator operator+(const unsigned int num) const 
		{
			ch_iterator res;
			res.p = p;
			unsigned int count = 0;
			while(count != num)
			{
				res.p = res.p->front;
				count++;				
			}
			return res;
		}
		
		ch_iterator operator-(const unsigned int num) const 
		{
			ch_iterator res;
			res.p = p;
			unsigned int count = 0;
			while(count != num)
			{
				res.p = res.p->back;
				count++;				
			}
			return res;
		}
		
		
	};

	/**
	 *   Default Constructor
	 * 
	 */
	Convexhull2d() 
	{
		head = 0;
		tail = 0;
		my_size = 0;
		my_area = 0;
	}
	
	
	/**
	 *    Copy Constructor
	 *
	 *    @returns other_ch is the Convexhull2d that we make a copy of this.
	 */
	Convexhull2d(const Convexhull2d& other_ch)
	{
		if(other_ch.my_size > 0)
		{
			Convexhull2d::ch_iterator curr_it(other_ch.begin());
			Node* curr = new Node;
			curr->data = *curr_it;
			head = curr;
			Node* pre_curr = curr;
			while(++curr_it != other_ch.head)
			{
				curr = new Node;
				curr->data = *curr_it;
				pre_curr->front = curr;
				curr->back = pre_curr;
				pre_curr = curr;
			}
			curr->front = head;
			head->back = curr;
			tail = other_ch.tail;
			
			my_size = other_ch.my_size;
			my_area = other_ch.my_area;
		}else
		{
			head = 0;
			tail = 0;
			my_size = 0;
			my_area = 0;
		}
	}
	
	
		
	/**
	 * 
	 * Purpose : To implement basic algorithm or algorithms for the creation of a convex hull 
	 * in the plane(2d).
	 * @param points The set of points of which we will build the convex hull(2d)
	 * @param algorithm The algorithm we will use to construct the convex hull(2d) 
	 * 
	 */
	Convexhull2d(const std::vector<Point2d>& points, std::string algorithm = "Jarvis")
	{
		int size_of_vec = points.size();
		if ( size_of_vec == 0)
		{
			head = 0;
			tail = 0;
			my_size = 0;
			my_area = 0;
		}else if ( size_of_vec == 1)
		{
			Node* tmp = new Node;
			tmp->data = points[0];
			head = tmp;
			tail = tmp;
			head->front = head;
			head->back = head;
			my_size = 1;
			my_area = 0;
		}else if (size_of_vec == 2)
		{
			//I have to be carefull about whether two points are on the same 
			//vertical line, whether the two points are different 
			my_size = 2;
			my_area = 0;
		}
		if( algorithm.compare("Jarvis") == 0 )
		{
			//firstly we have to find the point with the minimum x  i.e the one we get from
			// GetX() from Point2d class
			int pos_min_x = 0; //the position with the minimum x
			for (int i = 1; i < size_of_vec; i++)
			{
				if ( points[i].GetX() < points[pos_min_x].GetX() )
				{
					pos_min_x = i;
				}
			}// end of finding minimum
		
			//the minimum is not surely a point of the convex hull 
			// for example if there is three point with the same minimum x 
			// then one of them or two of them must be included to the 
			// convex hull . but we must start from this ?
			// probably I have to find all the minimum and to place them 
			// in a vector, and after that i have to find the one with 
			//the minimum or maximum y. So if we start from the point with
			// the minimum or maximum y then the others will be rejected 
			// from the algorithm because it will be colinear.
			
			// from all the points with the minimum x we must select the one 
			// with the minimum y. But you can't avoid that you have to find 
			// first the minimum x. If you don't find the minimum by x first
			// then if the point with the minimum x is only one then the algorithm
			// will fail.
			int pos_head = pos_min_x;
			for(int i = 0; i < size_of_vec; i++ )
			{
				if ( (points[i].GetX() <= points[pos_head].GetX()) && (points[i].GetY() <= points[pos_head].GetY()) )
				{
					pos_head = i;
				}
				
			}// for sure the points[pos_best_x] wil be the first point of the
			// convex hull(2d).
			int pos_tail = 0; // the position with the maximum x will be 
			//needed in order to set the tail of the list to this position.
			//But it will be better if this maximum x has only the minimum y.
			for( int i = 1; i < size_of_vec; i++ )
			{
				if( points[i].GetX() > points[pos_tail].GetX() )
				{
					pos_tail = i;
				}
			}
			for( int i = 0 ; i < size_of_vec; i++ )
			{
				if( (points[i].GetX() >= points[pos_tail].GetX()) && (points[i].GetY() <= points[pos_tail].GetY()) )
				{
					pos_tail = i;
				}
			}

			head = new Node;
			head->data = points[pos_head];
			my_size =1;
			Node* last_node = head;//we have to hold also the last node added to the list
			int last_ch_pos = pos_head;// the position of the last point added to the convex
			//hull (2d).
			int pos_next_cand = (pos_head+1)%size_of_vec; // with this we can guarantee
			//that we start from a "random" candidate different than the pos_head
			while( pos_next_cand != pos_head )
			{
				pos_next_cand = (pos_head+1)%size_of_vec;// there is no problem if we 
				//assign a standard possible next candidate, I added this line because
				//from the end of the while if we come here the pos_next_cand doesn't
				//change and at this run of the while you will have the pos_next_cand
				// and the last_ch_pos equals. So the first if in the for will not be 
				// true never.
				
				for( int i = 0; i < size_of_vec; i++ )
				{
					if( i != last_ch_pos && i != pos_next_cand && last_ch_pos != pos_next_cand ){//doesn't have a sense to 
						// check the angle if one of the point is the same with another
						if ( Predicates::Orient_Pred(points[pos_next_cand],points[last_ch_pos],points[i]) > 0 )
						{
							pos_next_cand = i;
						}						
					}
				}
				// if there are more than one points which are good as the 
				// points[pos_next_cand] i.e, the vector that starts from the
				// last point of the convex hull and ends to the point that
				// is the best, is colinear with the vector that starts from
				// the last point of the convex hull and ends to another point
				// (the last point is the point which is as good as the 
				// points[pos_next_cand]. From the points[pos_next_cand] and 
				// the other point we have to insert to the convex hull the 
				// one with the greater distance from the last point of the
				// convex hull(2d).
				for( int i = 0; i < size_of_vec ; i++ )
				{
					if( Predicates::Orient_Pred(points[pos_next_cand],points[last_ch_pos],points[i]) == 0 &&
						Point2d::Distanceof2dPoints(points[last_ch_pos],points[pos_next_cand]) < 
						Point2d::Distanceof2dPoints(points[last_ch_pos],points[i]) )
						pos_next_cand = i;
				}//with the finish of the for we have the new point of the convex hull in the pos_next_cand
				if( pos_next_cand != pos_head )
				{
					//below we insert the point to the dlc list
					Node* tmp = new Node;
					tmp->data = points[pos_next_cand];
					last_node->front = tmp;
					tmp->back = last_node;
					if( pos_next_cand == pos_tail )
					{
						tail = tmp;
					}
					//below we have to update the indexes and the pointers to node
					last_node = tmp;
					last_ch_pos = pos_next_cand;
					my_size++;
					//becareful don't updathe pos_next_cand because it is checked in the 
					//condition of the while
				
				}else //if the next point of the ch(2d) is the head then 
				{	//we don't have to allocate memory it is already allocated
					last_node->front = head;
					head->back = last_node;
				}
			}
		}
	};

	
	
	
	/**
	 *   Destructor 
	 */
	~Convexhull2d()
	{
		if (head != 0)
		{
			Node* curr;
			Node* last;
			curr = head;
			last = head->back;
			while( curr != last )
			{
				Node* tmp = curr;
				curr = curr->front;
				//you should uncomment the below if you are running tests
				//std::cout << "deletion : " << tmp->data <<  ", with address : " << tmp << "\n";
				delete tmp;
			}
			//you should uncomment the below if you are running tests
			//std::cout << "deletion : " << last->data << ", with address : " << last << "\n"; 
			delete last;
		}
	}
	
	/**
	 *    Assignment Operator
	 */
	Convexhull2d& operator=(const Convexhull2d& other_ch)
	{
		if (this != &other_ch)
		{
			//firstly we have to delete the list that "this" holds, if "this" is 
			//nonotherwise will have a memory leak 
			if ( head!= 0 ) 
			{
				Node* curr;
				Node* last;
				curr = head;
				last = head->back;
				while( curr->front != last )
				{
					Node* tmp = curr;
					curr = curr->front;
					std::cout << "Deletion of the node with address : " << tmp << "\n";
					delete tmp;
				}
				std::cout << "Deletion of the node with address : " << last << "\n";
				delete last;
			}
			//the above was the last command of the deletion of the "this" list.
				
			//now we have the same list as the other_ch 
			if(other_ch.my_size > 0)
			{
			// we can't iterate through the iterator we made because with this we can only access the 
			// list not to modify. Here we make modification in order the nodes point where we want !!
				Convexhull2d::ch_iterator curr_it(other_ch.begin());
				Node* curr = new Node;
				curr->data = *curr_it;
				head = curr;
				Node* pre_curr = curr;
				while(++curr_it != other_ch.head)
				{
					curr = new Node;
					curr->data = *curr_it;
					pre_curr->front = curr;
					curr->back = pre_curr;
					pre_curr = curr;
				}
				curr->front = head;
				head->back = curr;
			
				my_size = other_ch.my_size;
				my_area = other_ch.my_area;
			}else
			{
				head = 0;
				my_size = 0;
				my_area = 0;
			}
		}
		return *this;
	}
	

	/**
	 * @returns the number of the points consistute the convex hull
	 */
	unsigned int size() const
	{
		return my_size;
	}

	/**
	* initially this method will add a Point2d to the "head" of the list, but 
	* at the next stage it will check if the element is in the convex hull or not.
	* If it is in the convex hull it will be added to the list
	* @param point Is the point that will be add to the head of the list.
	*/
	void push(Point2d point) 
	{
		Node* tmp = new Node;
		tmp->data = point;
		if(my_size == 0)
		{
			head = tmp;
			head->front = head;
			head->back = head;
		}else
		{
			Node* last = head->back;			
			last->front = tmp;
			tmp->back = last;
			tmp->front = head;
			head->back = tmp;
			head = tmp;
		}
		my_size++;
	}
	
	/**
	* @returns an iterator at the head of the list.
	*/
	ch_iterator begin() const
	{
		//assert(my_size > 0);
		return ch_iterator(head);
	}

	
	/**
	 * @returns the point with the maximum x, and the minimum y
	 */
	ch_iterator end() const
	{
		return ch_iterator(tail);
	}
	
	
	
};


#endif