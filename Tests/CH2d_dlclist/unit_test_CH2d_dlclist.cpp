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
	write_str << "CH2d_dlclist(const std::vector<Point2d>& , std::string algorithm = \"Jarvis\")\n\n";
	
	int cas = 1;
	
	while( cas <= 25)
	{
		if( cas == 1)
		{
			bool test_pass = false;
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
						test_pass = true;
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
		}
			
		cas++;
	}
	
}



int main(int argc, char* argv[])
{
	
	test_parameter_constructor1(std::cout);
	
}