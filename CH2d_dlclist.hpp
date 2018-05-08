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
#include <stack>
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
		if( size_of_vec == 0 )
		{
			head = 0;
			tail = 0;
			my_size = 0;
			my_area = 0;
		}else if( size_of_vec == 1 )
		{
			head = new Node;
			head->data = points[0];
			head->front = head;
			head->back = head;
			tail = head;
			my_size = 1;
			my_area = 0;
		}else if(size_of_vec == 2)
		{
			if( points[0] == points[1] )
			{
				head = new Node;
				head->data = points[0];
				head->front = head;
				head->back = head;
				tail = head;
				my_size = 1;
				my_area = 0;
			}else if( points[0].GetX() == points[1].GetX() )
			{
				head = new Node;
				tail = new Node;
				if( points[0].GetY() < points[1].GetY() )
				{
					head->data = points[0];
					tail->data = points[1];
					
				}else if( points[0].GetY() > points[1].GetY() )
				{
					head->data = points[1];
					tail->data = points[0];
				}
				head->front = tail;
				tail->back = head;
				tail->front = head;
				head->back = tail;
				my_size = 2;
				my_area = 0;
			}else 
			{
				head = new Node;
				tail = new Node;
				if( points[0].GetX() < points[1].GetX() )
				{
					head->data = points[0];
					tail->data = points[1];
				}else
				{
					head->data = points[1];
					tail->data = points[0];
				}
				head->front = tail;
				tail->back = head;
				tail->front = head;
				head->back = tail;
				my_size = 2;
				my_area = 0;
			}
		}else
		{
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
					pos_next_cand = (last_ch_pos+1)%size_of_vec;// we change the pos_next_cand
					//after the while because we don't want to the end of the while because
					//at the start of the while we remain the pos_next_cand to be checked.
					// the last_ch_pos changes in every iteration so there is no problem this
					// assignment.
				
					for( int i = 0; i < size_of_vec; i++ )
					{
						if( i != last_ch_pos && i != pos_next_cand && last_ch_pos != pos_next_cand )
						{
							//doesn't have a sense to  check the angle if one of the point is the
							//same with another
							if( Pred::Orient(points[pos_next_cand],points[last_ch_pos],points[i]) > 0 || 
							       (Pred::Orient(points[pos_next_cand],points[last_ch_pos],points[i]) == 0 &&
							       Point2d::Distanceof2dPoints(points[last_ch_pos],points[pos_next_cand]) < 
							       Point2d::Distanceof2dPoints(points[last_ch_pos],points[i])) )
							{
							//the best point will change if there is one with better angle, or a collinear
							//point which is more distant from the last point added than the best point is distant
							//from the last point added.
								pos_next_cand = i;
							}						
						}
					}
					//with the finish of the for we have the new point of the convex hull in the pos_next_cand
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
			notify_area();
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
					//std::cout << "Deletion of the node with address : " << tmp << "\n";
					delete tmp;
				}
				//std::cout << "Deletion of the node with address : " << last << "\n";
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
	* This function will push a point to the dlc list if it is not in the
	* convex hull(2d), otherwise it will not be added. The complexity of 
	* the addition of the point to a list, if the list size is >= 3, is
	* O(n). Because it runs the upper hull and the lower hull to check 
	* if there are not anti clockwise turns in the convex hull(2d). 
	* Purpose : to add a point if it is not interval to the convex hull(2d) 
	* @param point Is the point that will be add to the head of the list.
	* @returns -1 if the point wasn't added to the list, 1 if the point
	* was added to the list.
	*/
	int push(const Point2d& query_po) 
	{
		if( my_size == 0 )
		{
			//std::cout << "(DEBUGGING) : case 1\n";
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
			//std::cout << "(DEBUGGING) : case 2\n";
			Node* current_nod ;
			current_nod = head;

			//the current point of the list is represented by the head
			if( !(query_po == current_nod->data) )//if the points are not equal
			{
				//std::cout << "(DEBUGGING) : case 3\n";
				Node* new_elem = new Node; // if we construct the new point Node and it will not be added we will have 
				// a memory leak, so I declare and initialize the node inside the if
				new_elem->data = query_po;
					
				if( query_po.GetX() < current_nod->data.GetX() )
				{
					//std::cout << "(DEBUGGING) : case 4\n";
					head = new_elem;
					tail = current_nod;
				}
				else if( query_po.GetX() > current_nod->data.GetX() )
				{
					//std::cout << "(DEBUGGING) : case 5\n";
					head = current_nod;
					tail = new_elem;
				}else//if the two points are on the same vertical position
				{
					//std::cout << "(DEBUGGING) : case 6\n";
					if( current_nod->data.GetY() > query_po.GetY() )
					{
						//std::cout << "(DEBUGGING) : case 7\n";
						head = new_elem;
						tail = current_nod;

					}else if( current_nod->data.GetY() < query_po.GetY() )
					{
						//std::cout << "(DEBUGGING) : case 8\n";
						head = current_nod;
						tail = new_elem;
					}
				}
				//std::cout << "(DEBUGGING) : case 9\n";
				head->front = tail;
				head->back = tail;
				tail->back = head;
				tail->front = head;
				my_size++;
				my_area = 0;
				return 1; 
			}else
			{
				//std::cout << "(DEBUGGING) : case 10\n";
				return -1;
			}
			
		}else if( my_size == 2 )
		{
			//std::cout << "(DEBUGGING) : case 11\n";
			if( head->data == query_po || tail->data == query_po )
			{
				//std::cout << "(DEBUGGING) : case 12\n";
				//if the query point is equal with one of the current points
				return -1;
			}else if( Pred::Orient(query_po,head->data,tail->data) == 0  &&
				   ( (query_po.GetX() >= head->data.GetX() && query_po.GetX() <= tail->data.GetX()) &&
				     (query_po.GetY() >= head->data.GetY() && query_po.GetY() <= tail->data.GetY()) )  )
			{
				//std::cout << "(DEBUGGING) : case 13\n";
				// if the query point is collinear with the other two and the query point is between the head
				// and the tail then it will not be added to the list
				return -1;
			}else if( Pred::Orient(query_po,head->data,tail->data) == 0 ) 
			{
				//std::cout << "(DEBUGGING) : case 14\n";
				// the new element is collinear but it will be added to the list
				Node* new_elem = new Node;
				new_elem->data = query_po;
				if( head->data.GetX() == tail->data.GetX() )
				{
					//std::cout << "(DEBUGGING) : case 15\n";
					// if the head and the tail lie on the same vertical line
					//then we check the y coordinates
					if( query_po.GetY() < head->data.GetY() )
					{
						//std::cout << "(DEBUGGING) : case 16\n";
						// the new element must substitute the head and the (old) head must be deleted
						delete head;//the old head must be deleted 
						head = new_elem;
					}else
					{
						//std::cout << "(DEBUGGING) : case 17\n";
						// the new element must substitute the tail and the (old) head must be deleted
						delete tail;// the old tail must be deleted
						tail = new_elem;
					}
				}else if( query_po.GetX() < head->data.GetX() )
				{
					//std::cout << "(DEBUGGING) : case 18\n";
					// the new element must substitute the head and the (old) head must be deleted
					delete head;//the old head must be deleted 
					head = new_elem;
				}else
				{
					//std::cout << "(DEBUGGING) : case 19\n";
					// the new element must substitute the tail and the (old) head must be deleted
					delete tail;// the old tail must be deleted
					tail = new_elem;
				}
				//std::cout << "(DEBUGGING) : case 20\n";
				head->front = tail;
				tail->back = head;
				tail->front = head;
				head->back = tail;
				//becareful we added a new element but we deleted also so there is no change in
				//the size, nor change to the area because is zero again;
				return 1;
			}else 
			{
				//std::cout << "(DEBUGGING) : case 21\n";
				// in this case the query point will be added to the list
				Node* new_elem = new Node;
				new_elem->data = query_po;
				if( query_po.GetX() < head->data.GetX() ||
				    (query_po.GetX() == head->data.GetX() && query_po.GetY() < head->data.GetY()) )
				{
					//std::cout << "(DEBUGGING) : case 22\n";
					// then the head must be substituted by the query point
					Node* old_head = head;
					head = new_elem;
					if( Pred::Orient(query_po,old_head->data,tail->data) < 0 )
					{
						//std::cout << "(DEBUGGING) : case 23\n";
						// the front of the new head is the tail,
						head->front = tail;
						tail->back = head;
						tail->front = old_head;
						old_head->back = tail;
						old_head->front = head;
						head->back = old_head;
						if( old_head->data.GetX() == tail->data.GetX() )
						{
							//std::cout << "(DEBUGGING) : case 24\n";
							//if the old head lie on the same vertical
							// line with the tail then the tail also must change
							tail = old_head;						
						}
					}else
					{
						//std::cout << "(DEBUGGING) : case 25\n";
						// the front of the new head is the old head
						head->front = old_head;
						old_head->back = head;
						old_head->front = tail;
						tail->back = old_head;
						tail->front = head;
						head->back = tail;
					}
				}else if( query_po.GetX() > tail->data.GetX() ||
				        (query_po.GetX()== tail->data.GetX() && query_po.GetY() < tail->data.GetY()) )
				{
					//std::cout << "(DEBUGGING) : case 26\n";
					// the the tail must be substituted 
					Node* old_tail = tail;
					tail = new_elem;
					if( Pred::Orient(head->data,old_tail->data,query_po) < 0 )
					{
						//std::cout << "(DEBUGGING) : case 27\n";
						// then the front of the head is the new tail 
						head->front = tail;
						tail->back = head;
						tail->front = old_tail;
						old_tail->back = tail;
						old_tail->front = head;
						head->back = old_tail;
					}else 
					{
						//std::cout << "(DEBUGGING) : case 28\n";
						// the front of the head is the old tail
						head->front = old_tail;
						old_tail->back = head;
						old_tail->front = tail;
						tail->back = old_tail;
						tail->front = head;
						head->back = tail;
					}
				}else
				{
					//std::cout << "(DEBUGGING) : case 29\n";
					// then the nor the head nor the tail must be substituted
					if( Pred::Orient(tail->data,head->data,query_po) > 0 )
					{
						//std::cout << "(DEBUGGING) : case 30\n";
						head->front = new_elem;
						new_elem->back = head;
						new_elem->front = tail;
						tail->back = new_elem;
						tail->front = head;
						head->back = tail;
					}else 
					{
						//std::cout << "(DEBUGGING) : case 31\n";
						head->front = tail;
						tail->back = head;
						tail->front = new_elem;
						new_elem->back = tail;
						new_elem->front = head;
						head->back = new_elem;
					}
					
				}
				//std::cout << "(DEBUGGING) : case 31\n";
				my_size++;
				notify_area();
				return 1;
			}			
		}else//in this case we have an at least 3 points current convex hull(2d)
		{
			//std::cout << "(DEBUGGING) : case 33\n";
			//becareful you can't avoid the first stage which is the necessity to add 
			//the point to the list and the later loop will delete it if needed. The 
			//reason is you can't know how many points front or back you have to delete
			//if the query point will be added to the list.
			
			Node* query_nod = new Node;//it is helpfull to create the node of the query point
			query_nod->data = query_po;//because it is very helpfull in the deletion later.
			
			bool quer_po_added = false;// it is very usefull to see
			//if the query point added to the list, if it is not added
			//you haven't to run the last while which deletes the unnecessary 
			//points.
			
			//the case where the query point is equal with one of the points of the convex hull(2d)
			//is checked in the else of the following if-elseif...-else statement
			if( query_po.GetX() <= head->data.GetX() && query_po.GetY() < head->data.GetY() )
			{
				//std::cout << "(DEBUGGING) : case 34\n";
				Node* new_head = query_nod;//the query point is new head
			
				Node* bef_head = head->back;
				bef_head->front = new_head;
				new_head->back = bef_head;
				new_head->front = head;
				head->back = new_head;
				
				quer_po_added = true;
				my_size++;
				head = new_head;
				//now we the new point is inserted to the list and the later loop 
				//will delete some points if it is needed
			}else if( query_po.GetX() < head->data.GetX() && query_po.GetY() >= head->data.GetY() )
			{
				//std::cout << "(DEBUGGING) : case 35\n";
				Node* new_head = query_nod;//the query point is new head
							
				Node* after_head = head->front;
				head->front = new_head;
				new_head->back = head;
				new_head->front = after_head;
				after_head->back = new_head;
				
				quer_po_added = true;
				my_size++;
				head = new_head;
				//now we the new point is inserted to the list and the later loop 
				//will delete some points if it is needed
			}
			else if( query_po.GetX() > tail->data.GetX() && query_po.GetY() >= tail->data.GetY() )
			{
				//std::cout << "(DEBUGGING) : case 36\n";
				// becareful if the X's are equal and the Y of query point is bigger or equal to Y of tail
				// then the query point is not new tail
				Node* new_tail = query_nod;//the query point is new tail
				
				Node* after_tail = tail->front;
				tail->front = new_tail;
				new_tail->back = tail;
				new_tail->front = after_tail;
				after_tail->back = new_tail;
			
				quer_po_added = true;
				my_size++;
				tail = new_tail;
				//now the new point is inserted to the list and the later loop 
				//will delete some points if it is needed
			}else if ( query_po.GetX() >= tail->data.GetX() && query_po.GetY() < tail->data.GetY()  )
			{
				//std::cout << "(DEBUGGING) : case 37\n";
				Node* new_tail = query_nod;//the query point is new tail
				
				Node* after_tail = tail->front;
				tail->front = new_tail;
				new_tail->back = tail;
				new_tail->front = after_tail;
				after_tail->back = new_tail;
				
				quer_po_added = true;
				my_size++;
				tail = new_tail;
				//now we the new point is inserted to the list and the later loop 
				//will delete some points if it is needed
			}
			else
			{
				//std::cout << "(DEBUGGING) : case 38\n";
				//the query point lies above or below the convex hull(2d)
				Node* prev = head;
				Node* after = head->front;
				while( prev != tail )
				{
					//std::cout << "(DEBUGGING) : case 39\n";
					// upper hull iteration
					if( query_po == prev->data || query_po == after->data)
					{
						//std::cout << "(DEBUGGING) : case 40\n";
						// this is the case where the query point is equal to one point of the 
						// current convex hull
						delete query_nod;//we must delete the query point that we allocated
						return -1;
					}
					if( prev->data.GetX() != after->data.GetX() && 
					    query_po.GetX() >= prev->data.GetX() && query_po.GetX() <= after->data.GetX() )
					{
						//std::cout << "(DEBUGGING) : case 41\n";
						//if after and prev are on the same vertical line then we don't want to add the 
						//query point here because it will be added to the next iteration
						if( Pred::Orient(prev->data,query_po,after->data) > 0 )
						{
							//std::cout << "(DEBUGGING) : case 42\n";
							//the second condition after || is for the case that the previous and the after 
							//are at the same x coordinate, and we have three collinear points
							//(with the query point) and the query point is not between the other two points,
							// thus it should be added to the list because it is surely in the convex hull(2d)							
							prev->front = query_nod;
							query_nod->back = prev;
							query_nod->front = after;
							after->back = query_nod;
							quer_po_added = true;
							my_size++;//the size must be increased. at the later stage may also be decreased.
							break;//if we find the position of the query point in the list the we must stop
						}
					}
					//std::cout << "(DEBUGGING) : case 43\n";
					prev = prev->front;
					after = after->front;
				}
				//std::cout << "(DEBUGGING) : case 44\n";
				prev = tail;
				after = tail->front;
				while( prev != head && !quer_po_added )
				{
					//std::cout << "(DEBUGGING) : case 45\n";
					// lower hull iteration
					if( query_po == prev->data || query_po == after->data)
					{
						//std::cout << "(DEBUGGING) : case 46\n";
						// this is the case where the query point is equal to one point of the 
						// current convex hull
						delete query_nod;//we must delete the query point that we allocated
						return -1;
					}
					if( prev->data.GetX() != after->data.GetX() && 
					    query_po.GetX() >= after->data.GetX() && query_po.GetX() <= prev->data.GetX() )
					{
						//std::cout << "(DEBUGGING) : case 47\n";
						if( Pred::Orient(prev->data,query_po,after->data) > 0 )
						{
							//std::cout << "(DEBUGGING) : case 48\n";
							//the second condition after || is for the case that we have three collinear points
							// and the query point is not between the other two points, thus it should be added
							// to the list because it is surely in the convex hull(2d)
							prev->front = query_nod;
							query_nod->back = prev;
							query_nod->front = after;
							after->back = query_nod;
							quer_po_added = true;
							my_size++;//the size must be increased. at the later stage may also be decreased.
							break;//if we find the position of the query point in the list the we must stop
						}
					}	
					//std::cout << "(DEBUGGING) : case 49\n";
					prev = prev->front;
					after = after->front;
				}
			}
			//at this stage we have added the query point to the list but maybe will deleted and also
			//some other points maybe will deleted, the head and the tail points to the right nodes 
			//std::cout << "(DEBUGGING) : case 50\n";
			if ( !quer_po_added )
			{
				//std::cout << "(DEBUGGING) : case 51\n";
				//if the query point have not been added to the list then we don't have 
				//to proceed any further because there is no change in the list. 
				delete query_nod;
				return -1;
			}
				
			std::stack<Node*> del;// all the points from the list that will be deleted
			//now is the time to delete all the unnecessary points

			//the upper hull iteration to remove unnecessary points
			std::vector<Node*> upp;
			upp.push_back(head);
			upp.push_back(head->front);
			Node* curr = head->front;
			std::cout << "(DEBUGGING)-------------------------------\n";
			std::cout << "(DEBUGGING) 1\n";
			while( curr != tail )
			{
				std::cout << "(DEBUGGING) 2\n";
				curr = curr->front;
				upp.push_back(curr);
				int siz = upp.size();
				while( siz > 2 && Pred::Orient(upp[siz-3]->data,upp[siz-2]->data,upp[siz-1]->data) <= 0 )
				{
					std::cout << "(DEBUGGING) 3\n";
					upp[siz-3]->front = upp[siz-1];
					upp[siz-1]->back = upp[siz-3];
					del.push(upp[siz-2]);
					upp.erase(upp.end()-2);
					siz = upp.size();
				}
			}
			//lower hull iteration
			std::vector<Node*> low;
			low.push_back(tail);
			low.push_back(tail->front);
			curr = tail->front;
			std::cout << "(DEBUGGING) 4\n";
			while( curr != head )
			{
				std::cout << "(DEBUGGING) 5\n";
				curr = curr->front;
				low.push_back(curr);
				int siz = low.size();
				while( siz > 2 && Pred::Orient(low[siz-3]->data,low[siz-2]->data,low[siz-1]->data) <= 0 )
				{
					std::cout << "(DEBUGGING) 6\n";
					low[siz-3]->front = low[siz-1];
					low[siz-1]->back = low[siz-3];
					del.push(low[siz-2]);
					low.erase(low.end()-2);
					siz = low.size();
				}
				std::cout << "(DEBUGGING) 7\n";
			}
			std::cout << "(DEBUGGING) 8\n";
			
			//at this point we have disconnected the unnecessary points and we inserted them to the del 
			//stack , so we have to free the pointers of this points and to reduce the size and to 
			//notify the area. of course we have to check if the query point deleted from the list 
			//thus we have the below flag
			bool flag = false;
			while( !del.empty() )
			{
				std::cout << "(DEBUGGING) 9\n";
				//std::cout << "(DEBUGGING) : case 54\n";
				if( query_nod == del.top() )
				{
					std::cout << "(DEBUGGING) 10\n";
					//std::cout << "(DEBUGGING) : case 55\n";
					flag = true;
				}
				delete del.top();
				del.pop();
				my_size--;
			}
			std::cout << "(DEBUGGING)-------------------------------\n\n\n";
			//std::cout << "(DEBUGGING) : case 56\n";
			notify_area();
			if( flag )
			{
				//std::cout << "(DEBUGGING) : case 57\n";
				return -1;
			}else
			{
				//std::cout << "(DEBUGGING) : case 58\n";
				return 1;
			}
			//std::cout << "(DEBUGGING) : case 59\n";

		}
		//std::cout << "(DEBUGGING) : case 60\n";	
		
	}
	
	
	/**
	 * @returns the number of the points consistute the convex hull
	 */
	unsigned int size() const
	{
		return my_size;
	}

	
	/**
	* @returns the point with the minimum x and the minimum y
	*/
	ch_iterator begin() const
	{
		assert( my_size > 0 );
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
	
	/**
	 * @returns the area of the convex hull(2d)
	 */
	double area() const
	{
		return my_area;
	}
	
};


#endif