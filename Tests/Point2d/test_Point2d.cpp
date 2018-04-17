#include<iostream>
#include"../../Point2d.hpp"

void test_default_constructor()
{
	std::cout << "\n";
	std::cout << "Start---Testing: default constructor----------" << "\n\n"; 
	Point2d a;
	std::cout << "Creation of Point2d a by the default constructor :\n";
	std::cout <<  "a.GetX() = " << a.GetX() << "\n";
	std::cout <<  "a.GetY() = " << a.GetY() << "\n";
	std::cout << "TOL_OF_EQUALITY_OF_POINTS2D = " << Point2d::GetToleranceOfEquality() << "\n"; 
	std::cout << "\n" <<"End---Testing: default constructor----------" << "\n\n"; 
	std::cout << "\n";
}


void test_parameter_constructor()
{
	std::cout << "\n";
	std::cout << "Start---Testing: parameter constructor----------" << "\n\n"; 
	
	std::cout << "Point2d a(3,2);\n";
	Point2d a(3,2);
	std::cout <<  "a.GetX = " << a.GetX() << "\n";
	std::cout <<  "a.GetY = " << a.GetY() << "\n";
	std::cout << "TOL_OF_EQUALITY_OF_POINTS2D = " << Point2d::GetToleranceOfEquality() << "\n"; 
	
	
	std::cout << "\n" <<"End---Testing: parameter constructor----------" << "\n\n"; 
	std::cout << "\n";
}


void test_copy_constructor()
{
	std::cout << "\n";
	std::cout << "Start---Testing: copy constructor----------" << "\n\n"; 
	std::cout << "Point2d a(3,2);\n";
	Point2d a(3,2);
	std::cout << "Point2d b(a);\n";
	Point2d b(a);
	std::cout <<  "a.GetX = " << a.GetX() << "\n";
	std::cout <<  "a.GetY = " << a.GetY() << "\n";
	std::cout << "TOL_OF_EQUALITY_OF_POINTS2D = " << Point2d::GetToleranceOfEquality() << "\n";
	std::cout <<  "b.GetX = " << b.GetX() << "\n";
	std::cout <<  "b.GetY = " << b.GetY() << "\n";
	std::cout << "TOL_OF_EQUALITY_OF_POINTS2D = " << Point2d::GetToleranceOfEquality() << "\n";
	std::cout << "Are the a and b have equal addresses ?\n";
	std::cout << "&a==&b : " << (&a == &b) << "\n";
	
	std::cout << "\n" <<"End---Testing: copy constructor----------" << "\n\n"; 
	std::cout << "\n";
}


void test_assignment_operator()
{
	std::cout << "\n";
	std::cout << "Start---Testing: assignment operator ----------" << "\n\n";
	
	std::cout << "TOL_OF_EQUALITY_OF_POINTS2D = " << Point2d::GetToleranceOfEquality() << "\n\n";
	
	std::cout << "Point2d a(0,0);\n";
	Point2d a(0,0);
	std::cout << "\n";
	
	std::cout << "Point2d b(0,2*Point2d::GetToleranceOfEquality());\n";
	Point2d b(0,2*Point2d::GetToleranceOfEquality());
	std::cout << "Point2d::Distanceof2dPoints(a,b) = " << Point2d::Distanceof2dPoints(a,b) << "\n";
	std::cout << "Are the a and b considered equal ? a == b : " << (a==b) << "\n";
	std::cout << "\n";
	
	std::cout << "Point2d c(0,1);\n";
	Point2d c(0,1);
	std::cout << "Point2d::Distanceof2dPoints(a,c) = " << Point2d::Distanceof2dPoints(a,c) << "\n";
	std::cout << "Are the a and c considered equal ? a == c : " << (a==c) << "\n";
	std::cout << "\n";

	std::cout << "Point2d d(Point2d::GetToleranceOfEquality(),Point2d::GetToleranceOfEquality());\n";
	Point2d d(Point2d::GetToleranceOfEquality(),Point2d::GetToleranceOfEquality());
	std::cout << "Point2d::Distanceof2dPoints(a,d) = " << Point2d::Distanceof2dPoints(a,d) << "\n";
	std::cout << "Are the a and d considered equal ? a == d : " << (a==d) << "\n";
	std::cout << "\n";
	
	std::cout << "Point2d e(Point2d::GetToleranceOfEquality()/2,Point2d::GetToleranceOfEquality()/2);\n";
	Point2d e(Point2d::GetToleranceOfEquality()/2,Point2d::GetToleranceOfEquality()/2);
	std::cout << "Point2d::Distanceof2dPoints(a,e) = " << Point2d::Distanceof2dPoints(a,e) << "\n";
	std::cout << "Are the a and e considered equal ? a == e : " << (a==e) << "\n";
	std::cout << "\n";
	
	std::cout << "Point2d f(Point2d::GetToleranceOfEquality(),0);\n";
	Point2d f(Point2d::GetToleranceOfEquality()/2,0);
	std::cout << "Point2d::Distanceof2dPoints(d,f) = " << Point2d::Distanceof2dPoints(d,f) << "\n";
	std::cout << "Are the a and e considered equal ? d == f : " << (d==f) << "\n";
	std::cout << "\n";
	
	std::cout << "\n" <<"End---Testing: assignment operator----------" << "\n\n"; 
	std::cout << "\n";
}


void test_plus_minus_unary_operator()
{
	std::cout << "\n";
	std::cout << "Start---Testing: plus minus unary operator ----------" << "\n\n";
	
	std::cout << "Point2d a(1,2);\n";
	Point2d a(1,2);
	std::cout << "+a = " << +a << "\n";
	std::cout << "-a = " << -a << "\n";
	
	std::cout << "\n" <<"End---Testing: plus minus unary operator----------" << "\n\n"; 
	std::cout << "\n";
}


void test_addition_and_subtraction_binary_operator()
{
	std::cout << "\n";
	std::cout << "Start---Testing: addition subtraction binary operator ----------" << "\n\n";

	std::cout << "Point2d a(5+3./4,1);\n";
	Point2d a(5+3./4,1);
	std::cout << "Point2d b(-2,1);\n";
	Point2d b(-2,1);
	std::cout << "a+b = " << a+b << "\n";
	std::cout << "b+a = " << b+a << "\n";
	std::cout << "a-b = " << a-b << "\n";
	std::cout << "b-a = " << b-a << "\n";
	
	
	std::cout << "\n" <<"End---Testing: addition subtraction binary operator----------" << "\n\n"; 
	std::cout << "\n";
}

int main(int argc, char* argv[])
{
	std::cout << "!!!In order to test what you want, just uncomment the corresponding function call from the main!!! \n";
//	test_default_constructor();
//	test_parameter_constructor();
//	test_copy_constructor();
	test_assignment_operator();
//	test_plus_minus_unary_operator();
//	test_addition_and_subtraction_binary_operator();
}