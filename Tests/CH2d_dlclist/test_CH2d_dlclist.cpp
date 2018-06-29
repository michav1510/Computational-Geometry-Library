#include <iostream>
#include <fstream>
#include "../../CH2d_dlclist.hpp"
#include "../../Point2d.hpp"

/*
 * An auxiliary function to print the state of the list 
 */
void print_state_ch2d(std::ostream& wri, CH2d_dlclist a)
{
	wri << "The head is " << *(a.begin()) << "\n";
	wri << "The tail is " << *(a.end()) << "\n";
	wri << "The size is " << a.size() << "\n";
	wri << "The area is " << a.area() << "\n";
	wri << "The clockwise iteration is :" << "\n";
	CH2d_dlclist::ch_iterator it = a.begin();
	CH2d_dlclist::ch_iterator flag = it;
	int size = a.size();
	wri << *it ;
	int count = 1;
	while( ++it != flag )
	{
		if( count% 10 == 0 ) 
		{
			wri<< "\n";
		}
		wri << *it << " "; 
			
	}
	wri << "\n";
	wri << "The counter clockwise iteration is :" << "\n";
	it = a.begin();
	size = a.size();
	wri << *it;
	count = 1;
	while( --it != flag )
	{
		if( count% 10 == 0 ) 
		{
			wri<< "\n";
		}
		wri << *it << " "; 
	}
	wri << "\n";
}


