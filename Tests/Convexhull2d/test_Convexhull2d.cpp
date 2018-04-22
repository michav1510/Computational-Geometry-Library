#include <iostream>
#include "../../Convexhull2d.hpp"
#include "../../Point2d.hpp"

void test_push()
{
	std::cout << "Start---Testing: void push(T a)----------" << "\n\n"; 
	Convexhull2d a; 
	a.push(Point2d(3,3));
	a.push(Point2d(2,2));
	a.push(Point2d(1,1));
	Convexhull2d::ch_iterator it = a.begin();
	Convexhull2d::ch_iterator flag = it;
	std::cout << "---start of list---(a)"<< "\n";
	std::cout << *it << " ";
	while(++it != flag)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "The size is " << a.size() << "\n";
	std::cout << "---end of list---(a)"<< "\n";
	std::cout << "\n";
	std::cout << "End-----Testing: void push(T a)----------" << "\n\n";
}

void test_default_constructor()
{
	std::cout << "Start---Testing: default constructor----------" << "\n\n"; 
	Convexhull2d a;
	std::cout << "The size of the Convexhull2d  obj created with the default constructor is: " << a.size() << "\n";
	std::cout << "Below must be a segmentation fault or an assertion: " << "\n"; 
	std::cout << *(a.begin()) << "\n";
      std::cout << "End---Testing: default constructor----------" << "\n\n"; 

}

void test_copy_constructor()
{
	std::cout << "Start---Testing: Copy constructor---------------" << "\n\n"; 
	Convexhull2d a;
	a.push(Point2d(1,1)); 
	a.push(Point2d(2,2));
	Convexhull2d b(a);
	std::cout << "Possibly you have to uncomment some comments from the destructor. Below you have ";
	std::cout << "to see two same lists \n";
	Convexhull2d::ch_iterator it = a.begin();
	Convexhull2d::ch_iterator flag = it;
	std::cout << "---start of list---(a)"<< "\n";
	std::cout << *it << " ";
	while(++it != flag)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "The size is " << a.size() << "\n";
	std::cout << "---end of list---(a)"<< "\n";
	
	it = b.begin();
	flag = it;
	std::cout << "---start of list---(b)"<< "\n";
	std::cout << *it << " ";
	while(++it != flag)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "The size is " << b.size() << "\n";
	std::cout << "---end of list---(b)"<< "\n";
	
	std::cout << "Now we will see if the addresses of the elements are equal\n";
	it = a.begin();
	Convexhull2d::ch_iterator it1 = b.begin();
	unsigned int count = 0;
	while(count<a.size() && count<b.size())
	{
		std::cout << count+1 << " element of list(a) address == " << count+1 << " element of list(b) address \n";
		if(it+count == it1+count)
		{
				std::cout << "Yes they are equal\n";
		}else
		{
				std::cout << "No they aren't equal\n";	
		}
		count++;
	}
	
	std::cout << "End-----Testing: Copy constructor---------------" << "\n\n"; 
}


void test_destructor()
{
	std::cout << "Start-----Testing: Destructor---------------" << "\n\n"; 
	std::cout << "In order to see if the destructor works you have to uncomment some comments from the destructor \n";
	if(1)
	{
		Convexhull2d a;
		a.push(Point2d(3,3));
		a.push(Point2d(2,2));
		Convexhull2d::ch_iterator it = a.begin();
		Convexhull2d::ch_iterator flag = it;
		std::cout << "---start of list---(a)"<< "\n";
		std::cout << *it << " ";
		while(++it != flag)
		{
			std::cout << *it << " ";
		}
		std::cout << "\n";
		std::cout << "The size is " << a.size() << "\n";
		std::cout << "---end of list---(a)"<< "\n";
		
	}
	std::cout << "End-------Testing: Destructor---------------" << "\n\n"; 
}


void test_assign_operator()
{
	std::cout << "Start-----Testing: assign operator---------------" << "\n\n"; 
	Convexhull2d a;
	a.push(Point2d(1,1));
	a.push(Point2d(2,2));
	Convexhull2d b;
	b = a;
	std::cout << "Possibly you have to uncomment some comments from the assignment operator and from the ";
	std::cout << "destructor. Below you have to see two same lists \n";
	Convexhull2d::ch_iterator it = a.begin();
	Convexhull2d::ch_iterator flag = it;
	std::cout << "---start of list---(a)"<< "\n";
	std::cout << *it << " ";
	while(++it != flag)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "The size is " << a.size() << "\n";
	std::cout << "---end of list---(a)"<< "\n";
	
	it = b.begin();
	flag = it;
	std::cout << "---start of list---(b)"<< "\n";
	std::cout << *it << " ";
	while(++it != flag)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "The size is " << b.size() << "\n";
	std::cout << "---end of list---(b)"<< "\n";
	
	std::cout << "Now we will see if the addresses of the elements are equal\n";
	it = a.begin();
	Convexhull2d::ch_iterator it1 = b.begin();
	unsigned int count = 0;
	while(count<a.size() && count<b.size())
	{
		std::cout << count+1 << " element of list(a) address == " << count+1 << " element of list(b) address \n";
		if(it+count == it1+count)
		{
				std::cout << "Yes they are equal\n";
		}else
		{
				std::cout << "No they aren't equal\n";	
		}
		count++;
	}
	
 	std::cout << "End-------Testing: assign operator---------------" << "\n\n"; 
}


