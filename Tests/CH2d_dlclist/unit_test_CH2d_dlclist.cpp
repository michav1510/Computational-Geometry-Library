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
	while( cas <= 100)
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
			//one point is added to a convex hull(list) with two points that lie on the same vertical line
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
			//one point is added to a convex hull(list) with two points that lie on the same vertical line
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
			//one point is added to a convex hull(list) with two points that lie on the same vertical line
			// the new point has smaller x than the head
			bool test_pass12 = false;
			std::vector<Point2d> vec12;
			Point2d a12(1,0);
			Point2d b12(1,1);
			vec12.push_back(a12);
			vec12.push_back(b12);
			
			CH2d_dlclist ch12(vec12);
			
			Point2d c12(-1,0);
			if(ch12.push(c12) == 1)
			{
				// then the point was added
				if(*ch12.begin() == c12)
				{
					// then the head is correct
					if(*ch12.end() == a12)
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it12 = ch12.begin();
						if( *it12 == c12 && *(it12+1) == b12 && *(it12+2) == a12
							&& *(it12+3) == c12  && *(it12-1) == a12 
							&& *(it12-2) == b12 && *(it12-3) == c12)
						{
							// then the linkage is correct
							if(ch12.size() == 3 && ch12.area() == 1)
							{
								//then the size and the area are correct
								test_pass12 = true;
							}
						}
					}
				}
			}
			
			if(test_pass12 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 13)
		{
			//one point is added to a convex hull(list) with two points that don't lie on the same vertical line
			// the new point has smaller x than the head
			bool test_pass13 = false;
			std::vector<Point2d> vec13;
			Point2d a13(0,0);
			Point2d b13(1,1);
			vec13.push_back(a13);
			vec13.push_back(b13);
			
			CH2d_dlclist ch13(vec13);
			
			Point2d c13(-1,0);
			if(ch13.push(c13) == 1)
			{
				// then the point was added
				if(*ch13.begin() == c13)
				{
					// then the head is correct
					if(*ch13.end() == b13)
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it13 = ch13.begin();
						if( *it13 == c13 && *(it13+1) == b13 && *(it13+2) == a13
							&& *(it13+3) == c13  && *(it13-1) == a13 
							&& *(it13-2) == b13 && *(it13-3) == c13)
						{
							// then the linkage is correct
							if(ch13.size() == 3 && ch13.area() == 0.5)
							{
								//then the size and the area are correct
								test_pass13 = true;
							}
						}
					}
				}
			}
			
			if(test_pass13 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 14)
		{
			//one point is added to a convex hull(list) with two points that don't lie on the same vertical line
			// the new point has smaller x than the head
			bool test_pass14 = false;
			std::vector<Point2d> vec14;
			vec14.push_back(Point2d(0,1));
			vec14.push_back(Point2d(1,0));
			
			CH2d_dlclist ch14(vec14);
			
			
			if(ch14.push(Point2d(-1,0)) == 1)
			{
				// then the point was added
				if(*ch14.begin() == Point2d(-1,0))
				{
					// then the head is correct
					if(*ch14.end() == Point2d(1,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it14 = ch14.begin();
						if( *it14 == Point2d(-1,0) && *(it14+1) == Point2d(0,1) && *(it14+2) == Point2d(1,0)
							&& *(it14+3) == Point2d(-1,0)  && *(it14-1) == Point2d(1,0) 
							&& *(it14-2) == Point2d(0,1) && *(it14-3) == Point2d(-1,0))
						{
							// then the linkage is correct
							if(ch14.size() == 3 && ch14.area() == 1)
							{
								//then the size and the area are correct
								test_pass14 = true;
							}
						}
					}
				}
			}
			
			if(test_pass14 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
		}else if(cas == 15)
		{
			//one point is added to a convex hull(list) with two points that don't lie on the same vertical line
			// the new point has bigger x than the tail
			bool test_pass15 = false;
			std::vector<Point2d> vec15;
			vec15.push_back(Point2d(-1,0));
			vec15.push_back(Point2d(0,1));
			
			CH2d_dlclist ch15(vec15);
			
			
			if(ch15.push(Point2d(1,0)) == 1)
			{
				// then the point was added
				if(*ch15.begin() == Point2d(-1,0))
				{
					// then the head is correct
					if(*ch15.end() == Point2d(1,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it15 = ch15.begin();
						if( *it15 == Point2d(-1,0) && *(it15+1) == Point2d(0,1) && *(it15+2) == Point2d(1,0)
							&& *(it15+3) == Point2d(-1,0)  && *(it15-1) == Point2d(1,0) 
							&& *(it15-2) == Point2d(0,1) && *(it15-3) == Point2d(-1,0))
						{
							// then the linkage is correct
							if(ch15.size() == 3 && ch15.area() == 1)
							{
								//then the size and the area are correct
								test_pass15 = true;
							}
						}
					}
				}
			}
			
			if(test_pass15 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
			
			
		}else if(cas == 16)
		{
			//one point is added to a convex hull(list) with two points that don't lie on the same vertical line
			// the new point has bigger x than the tail
			bool test_pass16 = false;
			std::vector<Point2d> vec16;
			vec16.push_back(Point2d(-1,0));
			vec16.push_back(Point2d(0,-1));
			
			CH2d_dlclist ch16(vec16);
			
			
			if(ch16.push(Point2d(1,0)) == 1)
			{
				// then the point was added
				if(*ch16.begin() == Point2d(-1,0))
				{
					// then the head is correct
					if(*ch16.end() == Point2d(1,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it16 = ch16.begin();
						if( *it16 == Point2d(-1,0) && *(it16+1) == Point2d(1,0) && *(it16+2) == Point2d(0,-1)
							&& *(it16+3) == Point2d(-1,0)  && *(it16-1) == Point2d(0,-1) 
							&& *(it16-2) == Point2d(1,0) && *(it16-3) == Point2d(-1,0))
						{
							// then the linkage is correct
							if(ch16.size() == 3 && ch16.area() == 1)
							{
								//then the size and the area are correct
								test_pass16 = true;
							}
						}
					}
				}
			}
			
			if(test_pass16 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 17)
		{
			//one point is added to a convex hull(list) with two points that don't lie on the same vertical line
			//the new point doesn't substitute the head nor the tail
			bool test_pass17 = false;
			std::vector<Point2d> vec17;
			vec17.push_back(Point2d(-1,0));
			vec17.push_back(Point2d(1,0));
			
			CH2d_dlclist ch17(vec17);
			
			
			if(ch17.push(Point2d(0,1)) == 1)
			{
				// then the point was added
				if(*ch17.begin() == Point2d(-1,0))
				{
					// then the head is correct
					if(*ch17.end() == Point2d(1,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it17 = ch17.begin();
						if( *it17 == Point2d(-1,0) && *(it17+1) == Point2d(0,1) && *(it17+2) == Point2d(1,0)
							&& *(it17+3) == Point2d(-1,0)  && *(it17-1) == Point2d(1,0) 
							&& *(it17-2) == Point2d(0,1) && *(it17-3) == Point2d(-1,0))
						{
							// then the linkage is correct
							if(ch17.size() == 3 && ch17.area() == 1)
							{
								//then the size and the area are correct
								test_pass17 = true;
							}
						}
					}
				}
			}
			
			if(test_pass17 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 18)
		{
			//one point is added to a convex hull(list) with two points that don't lie on the same vertical line
			//the new point doesn't substitute the head nor the tail
			bool test_pass18 = false;
			std::vector<Point2d> vec18;
			vec18.push_back(Point2d(-1,0));
			vec18.push_back(Point2d(1,0));
			
			CH2d_dlclist ch18(vec18);
			
			
			if(ch18.push(Point2d(0,-1)) == 1)
			{
				// then the point was added
				if(*ch18.begin() == Point2d(-1,0))
				{
					// then the head is correct
					if(*ch18.end() == Point2d(1,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it18 = ch18.begin();
						if( *it18 == Point2d(-1,0) && *(it18+1) == Point2d(1,0) && *(it18+2) == Point2d(0,-1)
							&& *(it18+3) == Point2d(-1,0)  && *(it18-1) == Point2d(0,-1) 
							&& *(it18-2) == Point2d(1,0) && *(it18-3) == Point2d(-1,0))
						{
							// then the linkage is correct
							if(ch18.size() == 3 && ch18.area() == 1)
							{
								//then the size and the area are correct
								test_pass18 = true;
							}
						}
					}
				}
			}
			
			if(test_pass18 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 19)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 1
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(-4,0.5)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(-4,0.5))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(-4,0.5) && *(it+1) == Point2d(1,2) && *(it+2) == Point2d(2,2) 
							&& *(it+3) == Point2d(3,1) && *(it+4) == Point2d(3,0) && *(it+5) == Point2d(2,-1)
							&& *(it+6) == Point2d(1,-1) && *(it+7) == Point2d(-4,0.5) 
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(2,2) && *(it-6) == Point2d(1,2)
							&& *(it-7) == Point2d(-4,0.5))
						{
							// then the linkage is correct
							if(ch.size() == 7 && ch.area() == 12.5)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 20)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 2
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(0,2)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,2) && *(it+2) == Point2d(2,2) 
							&& *(it+3) == Point2d(3,1) && *(it+4) == Point2d(3,0) && *(it+5) == Point2d(2,-1)
							&& *(it+6) == Point2d(1,-1) && *(it+7) == Point2d(0,0) && *(it-1) == Point2d(1,-1)
							&& *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) && *(it-4) == Point2d(3,1) 
							&& *(it-5) == Point2d(2,2) && *(it-6) == Point2d(0,2) && *(it-7) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 7  && ch.area() == 7.5)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}
		
		else if(cas == 21)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 3
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(0,0.5)) == -1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(3,1) && *(it+5) == Point2d(3,0) 
							&& *(it+6) == Point2d(2,-1) && *(it+7) == Point2d(1,-1) && *(it+8) == Point2d(0,0)
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(2,2) && *(it-6) == Point2d(1,2)
							&& *(it-7) == Point2d(0,1) && *(it-8) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 8 && ch.area() == 7 )
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 22)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 4
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(0,-1)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,-1))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,-1) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(3,1) && *(it+5) == Point2d(3,0) 
							&& *(it+6) == Point2d(2,-1) && *(it+7) == Point2d(0,-1) 
							&& *(it-1) == Point2d(2,-1) && *(it-2) == Point2d(3,0) && *(it-3) == Point2d(3,1) 
							&& *(it-4) == Point2d(2,2) && *(it-5) == Point2d(1,2) && *(it-6) == Point2d(0,1)
							&& *(it-7) == Point2d(0,-1))
						{
							// then the linkage is correct
							if(ch.size() == 7 && ch.area() == 7.5)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 22)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 5
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(0.5,1.5)) == -1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(3,1) && *(it+5) == Point2d(3,0) 
							&& *(it+6) == Point2d(2,-1) && *(it+7) == Point2d(1,-1) && *(it+8) == Point2d(0,0)
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(2,2) && *(it-6) == Point2d(1,2) 
							&& *(it-7) == Point2d(0,1) && *(it-8) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 8 && ch.area() == 7)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 23)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 6
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(1.5,2.5)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1.5,2.5) 
							&& *(it+3) == Point2d(3,1) && *(it+4) == Point2d(3,0) && *(it+5) == Point2d(2,-1) 
							&& *(it+6) == Point2d(1,-1) && *(it+7) == Point2d(0,0) 
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(1.5,2.5) && *(it-6) == Point2d(0,1)
							&& *(it-7) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 7 && ch.area() == 7.25 )
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 24)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 7
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(2.5,-0.5)) == -1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(3,1) && *(it+5) == Point2d(3,0) 
							&& *(it+6) == Point2d(2,-1) && *(it+7) == Point2d(1,-1) && *(it+8) == Point2d(0,0)
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(2,2) && *(it-6) == Point2d(1,2) 
							&& *(it-7) == Point2d(0,1) && *(it-8) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 8  && ch.area() == 7)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 25)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 8
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(1.5,-5)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(3,1) && *(it+5) == Point2d(3,0) 
							&& *(it+6) == Point2d(1.5,-5) && *(it+7) == Point2d(0,0) 
							&& *(it-1) == Point2d(1.5,-5) && *(it-2) == Point2d(3,0) && *(it-3) == Point2d(3,1) 
							&& *(it-4) == Point2d(2,2) && *(it-5) == Point2d(1,2) && *(it-6) == Point2d(0,1)
							&& *(it-7) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 7  && ch.area() == 12.5)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 26)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 9
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(3,0.5)) == -1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(3,1) && *(it+5) == Point2d(3,0) 
							&& *(it+6) == Point2d(2,-1) && *(it+7) == Point2d(1,-1) && *(it+8) == Point2d(0,0)
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(2,2) && *(it-6) == Point2d(1,2) 
							&& *(it-7) == Point2d(0,1) && *(it-8) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 8  && ch.area() == 7)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 27)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 10
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(10,0.5)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(10,0.5))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(10,0.5) && *(it+5) == Point2d(2,-1) 
							&& *(it+6) == Point2d(1,-1) && *(it+7) == Point2d(0,0) 
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(10,0.5) 
							&& *(it-4) == Point2d(2,2) && *(it-5) == Point2d(1,2) && *(it-6) == Point2d(0,1)
							&& *(it-7) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 7 && ch.area() == 17 )
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 28)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 11
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(3,2)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(3,2) && *(it+4) == Point2d(3,0) && *(it+5) == Point2d(2,-1) 
							&& *(it+6) == Point2d(1,-1) && *(it+7) == Point2d(0,0) 
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,2) && *(it-5) == Point2d(1,2) && *(it-6) == Point2d(0,1)
							&& *(it-7) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 7  && ch.area() == 7.5)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 29)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 12
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(3,-0.5)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(0,0))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,-0.5))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(0,0) && *(it+1) == Point2d(0,1) && *(it+2) == Point2d(1,2) 
							&& *(it+3) == Point2d(2,2) && *(it+4) == Point2d(3,1) && *(it+5) == Point2d(3,-0.5) 
							&& *(it+6) == Point2d(2,-1) && *(it+7) == Point2d(1,-1) && *(it+8) == Point2d(0,0)
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,-0.5) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(2,2) && *(it-6) == Point2d(1,2)
							&& *(it-7) == Point2d(0,1) && *(it-8) == Point2d(0,0))
						{
							// then the linkage is correct
							if(ch.size() == 8 && ch.area() == 7.25)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}else if(cas == 30)
		{
			//one point is added to a convex hull that contains 8 points 
			//case 13
			bool test_pass = false;
			std::vector<Point2d> vec;
			vec.push_back(Point2d(0,0));
			vec.push_back(Point2d(0,1));
			vec.push_back(Point2d(1,2));
			vec.push_back(Point2d(2,2));
			vec.push_back(Point2d(3,1));
			vec.push_back(Point2d(3,0));
			vec.push_back(Point2d(2,-1));
			vec.push_back(Point2d(1,-1));
			
			CH2d_dlclist ch(vec);
			
			if(ch.push(Point2d(-0.5,0.5)) == 1)
			{
				// then the point was added
				if(*ch.begin() == Point2d(-0.5,0.5))
				{
					// then the head is correct
					if(*ch.end() == Point2d(3,0))
					{
						//then the tail is correct
						CH2d_dlclist::ch_iterator it = ch.begin();
						if( *it == Point2d(-0.5,0.5) && *(it+1) == Point2d(1,2) && *(it+2) == Point2d(2,2) 
							&& *(it+3) == Point2d(3,1) && *(it+4) == Point2d(3,0) && *(it+5) == Point2d(2,-1) 
							&& *(it+6) == Point2d(1,-1) && *(it+7) == Point2d(-0.5,0.5) 
							&& *(it-1) == Point2d(1,-1) && *(it-2) == Point2d(2,-1) && *(it-3) == Point2d(3,0) 
							&& *(it-4) == Point2d(3,1) && *(it-5) == Point2d(2,2) && *(it-6) == Point2d(1,2)
							&& *(it-7) == Point2d(-0.5,0.5) )
						{
							// then the linkage is correct
							if(ch.size() == 7  && ch.area() == 7.25)
							{
								//then the size and the area are correct
								test_pass = true;
							}
						}
					}
				}
			}
			
			if(test_pass == true)
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


int main(int argc, char* argv[])
{
	
	test_parameter_constructor1(std::cout);
	test_push(std::cout);
}