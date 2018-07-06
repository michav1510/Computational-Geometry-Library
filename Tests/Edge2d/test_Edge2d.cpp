#include<iostream>
#include<vector>
#include<random>
#include"../../Point2d.hpp"
#include"../../Edge2d.hpp"

void test_parameter_constructor_and_get_points(std::ostream& write_str);
void test_copy_constructor(std::ostream& write_str);
void test_IsNeighbour(std::ostream& write_str);
void test_GetPoints();


int main(int argc, char *argv[])
{
	test_parameter_constructor_and_get_points(std::cout);
	test_copy_constructor(std::cout);
	test_IsNeighbour(std::cout);
}




void test_parameter_constructor_and_get_points(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "Edge2d(const Point2d& p1, const Point2d& p2) and :\n"; 
	write_str << "std::vector<Point2d> GetPoints() const :\n";
		

	int numberofexperim = 1000;
	int numberofpassed = 0;
	int cas = 1;
	while(cas <= numberofexperim)
	{
		std::random_device r;
		std::default_random_engine eng{r()};
		std::uniform_real_distribution<double> urd(100000000000000000-1,100000000000000000);
		double num1 = urd(eng);
		double num2 = urd(eng);
		double num3 = urd(eng);
		double num4 = urd(eng);
		Edge2d ed(Point2d(num1,num2),Point2d(num3,num4));
		std::vector<Point2d> points = ed.GetPoints();
		if(points[0]== Point2d(num1,num2) && points[1] == Point2d(num3,num4) )
		{
			numberofpassed++;
		}
			
		cas++;
	}
	
	write_str << "Number of tests were done: " << numberofexperim  << "\n";
	write_str << "Percentage of tests were passed: " << (numberofpassed/numberofexperim)*100 << "%" <<"\n";


	write_str << "\n\n";

}


void test_copy_constructor(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "Edge2d(const Point2d& p1, const Point2d& p2) :\n"; 
	
	int numberofexperim = 1000;
	int numberofpassed = 0;
	int cas = 1;
	while(cas <= numberofexperim)
	{
		std::random_device r;
		std::default_random_engine eng{r()};
		std::uniform_real_distribution<double> urd(1000000000000000-1,1000000000000000);
		double num1 = urd(eng);
		double num2 = urd(eng);
		double num3 = urd(eng);
		double num4 = urd(eng);
		Edge2d ed1(Point2d(num1,num2),Point2d(num3,num4));
		Edge2d ed2(ed1);
		std::vector<Point2d> poi1 = ed1.GetPoints();
		std::vector<Point2d> poi2 = ed2.GetPoints();
		if( poi1[0] == poi2[0] && poi1[1] == poi2[1] )
		{
			numberofpassed++;
		}
			
		cas++;
	}
	
	write_str << "Number of tests were done: " << numberofexperim  << "\n";
	write_str << "Percentage of tests were passed: " << (numberofpassed/numberofexperim)*100 << "%" <<"\n";


	write_str << "\n\n";
}


void test_IsNeighbour(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "bool IsNeighbour(const Edge2d& other_edge) :\n"; 
	
	int numberofexperim = 1000;
	int numberofpassed = 0;
	int cas = 1;
	while(cas <= numberofexperim)
	{
		std::random_device r;
		std::default_random_engine eng{r()};
		std::uniform_real_distribution<double> urd(1000000000000000-1,1000000000000000);
		double num1 = urd(eng);
		double num2 = urd(eng);
		double num3 = urd(eng);
		double num4 = urd(eng);
		
		if( 0 )
		{
			numberofpassed++;
		}
			
		cas++;
	}
	
	write_str << "Number of tests were done: " << numberofexperim  << "\n";
	write_str << "Percentage of tests were passed: " << (numberofpassed/numberofexperim)*100 << "%" <<"\n";
	
	write_str << "\n\n";
}