void test_push()
{
	std::cout << "Start---Testing: void push(Point2d )----------" << "\n\n"; 
	
	
	/* With the below code we will execute all the cases in the
	 * push(Point2d) as they formed by the if else cases
	 */
	std::ofstream outfile("ch_push_res_of_all_cases.txt");
	int cas = 26;
	while( cas <= 35 )
	{
		if( cas == 1 )
		{	
			//this is the case where we have an empty list and we add 
			//a point
			outfile << "-------------------------------\n";
			outfile << "case 1\n";
			CH2d_dlclist a;
			outfile << "The list is empty" << "\n";
			outfile << "Addition of the point " << Point2d(1,10) << " : " << a.push(Point2d(1,10))  << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
			
		}else if( cas == 3 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 3\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,2) << " : " << a.push(Point2d(-1,2)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 4 )
		{
			//below we have cases where we have a list with one point and we add another one
			outfile << "-------------------------------\n";
			outfile << "case 4\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,3) << " : " << a.push(Point2d(-1,3)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 5 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 5\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,-4) << " : " << a.push(Point2d(-1,-4)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 6 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 6\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(1,2) << " : " << a.push(Point2d(1,2)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 7 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 7\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-3,2) << " : " << a.push(Point2d(-3,2)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
			//this is the last case with one point before the addition
		}else if( cas == 8 )
		{
			//this is the case where we have two points in the list and we add another one
			outfile << "-------------------------------\n";
			outfile << "case 8\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(-1,5));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,3) << " : " << a.push(Point2d(-1,3)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 9 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 9\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(-1,5));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,2) << " : " << a.push(Point2d(-1,2)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 10 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 10\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(-1,5));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,5) << " : " << a.push(Point2d(-1,5)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 11 )
		{
			outfile << "-------------------------------\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(-1,5));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,6) << " : " << a.push(Point2d(-1,6)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 12 )
		{
			outfile << "-------------------------------\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(-1,5));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-1,-1) << " : " << a.push(Point2d(-1,-1)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 13 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 13\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(-1,5));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(10,5) << " : " << a.push(Point2d(10,5)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 14 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 14\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(-1,2));
			vec.push_back(Point2d(-1,5));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(-4,5) << " : " << a.push(Point2d(-4,5)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 15 )
		{
			//in this case we have three points to the list and we add another one
			outfile << "-------------------------------\n";
			outfile << "case 15(THERE IS A BUG)\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(0,0) << " : " << a.push(Point2d(0,0)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 16 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 16\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(1,0) << " : " << a.push(Point2d(1,0)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 17 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 17\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(1,1) << " : " << a.push(Point2d(1,1)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 18 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 18\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(0.5,0.5) << " : " << a.push(Point2d(0.5,0.5)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 19 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 19\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(1,0.5) << " : " << a.push(Point2d(1,0.5)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 20 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 20\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(0.5,0) << " : " << a.push(Point2d(0.5,0)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 21 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 21\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(0.5,0.25) << " : " << a.push(Point2d(0.5,0.25)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 22 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 22\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist a(vec,"Jarvis");
			print_state_ch2d(outfile,a);
			outfile << "Addition of the point " << Point2d(1,3) << " : " << a.push(Point2d(1,3)) << "\n";
			print_state_ch2d(outfile,a);
			outfile << "-------------------------------\n";
		}else if( cas == 23 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 23\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist ch(vec,"Jarvis");
			print_state_ch2d(outfile,ch);
			outfile << "Addition of the point " << Point2d(1,-0.5) << " : " << ch.push(Point2d(1,-0.5)) << "\n";
			print_state_ch2d(outfile,ch);
			outfile << "-------------------------------\n";
		}else if( cas == 24 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 24\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(1,0));
			vec.push_back(Point2d(1,1));
			CH2d_dlclist ch(vec,"Jarvis");
			print_state_ch2d(outfile,ch);
			outfile << "Addition of the point " << Point2d(-1,1) << " : " << ch.push(Point2d(-1,1)) << "\n";
			print_state_ch2d(outfile,ch);
			outfile << "-------------------------------\n";
		}else if( cas == 25 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 25\n";
			std::ifstream infile("sets_of_points.txt");
			double a;
			double b;
			std::string tmp;
			std::vector<Point2d> vec;
			while( infile >> tmp >> a >> tmp >> b >> tmp)
			{
				vec.push_back(Point2d(a,b));
			}
			CH2d_dlclist ch;
			int count_added = 0;
			int size_vec = vec.size();
			for(int i = 0; i < size_vec; i++)
			{
				int resul_of_add ; 
				if ( i < -1 )
				{
					//std::cout << "--------------------------------------\n";
					std::cout << "Addition of the point " << vec[i] << " : " <<  (resul_of_add = ch.push(vec[i]))  << "\n";
					if( resul_of_add == 1 )
					{
						count_added++;
					}
				}else
				{
					ch.push(vec[i]);
				}
			}
			std::cout << "Number of points added : " << count_added << "\n";
			print_state_ch2d(outfile,ch);
			outfile << "-------------------------------\n";
		}else if ( cas == 26 )
		{
			outfile << "-------------------------------\n";
			outfile << "case 26\n";
			CH2d_dlclist ch;
			ch.push(Point2d(0,0));
			ch.push(Point2d(1,1));
			ch.push(Point2d(0,1));
			ch.push(Point2d(1,0));
			ch.push(Point2d(-1,0.5));
			print_state_ch2d(std::cout,ch);
			outfile << "-------------------------------\n";
		}
			
		cas++;
	}
	outfile.close();
	
	/*
	 *  end of the cases
	 */
	
	/* The below is using a random generator of points in (0,1) 
	 * and pushes all of the point in the convex hull
	std::ifstream infile("sets_of_points.txt");
	std::ofstream outfile("convex_hull_res.txt");
	double a;
	double b;
	std::string tmp;
	std::vector<Point2d> vec1;
	while (infile >> tmp >> a  >> tmp >>  b >> tmp)
	{
		vec1.push_back(Point2d(a,b));
	}
	CH2d_dlclist a1;
	
	int size = vec1.size();
	for( int i = 0 ; i < size; i++ )
	{
		a1.push(vec1[i]);
	}
	
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
	/* /*end of one of the debugging code*/
	
	
	
	std::cout << "\n";
	std::cout << "End-----Testing: void push(Point2d )----------" << "\n\n";
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
	int cas = 2;
	
	while( cas <= 25)
	{
		if( cas == 1)
		{
			// this test reads from the file "sets_of_points.txt"
			// and write the resulted convex hull to "convex_hull_res.txt"
			std::ifstream infile("sets_of_points.txt");
			std::ofstream outfile("convex_hull_res.txt");
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
		}else if( cas == 2 )
		{
			std::cout  << "This shows that the CH2d_dlclist(points,algorithm) doesn't work for \"points\" with duplicate points\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(2,1));
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(0.5,-2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(2,1));
			CH2d_dlclist ch(vec,"Jarvis");
			
			print_state_ch2d(std::cout, ch);
			
		}else if( cas == 3 )
		{
			std::cout  << "This shows that the CH2d_dlclist(points,algorithm) doesn't work for \"points\" with duplicate points\n";
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0.5,-2));
			vec.push_back(Point2d(2,1));
			vec.push_back(Point2d(0.5,-2));
			vec.push_back(Point2d(0.5,-2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(0.5,-2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(2,1));
			vec.push_back(Point2d(0,0));
			CH2d_dlclist ch(vec,"Jarvis");
			
		}
		cas++;
	}	

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



