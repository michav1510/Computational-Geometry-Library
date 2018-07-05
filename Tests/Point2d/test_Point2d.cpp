#include<iostream>
#include<random>
#include"../../Point2d.hpp"

void test_default_constructor(std::ostream& write_str);
void test_parameter_constructor(std::ostream& write_str);
void test_copy_constructor(std::ostream& write_str);
void test_assignment_operator(std::ostream& write_str);
void test_plus_minus_unary_operator(std::ostream& write_str);
void test_addition_and_subtraction_binary_operator(std::ostream& write_str);


int main(int argc, char* argv[])
{
	test_default_constructor(std::cout);
	test_parameter_constructor(std::cout);
	test_copy_constructor(std::cout);
	test_assignment_operator(std::cout);
	test_plus_minus_unary_operator(std::cout);
	test_addition_and_subtraction_binary_operator(std::cout);

}





void test_default_constructor(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "Point2d() :\n"; 
	
	int cas = 1;
	while(cas <= 1)
	{
		if(cas == 1)
		{
			bool test_pass1 = false;
			Point2d a;
			if( a.GetX() == 0 && a.GetY() == 0)
			{
				test_pass1 = true;
			}
	
			if(test_pass1 == true)
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



void test_parameter_constructor(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "Point2d(const double x, const double y) :\n";
	
	int cas = 1;
	while(cas <= 2)
	{
		if(cas == 1)
		{
			bool test_pass1 = false;
			Point2d a(3,2);
			if(a.GetX() == 3 && a.GetY() == 2)
			{
				test_pass1 = true;
			}
			
			if(test_pass1 == true)
			{
				write_str << "Test " << cas << " passed\n";
			}else
			{
				write_str << "Test " << cas << " failed\n";
			}
		}
		if(cas == 2)
		{
			bool test_pass2 = false;
			Point2d a(3000,32497898);
			if(a.GetX() == 3000 && a.GetY() == 32497898)
			{
				test_pass2 = true;
			}
			
			if(test_pass2 == true)
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




void test_copy_constructor(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "Point2d(const Point2d& otherPoint); :\n";
	
	int numberofexperim = 1000;
	int numberofpassed = 0;
	int cas = 1;
	while(cas <= numberofexperim)
	{
		std::random_device r;
		std::default_random_engine eng{r()};
		std::uniform_real_distribution<double> urd(1000000000000000-1,1000000000000000);
		Point2d a(urd(eng),urd(eng));
		Point2d b(a);
		
		if(a.GetX() == b.GetX() && a.GetY() == b.GetY())
		{
			numberofpassed++;
		}
			
		cas++;
	}
	
	write_str << "Number of tests were done: " << numberofexperim  << "\n";
	write_str << "Percentage of tests were passed: " << (numberofpassed/numberofexperim)*100 << "%" <<"\n";
	write_str << "\n\n";
}






void test_assignment_operator(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "bool operator==(const Point2d& other_point) const; :\n";
	
	int numberofexperim = 1000;
	int numberofpassed = 0;
	int cas = 1;
	while(cas <= numberofexperim)
	{
		std::random_device r;
		std::default_random_engine eng{r()};
		std::uniform_real_distribution<double> urd(1000000000000000-1,1000000000000000);
		Point2d a(urd(eng),urd(eng));
		Point2d b(a);
		
		if(a == b)
		{
			numberofpassed++;
		}
			
		cas++;
	}
	
	write_str << "Number of tests were done: " << numberofexperim  << "\n";
	write_str << "Percentage of tests were passed: " << (numberofpassed/numberofexperim)*100 << "%" <<"\n";

	
	
	write_str << "\n\n";
}


void test_plus_minus_unary_operator(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "Point2d operator+() const; and  \n";
	write_str << "Point2d operator-() const; :\n";
	
	int numberofexperim = 100;
	int numberofpassed = 0;
	int cas = 1;
	while(cas <= numberofexperim)
	{
		std::random_device r;
		std::default_random_engine eng{r()};
		std::uniform_real_distribution<double> urd(1000000000000000-1,1000000000000000);
		//here must be the check of the plus and minus operator of the Point2d
		double ran_num1 = urd(eng);
		double ran_num2 = urd(eng);
		Point2d a(ran_num1,ran_num2);
		
		Point2d c = a;
		Point2d d = -a; 
		if(c.GetX() == ran_num1 && c.GetY() == ran_num2 && d.GetX() == -ran_num1 && d.GetY() == -ran_num2 )
		{
			numberofpassed++;
		}
		
		cas++;
	}
	
	write_str << "Number of tests were done: " << numberofexperim  << "\n";
	write_str << "Percentage of tests were passed: " << (numberofpassed/numberofexperim)*100 << "%" <<"\n";
	write_str << "\n\n";
}


void test_addition_and_subtraction_binary_operator(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "Point2d operator+(const Point2d& p1) const; and  \n";
	write_str << "Point2d operator-(const Point2d& p1) const; :\n";
	
	
	int numberofexperim = 100;
	int numberofpassed = 0;
	int cas = 1;
	while(cas <= numberofexperim)
	{
		std::random_device r;
		std::default_random_engine eng{r()};
		std::uniform_real_distribution<double> urd(1000000000000000-1,1000000000000000);
		double ran_num1 = urd(eng);
		double ran_num2 = urd(eng);
		double ran_num3 = urd(eng);
		double ran_num4 = urd(eng);
		Point2d a(ran_num1,ran_num2);
		Point2d b(ran_num3,ran_num4);
		Point2d c = a+b;
		Point2d d = a-b;
		if( c.GetX() == ran_num1 + ran_num3 && d.GetX() == ran_num1 - ran_num3 && c.GetY() == ran_num2 + ran_num4 
			&& d.GetY() == ran_num2 - ran_num4)
		{
			numberofpassed++;
		}
		
		cas++;
	}
	
	write_str << "Number of tests were done: " << numberofexperim  << "\n";
	write_str << "Percentage of tests were passed: " << (numberofpassed/numberofexperim)*100 << "%" <<"\n";
	write_str << "\n\n";
}