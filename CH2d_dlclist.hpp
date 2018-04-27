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
#ifndef CH2D_DLCLISTDEF
#define CH2D_DLCLISTDEF
#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include "Point2d.hpp"
#include "Pred.hpp"


class CH2d_dlclist{
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
	void notify_area()
	{
		if( my_size == 0 || my_size == 1 || my_size == 2 ){
			my_area = 0;
		}else 
		{
			//in order to find the area of the convex hull we will divide it 
			//into triangles 
			
			// the below three iterators point to different nodes because
			// there are at least three nodes in the list
			CH2d_dlclist::ch_iterator it_clo_back = ch_iterator(head);
			CH2d_dlclist::ch_iterator it_clo_front = it_clo_back + 1;
			CH2d_dlclist::ch_iterator it_cou_clo = it_clo_back-1;
			
			// at the below variable we will keep the sum of the areas of 
			//every triangle
			double sum = 0;
			sum += area_of_triangle(*it_clo_back,*it_clo_front,*it_cou_clo);
			
			while( ++it_clo_front != it_cou_clo )
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
	CH2d_dlclist() 
	{
		head = 0;
		tail = 0;
		my_size = 0;
		my_area = 0;
	}
	
	
	/**
	 * Copy Constructor
	 *
	 * @returns other_ch is the Convexhull2d that we make a copy of this.
	 */
	CH2d_dlclist(const CH2d_dlclist& other_ch)
	{
		if(other_ch.my_size > 0)
		{
			CH2d_dlclist::ch_iterator curr_it(other_ch.begin());
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
	CH2d_dlclist(const std::vector<Point2d>& points, std::string algorithm = "Jarvis")
	{
		int size_of_vec = points.size();
		if( size_of_vec == 0)
		{
			head = 0;
			tail = 0;
			my_size = 0;
			my_area = 0;
		}else if( size_of_vec == 1)
		{
			Node* tmp = new Node;
			tmp->data = points[0];
			head = tmp;
			tail = tmp;
			head->front = head;
			head->back = head;
			my_size = 1;
			my_area = 0;
		}else if(size_of_vec == 2)
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
			int pos_head = 0; //the position with the minimum x
			// from all the points with the minimum x we must select the one 
			// with the minimum y. But you can't avoid that you have to find 
			// first the minimum x. If you don't find the minimum by x first
			// then if the point with the minimum x is only one then the algorithm
			// will fail.
			for (int i = 1; i < size_of_vec; i++)
			{
				if ( (points[i].GetX() <= points[pos_head].GetX()) && (points[i].GetY() <= points[pos_head].GetY()) ||
					points[i].GetX() < points[pos_head].GetX() )
				{
					pos_head = i;
				}
			}// end of finding minimum, now we have the position of the head
			// for sure the points[pos_head] wil be the first point of the
			// convex hull(2d).
			
			int pos_tail = 0; // the position with the maximum x will be 
			//needed in order to set the tail of the list to this position.
			//But it will be better if this maximum x has only the minimum y.
			for( int i = 1; i < size_of_vec; i++ )
			{
				if( (points[i].GetX() >= points[pos_tail].GetX()) && (points[i].GetY() <= points[pos_tail].GetY()) ||
					points[i].GetX() > points[pos_tail].GetX() )
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
						if( Pred::Orient(points[pos_next_cand],points[last_ch_pos],points[i]) > 0 || 
						    (Pred::Orient(points[pos_next_cand],points[last_ch_pos],points[i]) == 0 &&
						     Point2d::Distanceof2dPoints(points[last_ch_pos],points[pos_next_cand]) < 
						     Point2d::Distanceof2dPoints(points[last_ch_pos],points[i])) )
						{//the best point will change if there is one with better angle, or a collinear
						//point which is more distant from the last point added than the best point is distant
						//from the last point added.
							pos_next_cand = i;
						}						
					}
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
	~CH2d_dlclist()
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
	CH2d_dlclist& operator=(const CH2d_dlclist& other_ch)
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
			if( other_ch.my_size > 0 )
			{
			// we can't iterate through the iterator we made because with this we can only access the 
			// list not to modify. Here we make modification in order the nodes point where we want !!
				CH2d_dlclist::ch_iterator curr_it(other_ch.begin());
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
	* This function will push a point to the dlc list if it is not in the
	* convex hull(2d), otherwise it will not be added. The complexity of 
	* the addition of the point to a list, if the list size is >= 3, is
	* O(n). Because it runs the upper hull and the lower hull to check 
	* if it is in the convex hull(2d). 
	* Purpose : to add a point if it is not in the convex hull(2d) 
	* @param point Is the point that will be add to the head of the list.
	* @returns -1 if the point wasn't added to the list, 1 if the point
	* was added to the list.
	*/
	int push(const Point2d& query_po) 
	{
		if( my_size == 0 )
		{
			head = new Node;
			head->data = query_po;
			head->front = head;
			head->back = head;
			tail = head;
			my_size ++ ;
			my_area = 0;
			return 1;
		}else if( my_size == 1 )
		{
			Node* current_nod ;
			current_nod = head;
			
			//the current point of the list is represented by the head
			if( !(query_po == current_nod->data) )//if the points are not equal
			{
				Node* new_elem = new Node; // if we construct the new point Node and it will not be added we will have 
				// a memory leak, so I declare and initialize the node inside the if
				new_elem->data = query_po;
					
				if( query_po.GetX() < current_nod->data.GetX() )
				{
					head = new_elem;
					tail = current_nod;
				}
				else if( query_po.GetX() > current_nod->data.GetX() )
				{
					head = current_nod;
					tail = new_elem;
				}else//if the two points are on the same vertical position
				{
					if( current_nod->data.GetY() > query_po.GetY() )
					{
						head = new_elem;
						tail = current_nod;

					}else if( current_nod->data.GetY() < query_po.GetY() )
					{
						head = current_nod;
						tail = new_elem;
					}
				}
				head->front = tail;
				head->back = tail;
				tail->back = head;
				tail->front = head;
				my_size++;
				my_area = 0;
				return 1; 
			}else
			{
				return -1;
			}
			
		}else if( my_size == 2 )
		{
			if( head->data == query_po || tail->data == query_po )
			{//if the query point is equal with one of the current points
				return -1;
			}
			if( Pred::Orient(query_po,head->data,tail->data == 0) )
			{//then we have to find the middle one of the three colinear points
			// in order to find it we can find the three distances of one point
			// to other
				double d1 = Point2d::Distanceof2dPoints(head->data,tail->data);
				double d2 = Point2d::Distanceof2dPoints(head->data,query_po);
				double d3 = Point2d::Distanceof2dPoints(tail->data,query_po);
				if( (d1 > d2 && d2 >= d3) || (d1 > d3 && d3 >= d2) )
				{// then d1 is the biggest one, and the query point doesn't
				// pushed in the list
					return -1;
				}else if( (d2 > d1 && d1 >= d3) || (d2 > d3 && d3 >= d1) )
				{
					tail = new Node;
					tail->data = query_po;
					head->front = tail;
					head->back = tail;
					tail->front = head;
					tail->back = head;
					//we will return 1 because the query point inserted to the
					//list, although the size of the list doesn't change
					return 1;
				}else
				{
					head = new Node;
					head->data = query_po;
					head->front = tail;
					head->back = tail;
					tail->front = head;
					tail->back = head;
					//we will return 1 because the query point inserted to the
					//list, although the size of the list doesn't change
					return 1;
				}
					
			}else//in this case we have to find the new head and tail because the 
			//query point is not collinear with the other two nor the same with 
			//one of them, so we will have a triangle
			{
				Node* query_nod = new Node;
				query_nod->data = query_po;
				if( (query_nod->data.GetX() <= head->data.GetX() && query_nod->data.GetY() > head->data.GetY()) 
				    || query_nod->data.GetX() < head->data.GetX() )
				{//if the query_p is better as "head" then we have to assign it as head
					Node* swap;
					swap = head;
					head = query_nod;
					query_nod = swap;
				}
				if( (query_nod->data.GetX() >= tail->data.GetX() && query_nod->data.GetY() < tail->data.GetY()) 
				    || query_nod->data.GetX() > tail->data.GetX() )
				{//if the query_p is better as "tail" then we have to assign it as tail
					Node* swap;
					swap = tail;
					tail = query_nod;
					query_nod = swap;
				}
				if( Pred::Orient(tail->data,head->data,query_nod->data)> 0 )
				{// then the new point is "upper" than the head-tail edge
					head->front = query_nod;
					query_nod->back = head;
					query_nod->front = tail;
					tail->back = query_nod;
					tail->front = head;
					head->back = tail;
				}else // then the query point is "lower" than the head-tail edge
				{
					head->front = tail;
					tail->back = head;
					tail->front = query_nod;
					query_nod->back = tail;
					query_nod->front = head;
					head->back = query_nod;
				}
				my_size++;
				notify_area();//this function uses the my_size
				return 1;
			}
		}else//in this case we have an at least 3 points current convex hull(2d)
		{
			
		}
			

	}
	
	/**
	* @returns an iterator at the head of the list.
	*/
	ch_iterator begin() const
	{
		assert(my_size > 0);
		return ch_iterator(head);
	}

	
	/**
	 * @returns the point with the maximum x, and the minimum y
	 */
	ch_iterator end() const
	{
		assert( my_size > 0 );
		return ch_iterator(tail);
	}
	
	
	
};


#endif