/**
 *  This test was written in order to get a simple answer if some trivial cases passed, if you change something 
 *  to the code and you want a clear answer if something was affected by the change. You don't have to recall 
 *  what the result must be in the test and you see simple fail or pass to a test.
 * 
 */

#include <iostream>
#include <fstream>
#include "../../CH2d_dlclist.hpp"
#include "../../Point2d.hpp"



/**
 *  Tests the constructor "CH2d_dlclist(const std::vector<Point2d>& , std::string algorithm = \" Jarvis \" )"
 *  @param write_str It is the stream where you want the output to be written.
 */
void test_parameter_constructor1(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "CH2d_dlclist(const std::vector<Point2d>& , std::string algorithm = \"Jarvis\")\n";
	
	int cas = 1;
	
	while( cas <= 25)
	{
		if( cas == 1)
		{
			bool test_pass1 = false;
			std::vector<Point2d> vec1;
			vec1.push_back(Point2d(0,0));
			
			CH2d_dlclist ch1(vec1,"Jarvis");
			if(*ch1.begin() == Point2d(0,0))
			{
				// then the head points to the correct Point2d
				if(*ch1.begin() == *ch1.end())
				{
					//then the head points where the tail points
					if(ch1.size() == 1 && ch1.area() == 0)
					{
						//then the size and the area is correct
						test_pass1 = true;
					}
					
				}
			}
			if(test_pass1 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 2)
		{
			bool test_pass2 = false;
			std::vector<Point2d> vec2;
			vec2.push_back(Point2d(2,0));
			vec2.push_back(Point2d(2,1));
			
			CH2d_dlclist ch2(vec2,"Jarvis");
			if(*ch2.begin() == Point2d(2,0))
			{
				//then the head is correct
				if(*ch2.end() == Point2d(2,1))
				{
					CH2d_dlclist::ch_iterator it2(ch2.begin());
					if(*(it2+1)== Point2d(2,1) && *(it2-1) == Point2d(2,1) && *(it2+2) == Point2d(2,0)
						&& *(it2-2) == Point2d(2,0))
					{
						// then the linkage is correct
						if(ch2.size() == 2 && ch2.area()== 0)
						{
							//then the size and the area are correct
							test_pass2 = true;
						}
					}
				}
			}
			if(test_pass2 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 3)
		{
			bool test_pass3 = false;
			std::vector<Point2d> vec3;
			vec3.push_back(Point2d(0,0));
			vec3.push_back(Point2d(1,1));
			vec3.push_back(Point2d(1,0));
			
			CH2d_dlclist ch3(vec3,"Jarvis");
			if(*ch3.begin() == Point2d(0,0))
			{
				// then the head is correct
				if(*ch3.end() == Point2d(1,0))
				{
					// then the tail is correct
					CH2d_dlclist::ch_iterator iter3(ch3.begin());
					if(*(iter3) == Point2d(0,0) && *(iter3+1) == Point2d(1,1) && *(iter3+2)== Point2d(1,0) 
						&& *(iter3+3)== Point2d(0,0) && *(iter3-1) == Point2d(1,0) && *(iter3-2) == Point2d(1,1) 
						&& *(iter3-3)== Point2d(0,0))
					{
						// then the linkage between the nodes is correct
						if(ch3.size() == 3 && ch3.area() == 0.5)
						{
							//then the size and the area are correct
							test_pass3 = true;
						}
					}
				}
			}
			if(test_pass3 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 4)
		{ 
			bool test_pass4 = false;
			std::vector<Point2d> vec4;
			vec4.push_back(Point2d(0,0));
			vec4.push_back(Point2d(1,1));
			vec4.push_back(Point2d(2,1));
			vec4.push_back(Point2d(3,0));
			
			CH2d_dlclist ch4(vec4,"Jarvis");
			if( *ch4.begin() == Point2d(0,0) )
			{
				// then the head is correct
				if(*ch4.end() == Point2d(3,0))
				{
					// then the tail is correct
					CH2d_dlclist::ch_iterator iter4(ch4.begin());
					if(*iter4 == Point2d(0,0) && *(iter4+1) == Point2d(1,1) && *(iter4+2) == Point2d(2,1) &&
						*(iter4+3) == Point2d(3,0) && *(iter4+4) == Point2d(0,0) && *(iter4-1) == Point2d(3,0)
						&& *(iter4-2) == Point2d(2,1) && *(iter4-3) == Point2d(1,1) && *(iter4-4) == Point2d(0,0) )
					{
						// then the linkage between the nodes is correct
						if(ch4.size() == 4 && ch4.area()== 2)
						{
							//then the size and the area are correct
							test_pass4 = true;
						}
					}
				}
			}	
			
			if(test_pass4 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 5)
		{ 
			bool test_pass5 = false;
			std::vector<Point2d> vec5;
			vec5.push_back(Point2d(0,0));
			vec5.push_back(Point2d(1,1));
			vec5.push_back(Point2d(2,2));
			vec5.push_back(Point2d(3,1));
			vec5.push_back(Point2d(2,0));
			
			CH2d_dlclist ch5(vec5,"Jarvis");
			if( *ch5.begin() == Point2d(0,0) )
			{
				// then the head is correct
				if( *ch5.end() == Point2d(3,1))
				{
					// then the tail is correct
					CH2d_dlclist::ch_iterator iter5(ch5.begin());
					if(*iter5 == Point2d(0,0) && *(iter5+1) == Point2d(2,2) && *(iter5+2) == Point2d(3,1) &&
						*(iter5+3) == Point2d(2,0) && *(iter5+4) == Point2d(0,0) && *(iter5-1) == Point2d(2,0)
						&& *(iter5-2) == Point2d(3,1) && *(iter5-3) == Point2d(2,2) && *(iter5-4) == Point2d(0,0) )
					{
						// then the linkage between the nodes is correct
						if( ch5.size() == 4 && ch5.area() == 3)
						{		
							//then the size and the area are correct
							test_pass5 = true;
						}
					}
				}
			}
			if(test_pass5 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 6)
		{ 
			bool test_pass6 = false;
			std::vector<Point2d> vec6;
			
			CH2d_dlclist ch6(vec6);
			if(ch6.size() == 0 && ch6.area() == 0 )
			{
				//then the size and the area are correct
				test_pass6 = true;
			}
			if(test_pass6 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}
		
		cas++;
	}
	write_str << "\n\n";
}


/**
 *  Tests the  "int push(const Point2d& )"
 *  @param write_str It is the stream where you want the output to be written.
 */
void test_push(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "int push(const Point2d& )\n";
	
	
	int cas = 1;
	while( cas <= 25)
	{
		if(cas == 1)
		{
			//one point is added to the empty convex hull(list)
			bool test_pass1 = false;
			std::vector<Point2d> vec1;
			
			CH2d_dlclist ch1(vec1,"Jarvis");
			
			if(ch1.push(Point2d(0,0)) == 1)
			{
				// then the point was added
				if(*ch1.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch1.end() == Point2d(0,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it1 = ch1.begin();
						if( *it1 == Point2d(0,0) && *(it1+1) == Point2d(0,0) && *(it1-1) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch1.size() == 1 && ch1.area() == 0)
							{
								//then the size and the area are correct
								test_pass1 = true;
							}
						}
					}
				}
			}
			if(test_pass1 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 2)
		{
			//one point is added to a convex hull(list) with one point
			//the new point has bigger x of the current
			bool test_pass2 = false;
			std::vector<Point2d> vec2;
			vec2.push_back(Point2d(5,1));
			
			CH2d_dlclist ch2(vec2,"Jarvis");
			
			if(ch2.push(Point2d(10,2)) == 1);
			{
				//then the point was added
				if(*ch2.begin() == Point2d(5,1))
				{
					// then the head is correct
					if(*ch2.end() == Point2d(10,2))
					{
						// then the tail is correct
						CH2d_dlclist::ch_iterator it2(ch2.begin());
						if(*it2 == Point2d(5,1) && *(it2+1) == Point2d(10,2) && *(it2+2) == Point2d(5,1) &&
							*(it2-1) == Point2d(10,2) && *(it2-2) == Point2d(5,1))
						{
							// then the linkage is correct
							if(ch2.size() == 2 && ch2.area() == 0)
							{
								//then the size and the area are correct
								test_pass2 = true;
							}
						}
					}
				}
				
			}
			
			
			if(test_pass2 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 3)
		{
			//one point is added to a convex hull(list) with one point
			//the new point is on the same vertical position but smaller y of the current
			bool test_pass3 = false;
			std::vector<Point2d> vec3;
			vec3.push_back(Point2d(5,1));
			
			CH2d_dlclist ch3(vec3,"Jarvis");
			
			if(ch3.push(Point2d(5,0)) == 1);
			{
				//then the point was added
				if(*ch3.begin() == Point2d(5,0))
				{
					// then the head is correct
					if(*ch3.end() == Point2d(5,1))
					{
						// then the tail is correct
						CH2d_dlclist::ch_iterator it3(ch3.begin());
						if(*it3 == Point2d(5,0) && *(it3+1) == Point2d(5,1) && *(it3+2) == Point2d(5,0) &&
							*(it3-1) == Point2d(5,1) && *(it3-2) == Point2d(5,0))
						{
							// then the linkage is correct
							if(ch3.size() == 2 && ch3.area() == 0)
							{
								//then the size and the area are correct
								test_pass3 = true;
							}
						}
					}
				}
				
			}
			
			
			if(test_pass3 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
			
		}else if(cas == 4)
		{
			//one point is added to a convex hull(list) with one point
			//the new point is on the same vertical position but greater y of the current
			bool test_pass4 = false;
			std::vector<Point2d> vec4;
			vec4.push_back(Point2d(5,1));
			
			CH2d_dlclist ch4(vec4,"Jarvis");
			
			if(ch4.push(Point2d(5,10)) == 1)
			{
				// then the point was added
				if(*ch4.begin() == Point2d(5,1))
				{
					// then the head is correct
					if(*ch4.end() == Point2d(5,10))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it4 = ch4.begin();
						if( *it4 == Point2d(5,1) && *(it4+1) == Point2d(5,10) && *(it4+2) == Point2d(5,1)
							&& *(it4-1) == Point2d(5,10) && *(it4-2) == Point2d(5,1))
						{
							// then the linkage is correct
							if(ch4.size() == 2 && ch4.area() == 0)
							{
								//then the size and the area are correct
								test_pass4 = true;
							}
						}
					}
				}
			}
							
			if(test_pass4 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 5)
		{
			//one point is added to a convex hull(list) with two points
			//the new point must be equal to the head of the convex hull
			bool test_pass5 = false;
			std::vector<Point2d> vec5;
			vec5.push_back(Point2d(5,1));
			vec5.push_back(Point2d(3,2));
			
			CH2d_dlclist ch5(vec5,"Jarvis");
			
			if(ch5.push(Point2d(3,2)) == -1)
			{
				// then the point was added
				if(*ch5.begin() == Point2d(3,2))
				{
					// then the head is correct
					if(*ch5.end() == Point2d(5,1))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it5 = ch5.begin();
						if( *it5 == Point2d(3,2) && *(it5+1) == Point2d(5,1) && *(it5+2) == Point2d(3,2)
							&& *(it5-1) == Point2d(5,1) && *(it5-2) == Point2d(3,2))
						{
							// then the linkage is correct
							if(ch5.size() == 2 && ch5.area() == 0)
							{
								//then the size and the area are correct
								test_pass5 = true;
							}
						}
					}
				}
			}
							
			if(test_pass5 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 6)
		{
			//one point is added to a convex hull(list) with two points
			//the new point must be equal to the tail of the convex hull
			bool test_pass6 = false;
			std::vector<Point2d> vec6;
			vec6.push_back(Point2d(5,1));
			vec6.push_back(Point2d(3,2));
			
			CH2d_dlclist ch6(vec6,"Jarvis");
			
			if(ch6.push(Point2d(5,1)) == -1)
			{
				// then the point was added
				if(*ch6.begin() == Point2d(3,2))
				{
					// then the head is correct
					if(*ch6.end() == Point2d(5,1))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it6 = ch6.begin();
						if( *it6 == Point2d(3,2) && *(it6+1) == Point2d(5,1) && *(it6+2) == Point2d(3,2)
							&& *(it6-1) == Point2d(5,1) && *(it6-2) == Point2d(3,2))
						{
							// then the linkage is correct
							if(ch6.size() == 2 && ch6.area() == 0)
							{
								//then the size and the area are correct
								test_pass6 = true;
							}
						}
					}
				}
			}
							
			if(test_pass6 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 7)
		{
			//one point is added to a convex hull(list) with two points
			// the new point must be in the line between them
			bool test_pass7 = false;
			std::vector<Point2d> vec7;
			vec7.push_back(Point2d(0,0));
			vec7.push_back(Point2d(1,1));
			
			CH2d_dlclist ch7(vec7);
			
			if(ch7.push(Point2d(0.1,0.1)) == -1)
			{
				// then the point was added
				if(*ch7.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch7.end() == Point2d(1,1))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it7 = ch7.begin();
						if( *it7 == Point2d(0,0) && *(it7+1) == Point2d(1,1) && *(it7+2) == Point2d(0,0)
							&& *(it7-1) == Point2d(1,1) && *(it7-2) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch7.size() == 2 && ch7.area() == 0)
							{
								//then the size and the area are correct
								test_pass7 = true;
							}
						}
					}
				}
			}
			
			if(test_pass7 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
			
		}else if(cas == 8)
		{
			//one point is added to a convex hull(list) with two points
			// the new point is collinear with the other two points but not in the line 
			//between them and substitutes the head
			bool test_pass8 = false;
			std::vector<Point2d> vec8;
			vec8.push_back(Point2d(0,0));
			vec8.push_back(Point2d(1,1));
			
			CH2d_dlclist ch8(vec8);
			
			if(ch8.push(Point2d(-1,-1)) == 1)
			{
				// then the point was added
				if(*ch8.begin() == Point2d(-1,-1))
				{
					// then the head is correct
					if(*ch8.end() == Point2d(1,1))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it8 = ch8.begin();
						if( *it8 == Point2d(-1,-1) && *(it8+1) == Point2d(1,1) && *(it8+2) == Point2d(-1,-1)
							&& *(it8-1) == Point2d(1,1) && *(it8-2) == Point2d(-1,-1))
						{
							// then the linkage is correct
							if(ch8.size() == 2 && ch8.area() == 0)
							{
								//then the size and the area are correct
								test_pass8 = true;
							}
						}
					}
				}
			}
			
			if(test_pass8 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
			
		}else if(cas == 9)
		{
			//one point is added to a convex hull(list) with two points
			// the new point is collinear with the other two points but not in the line 
			//between them and substitutes the tail
			bool test_pass9 = false;
			std::vector<Point2d> vec9;
			vec9.push_back(Point2d(0,0));
			vec9.push_back(Point2d(1,1));
			
			CH2d_dlclist ch9(vec9);
			
			if(ch9.push(Point2d(2,2)) == 1)
			{
				// then the point was added
				if(*ch9.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch9.end() == Point2d(2,2))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it9 = ch9.begin();
						if( *it9 == Point2d(0,0) && *(it9+1) == Point2d(2,2) && *(it9+2) == Point2d(0,0)
							&& *(it9-1) == Point2d(2,2) && *(it9-2) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch9.size() == 2 && ch9.area() == 0)
							{
								//then the size and the area are correct
								test_pass9 = true;
							}
						}
					}
				}
			}
			
			if(test_pass9 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 10)
		{
			//one point is added to a convex hull(list) with two points tha lie on the same vertical line
			// the new point is collinear with the other two points but not in the line between them and
			// substitutes the head
			bool test_pass10 = false;
			std::vector<Point2d> vec10;
			vec10.push_back(Point2d(1,0));
			vec10.push_back(Point2d(1,1));
			
			CH2d_dlclist ch10(vec10);
			
			if(ch10.push(Point2d(1,-1)) == 1)
			{
				// then the point was added
				if(*ch10.begin() == Point2d(1,-1))
				{
					// then the head is correct
					if(*ch10.end() == Point2d(1,1))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it10 = ch10.begin();
						if( *it10 == Point2d(1,-1) && *(it10+1) == Point2d(1,1) && *(it10+2) == Point2d(1,-1)
							&& *(it10-1) == Point2d(1,1) && *(it10-2) == Point2d(1,-1))
						{
							// then the linkage is correct
							if(ch10.size() == 2 && ch10.area() == 0)
							{
								//then the size and the area are correct
								test_pass10 = true;
							}
						}
					}
				}
			}
			
			if(test_pass10 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
			
			
		}else if(cas == 11)
		{
			//one point is added to a convex hull(list) with two points tha lie on the same vertical line
			// the new point is collinear with the other two points but not in the line between them and
			// substitutes the tail
			bool test_pass11 = false;
			std::vector<Point2d> vec11;
			vec11.push_back(Point2d(1,0));
			vec11.push_back(Point2d(1,1));
			
			CH2d_dlclist ch11(vec11);
			
			if(ch11.push(Point2d(1,2)) == 1)
			{
				// then the point was added
				if(*ch11.begin() == Point2d(1,0))
				{
					// then the head is correct
					if(*ch11.end() == Point2d(1,2))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it11 = ch11.begin();
						if( *it11 == Point2d(1,0) && *(it11+1) == Point2d(1,2) && *(it11+2) == Point2d(1,0)
							&& *(it11-1) == Point2d(1,2) && *(it11-2) == Point2d(1,0))
						{
							// then the linkage is correct
							if(ch11.size() == 2 && ch11.area() == 0)
							{
								//then the size and the area are correct
								test_pass11 = true;
							}
						}
					}
				}
			}
			
			if(test_pass11 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 12)
		{
			//else 583 line
		}
					
		
		cas++;
	}
	

	write_str << "\n\n";
}


int main(int argc, char* argv[])
{
	
	test_parameter_constructor1(std::cout);
	test_push(std::cout);
}