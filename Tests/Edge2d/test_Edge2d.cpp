#include<iostream>
#include<vector>
#include"../../Point2d.hpp"
#include"../../Edge2d.hpp"

void test_parameter_constructor()
{
	std::cout << "\n";
	std::cout << "Start---Testing: parameter constructor----------" << "\n\n"; 
	
	std::cout << "Edge2d a(Point2d(1,1),Point2d(2,2));\n";
	Edge2d a(Point2d(1,1),Point2d(2,2));
	std::cout << "a : " << a << "\n";

	std::cout << "Edge2d b(Point2d(-10,1),Point2d(2,-2));\n";
	Edge2d b(Point2d(-10,1),Point2d(2,-2));
	std::cout << "b : " << b << "\n";
	
	std::cout << "\n" <<"End---Testing: parameter constructor----------" << "\n\n"; 
	std::cout << "\n";
}


void test_copy_constructor()
{
	std::cout << "\n";
	std::cout << "Start---Testing: copy constructor----------" << "\n\n"; 
	
	std::cout << "Edge2d a(Point2d(1,1),Point2d(2,2));\n";
	Edge2d a(Point2d(1,1),Point2d(2,2));
	std::cout << "a : " << a << "\n";
	std::cout << "Edge2d b(a);\n";
	Edge2d b(a);
	std::cout << "b : " << b << "\n";
	std::cout << "Are the addresses of a and b equal ? (&a==&b) : " << (&a==&b) << "\n";
	
	std::cout << "\n" <<"End---Testing: copy constructor----------" << "\n\n"; 
	std::cout << "\n";
}


void test_IsNeighbour()
{
	std::cout << "\n";
	std::cout << "Start---Testing: IsNeighbour function----------" << "\n\n"; 
	
	std::cout << "TOL_OF_EQUALITY_OF_POINTS2D = " << Point2d::GetToleranceOfEquality() << "\n"; 
	
	Edge2d a(Point2d(-1,0),Point2d(0,1));
	std::cout << "a : " << a << "\n";
	Edge2d b(Point2d(2,2),Point2d(Point2d::GetToleranceOfEquality(),1));
	std::cout << "b : " << b << "\n";
	Edge2d c(Point2d(Point2d::GetToleranceOfEquality(),1),Point2d(2,2));
	std::cout << "c : " << c << "\n";
	Edge2d d(Point2d(2,2),Point2d(3,3));
	std:: cout << "d : " << d << "\n";

	std::cout << "a.IsNeighbour(b) : " << a.IsNeighbour(b) << "\n";
	std::cout << "b.IsNeighbour(a) : " << b.IsNeighbour(a) << "\n";
	std::cout << "c.IsNeighbour(a) : " << c.IsNeighbour(a) << "\n";
	std::cout << "a.IsNeighbour(c) : " << a.IsNeighbour(c) << "\n";
	std::cout << "b.IsNeighbour(c) : " << b.IsNeighbour(c) << "\n";
	std::cout << "c.IsNeighbour(b) : " << c.IsNeighbour(b) << "\n";
	std::cout << "d.IsNeighbour(a) : " << d.IsNeighbour(a) << "\n";
	std::cout << "a.IsNeighbour(d) : " << a.IsNeighbour(d) << "\n";
	
	std::cout << "\n" <<"End---Testing: IsNeighbour function----------" << "\n\n"; 
	std::cout << "\n";
}


void test_GetPoints()
{
	std::cout << "\n";
	std::cout << "Start---Testing: GetPoints function----------" << "\n\n";
	
	std::cout << "Edge2d a(Point2d(1,1),Point2d(2,2));\n";
	Edge2d a(Point2d(1,1),Point2d(2,2));
	std::cout << "std::vector<Point2d> b = a.GetPoints();\n";
	std::vector<Point2d> b = a.GetPoints();
	std::cout << "b[0] :" << b[0] << "\n";
	std::cout << "b[1] :" << b[1] << "\n";
	
	std::cout << "\n" <<"End---Testing: GetPoints function----------" << "\n\n"; 
	std::cout << "\n";
}


int main(int argc, char *argv[])
{
	std::cout << "!!!In order to test what you want, just uncomment the corresponding function call from the main!!! \n";
	//test_parameter_constructor();
	//test_copy_constructor();
	//test_IsNeighbour();
	//test_GetPoints();
}