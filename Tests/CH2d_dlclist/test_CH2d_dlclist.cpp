#include <iostream>
#include <fstream>
#include "../../CH2d_dlclist.hpp"
#include "../../Point2d.hpp"

void test_push()
{
	std::cout << "Start---Testing: void push(T a)----------" << "\n\n"; 
	
	std::ofstream outfile("convex_hull_res.dat");
	
	//the below code is for the reading of data from the following file
	//std::ifstream infile("sets_of_points.dat");
	//double a;
	//double b;
	//std::string tmp;
	//std::vector<Point2d> vec1;
	//while (infile >> tmp >> a  >> tmp >>  b >> tmp)
	//{
	//	vec1.push_back(Point2d(a,b));
	//}
	
	
	CH2d_dlclist ch;
	
	std::cout << "-----\n";
	std::cout << "The point " << Point2d(0,0) << " was added " << ch.push(Point2d(0,0)) <<"\n";
	CH2d_dlclist::ch_iterator it1 = ch.begin();
	CH2d_dlclist::ch_iterator flag1 = it1;
	std::cout << *it1 << "\n";
	while( ++it1 != flag1 )
	{
		std::cout  << *it1 << "\n" ;
	}
	std::cout << "The size of the convex hull is " << ch.size() << "\n";
	std::cout  << "The head is " << *ch.begin() << "\n";
	std::cout  << "The tail is " << *ch.end() << "\n";
	
	
	std::cout << "-----\n";
	std::cout << "The point " << Point2d(0,1) << " was added " << ch.push(Point2d(0,1)) <<"\n";
	it1 = ch.begin();
	flag1 = it1;
	std::cout << *it1 << "\n";
	while( ++it1 != flag1 )
	{
		std::cout  << *it1 << "\n" ;
	}
	std::cout << "The size of the convex hull is " << ch.size() << "\n";
	std::cout  << "The head is " << *ch.begin() << "\n";
	std::cout  << "The tail is " << *ch.end() << "\n";
	
	
	std::cout << "-----\n";
	std::cout << "The point " << Point2d(1,1.5) << " was added " << ch.push(Point2d(1,1.5)) <<"\n";
	it1 = ch.begin();
	flag1 = it1;
	std::cout << *it1 << "\n";
	while( ++it1 != flag1 )
	{
		std::cout  << *it1 << "\n" ;
	}
	std::cout << "The size of the convex hull is " << ch.size() << "\n";
	std::cout  << "The head is " << *ch.begin() << "\n";
	std::cout  << "The tail is " << *ch.end() << "\n";
	
	
	std::cout << "-----\n";
	std::cout << "The point " << Point2d(2,-1) << " was added " << ch.push(Point2d(2,-1)) <<"\n";
	it1 = ch.begin();
	flag1 = it1;
	std::cout << *it1 << "\n";
	while( ++it1 != flag1 )
	{
		std::cout  << *it1 << "\n" ;
	}
	std::cout << "The size of the convex hull is " << ch.size() << "\n";
	std::cout  << "The head is " << *ch.begin() << "\n";
	std::cout  << "The tail is " << *ch.end() << "\n";
		
	
	std::cout << "-----\n";
	std::cout << "The point " << Point2d(1,1) << " was added " << ch.push(Point2d(1,1)) <<"\n";
	it1 = ch.begin();
	flag1 = it1;
	std::cout << *it1 << "\n";
	while( ++it1 != flag1 )
	{
		std::cout  << *it1 << "\n" ;
	}
	std::cout << "The size of the convex hull is " << ch.size() << "\n";
	std::cout  << "The head is " << *ch.begin() << "\n";
	std::cout  << "The tail is " << *ch.end() << "\n";
	
	
	std::cout << "\n";
	std::cout << "End-----Testing: void push(T a)----------" << "\n\n";
}

void test_default_constructor()
{
	std::cout << "Start---Testing: default constructor----------" << "\n\n"; 
	CH2d_dlclist a;
	std::cout << "The size of the CH2d_dlclist  obj created with the default constructor is: " << a.size() << "\n";
	std::cout << "Below must be a segmentation fault or an assertion: " << "\n"; 
	std::cout << *(a.begin()) << "\n";
      std::cout << "End---Testing: default constructor----------" << "\n\n"; 

}