void test_size()
{
	std::cout << "Start-----Testing: unsigned int size() const---------------" << "\n\n"; 
	Convexhull2d a;
	std::cout << "push()\n";
	a.push(Point2d(5,5));
	std::cout << "push()\n";
	a.push(Point2d(6,6));
	std::cout << "push()\n";
	a.push(Point2d(7,7));
	std::cout << "The size is " << a.size() << "\n";

	Convexhull2d b;
	std::cout << "Without push\n";
	std::cout << "The size is " << b.size() << "\n";

	
	
	std::cout << "End-------Testing: unsigned int size() const---------------" << "\n\n"; 

}


void test_begin()
{
	std::cout << "Start-----Testing: ch_iterator begin() const---------------" << "\n\n"; 
	std::cout << "We can check what the begin() returns only by where it is point to :\n";
	Convexhull2d a;
	std::cout << "push(5)\n";
	a.push(Point2d(5,5));
	std::cout << "The first element is " << *(a.begin()) << "\n";
	
	Convexhull2d b;
	std::cout << "push(5)\n";
	b.push(Point2d(5,5));
	std::cout << "push(6)\n";
	b.push(Point2d(6,6));
	std::cout << "The first element is " << *(b.begin()) << "\n";
	
	Convexhull2d c;
	std::cout << "push(5)\n";
	c.push(Point2d(5,5));
	std::cout << "push(6)\n";
	c.push(Point2d(6,6));
	std::cout << "push(7)\n";
	c.push(Point2d(7,7));
	std::cout << "The first element is " << *(c.begin()) << "\n";
	
	Convexhull2d d;
	std::cout << "Below you should see a Segmentation Fault because we tried to find the first element ";
	std::cout << "of an empty list" << "\n";
	std::cout << *(d.begin());
	std::cout << "End-------Testing: ch_iterator begin() const---------------" << "\n\n"; 

}


void test_iterators()
{
	Convexhull2d a;
	a.push(Point2d(2,2));
	std::cout << "a.push(2)" << "\n";
	a.push(Point2d(4,4));
	std::cout << "a.push(4)" << "\n";
	a.push(Point2d(6,6));
	std::cout << "a.push(6)" << "\n";
	a.push(Point2d(8,8));
	std::cout << "a.push(8)" << "\n";
	
	Convexhull2d::ch_iterator it = a.begin();
	Convexhull2d::ch_iterator flag = it;
	std::cout << "---start of list---(a)"<< "\n";
	std::cout << *it << " ";
	while(++it != flag)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
	std::cout << "The size is " << a.size() << "\n";
	std::cout << "---end of list---(a)"<< "\n";
	
	std::cout << "head   : " << *(a.begin()) << "\n";
	std::cout << "head+1 : " << *(a.begin()+1) << "\n";
	std::cout << "head-1 : " << *(a.begin()-1) << "\n";
	std::cout << "head+2 : " << *(a.begin()+2) << "\n";
	std::cout << "head-2 : " << *(a.begin()-2) << "\n";
	std::cout << "head+3 : " << *(a.begin()+3) << "\n";
	std::cout << "head-3 : " << *(a.begin()-3) << "\n";
	std::cout << "head+4 : " << *(a.begin()+4) << "\n";
	std::cout << "head-4 : " << *(a.begin()-4) << "\n";
	std::cout << "head+5 : " << *(a.begin()+5) << "\n";
	std::cout << "head-5 : " << *(a.begin()-5) << "\n";
	
	std::cout << "head+1260 : " << *(a.begin()+1260) << "\n";
	std::cout << "head-1260 : " << *(a.begin()-1260) << "\n";

	std::cout << "----\n";	
	it = a.begin();
	std::cout << "(it) points to : " << *it << "\n";
	std::cout << "(++it== a.begin()) : " << (++it == a.begin())  << "\n";
	std::cout << "----\n";

	std::cout << "----\n";	
	it = a.begin();
	std::cout << "(it) points to : " << *it << "\n";
	std::cout << "(it++== a.begin()) : " << (it++ == a.begin())  << "\n";
	std::cout << "----\n";
	
	std::cout << "----\n";	
	it = a.begin();
	std::cout << "(it) points to : " << *it << "\n";
	std::cout << "(--it== a.begin()) : " << (--it == a.begin())  << "\n";
	std::cout << "----\n";

	std::cout << "----\n";	
	it = a.begin();
	std::cout << "(it) points to : " << *it << "\n";
	std::cout << "(it--== a.begin()) : " << (it-- == a.begin())  << "\n";
	std::cout << "----\n";
	
	std::cout << "----\n";
	std::cout << "I made an empty list and I will try to see where the begin() points to \n" ;
	std::cout << "So below we will see a Segmentation Fault \n";
	Convexhull2d b ; 
	std::cout << *(b.begin()) << "\n";
}


void test_parameter_constructor()
{
	std::vector<Point2d> vec;
	vec.push_back(Point2d(0,0));
	vec.push_back(Point2d(0,1));
	vec.push_back(Point2d(0,1.5));
	vec.push_back(Point2d(0.5,2));
	vec.push_back(Point2d(1,1.75));
	vec.push_back(Point2d(1,1));
	vec.push_back(Point2d(0.5,-0.5));
	vec.push_back(Point2d(0.1,-0.5));
	Convexhull2d a(vec,"Jarvis");
	Convexhull2d::ch_iterator it = a.begin();
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	it++;
	std::cout << *it << "\n";
	std::cout << "The size of the Convexhull2d is " << a.size() << "\n";
	std::cout << "The tail of the list is " << *(a.end()) << "\n";
}

int main(int argc, char* argv[])
{
	std::cout << "!!!In order to test what you want, just uncomment the corresponding function call from the main!!! \n\n";
//	test_push();
//	test_copy_constructor();
//	test_default_constructor();
//	test_destructor();
//	test_assign_operator();
//	test_size();
//	test_begin();
//	test_iterators();
	test_parameter_constructor();
	
	
}