void test_copy_constructor()
{
	std::cout << "Start---Testing: Copy constructor---------------" << "\n\n"; 
	CH2d_dlclist a;
	a.push(Point2d(1,1)); 
	a.push(Point2d(2,2));
	CH2d_dlclist b(a);
	std::cout << "Possibly you have to uncomment some comments from the destructor. Below you have ";
	std::cout << "to see two same lists \n";
	CH2d_dlclist::ch_iterator it = a.begin();
	CH2d_dlclist::ch_iterator flag = it;
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
	CH2d_dlclist::ch_iterator it1 = b.begin();
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
		CH2d_dlclist a;
		a.push(Point2d(3,3));
		a.push(Point2d(2,2));
		CH2d_dlclist::ch_iterator it = a.begin();
		CH2d_dlclist::ch_iterator flag = it;
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
	CH2d_dlclist a;
	a.push(Point2d(1,1));
	a.push(Point2d(2,2));
	CH2d_dlclist b;
	b = a;
	std::cout << "Possibly you have to uncomment some comments from the assignment operator and from the ";
	std::cout << "destructor. Below you have to see two same lists \n";
	CH2d_dlclist::ch_iterator it = a.begin();
	CH2d_dlclist::ch_iterator flag = it;
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
	CH2d_dlclist::ch_iterator it1 = b.begin();
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
	CH2d_dlclist a;
	std::cout << "push()\n";
	a.push(Point2d(5,5));
	std::cout << "push()\n";
	a.push(Point2d(6,6));
	std::cout << "push()\n";
	a.push(Point2d(7,7));
	std::cout << "The size is " << a.size() << "\n";

	CH2d_dlclist b;
	std::cout << "Without push\n";
	std::cout << "The size is " << b.size() << "\n";

	
	
	std::cout << "End-------Testing: unsigned int size() const---------------" << "\n\n"; 

}


void test_begin()
{
	std::cout << "Start-----Testing: ch_iterator begin() const---------------" << "\n\n"; 
	std::cout << "We can check what the begin() returns only by where it is point to :\n";
	CH2d_dlclist a;
	std::cout << "push(5)\n";
	a.push(Point2d(5,5));
	std::cout << "The first element is " << *(a.begin()) << "\n";
	
	CH2d_dlclist b;
	std::cout << "push(5)\n";
	b.push(Point2d(5,5));
	std::cout << "push(6)\n";
	b.push(Point2d(6,6));
	std::cout << "The first element is " << *(b.begin()) << "\n";
	
	CH2d_dlclist c;
	std::cout << "push(5)\n";
	c.push(Point2d(5,5));
	std::cout << "push(6)\n";
	c.push(Point2d(6,6));
	std::cout << "push(7)\n";
	c.push(Point2d(7,7));
	std::cout << "The first element is " << *(c.begin()) << "\n";
	
	CH2d_dlclist d;
	std::cout << "Below you should see a Segmentation Fault because we tried to find the first element ";
	std::cout << "of an empty list" << "\n";
	std::cout << *(d.begin());
	std::cout << "End-------Testing: ch_iterator begin() const---------------" << "\n\n"; 

}


void test_iterators()
{
	CH2d_dlclist a;
	a.push(Point2d(2,2));
	std::cout << "a.push(2)" << "\n";
	a.push(Point2d(4,4));
	std::cout << "a.push(4)" << "\n";
	a.push(Point2d(6,6));
	std::cout << "a.push(6)" << "\n";
	a.push(Point2d(8,8));
	std::cout << "a.push(8)" << "\n";
	
	CH2d_dlclist::ch_iterator it = a.begin();
	CH2d_dlclist::ch_iterator flag = it;
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
	CH2d_dlclist b ; 
	std::cout << *(b.begin()) << "\n";
}


void test_parameter_constructor()
{
	// this test reads from the file "sets_of_points.dat"
	// and write the resulted convex hull to "convex_hull_res.dat"
	std::ifstream infile("sets_of_points.dat");
	std::ofstream outfile("convex_hull_res.dat");
	double a;
	double b;
	std::string tmp;
	std::vector<Point2d> vec1;
	while (infile >> tmp >> a  >> tmp >>  b >> tmp)
	{
		vec1.push_back(Point2d(a,b));
	}
	CH2d_dlclist a1(vec1,"Jarvis");
	
	
	CH2d_dlclist::ch_iterator it1 = a1.begin();
	CH2d_dlclist::ch_iterator flag1 = it1;
	outfile << *it1 << "\n";
	while(++it1 != flag1)
	{
		outfile << *it1 << "\n" ;
	}
	outfile << "The size of the convex hull is " << a1.size() << "\n";
	outfile << "The head is " << *a1.begin() << "\n";
	outfile << "The tail is " << *a1.end() << "\n";
	outfile << "\n";
		
	outfile.close();
}





int main(int argc, char* argv[])
{
	std::cout << "!!!In order to test what you want, just uncomment the corresponding function call from the main!!! \n\n";
	test_push();
//	test_copy_constructor();
//	test_default_constructor();
//	test_destructor();
//	test_assign_operator();
//	test_size();
//	test_begin();
//	test_iterators();
//	test_parameter_constructor();
	
	
}



