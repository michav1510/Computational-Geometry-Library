#include <iostream>
#include"../../K2d_tree.hpp"

void test_parameter_constructor(std::ostream& write_str);


int main(int argc, char* argv[])
{
	test_parameter_constructor(std::cout);
}



void test_parameter_constructor(std::ostream& write_str)
{
	write_str << "\n\nHere is checked the \n";
	write_str << "K2d_tree(std::vector<Point2d> points) :\n";
	
	int cas = 1;
	while(cas <= 5)
	{
		if(cas == 1)
		{
			bool test_pass1 = false;
			std::vector<Point2d> vec1;
			vec1.push_back(Point2d(2,1));
			vec1.push_back(Point2d(1,0));
			vec1.push_back(Point2d(3,-5));
			vec1.push_back(Point2d(-1,2));
			vec1.push_back(Point2d(4,-3));
			K2d_tree tree1(vec1);
			
			K2d_tree::tree_iterator it1 = tree1.begin();
			if( it1.getSplitCoord() == 1 && it1.getSplitValue() == 2 && it1.getLeafPoint() == Point2d(0,0) && it1.isInternalNode() == true )
			{
				K2d_tree::tree_iterator it12 = it1.getLeftChild();
				if(it12.getSplitCoord() == 2 && it12.getSplitValue() == 1 && it12.getLeafPoint() == Point2d(0,0) && it12.isInternalNode() == true)
				{
					K2d_tree::tree_iterator it13 = it1.getRightChild();
					if(it13.getSplitCoord() == 2 && it13.getSplitValue() == -5 && it13.getLeafPoint() == Point2d(0,0) && it13.isInternalNode() == true)
					{
						K2d_tree::tree_iterator it14 = it1.getLeftChild().getLeftChild();
						if(it14.getSplitCoord() == 1 && it14.getSplitValue() == 1 && it14.getLeafPoint() == Point2d(0,0) && it14.isInternalNode() == true)
						{
							K2d_tree::tree_iterator it15 = it1.getLeftChild().getRightChild();
							if(it15.getSplitCoord() == 0 && it15.getSplitValue() == 0 && it15.getLeafPoint() == Point2d(-1,2) && it15.isInternalNode() == false)
							{
								
								K2d_tree::tree_iterator it16 = it1.getRightChild().getLeftChild();
								if(it16.getSplitCoord() == 0 && it16.getSplitValue() == 0 && it16.getLeafPoint() == Point2d(3,-5) && it16.isInternalNode() == false)
								{
									K2d_tree::tree_iterator it17 = it1.getRightChild().getRightChild();
									if(it17.getSplitCoord() == 0 && it17.getSplitValue() == 0 && it17.getLeafPoint() == Point2d(4,-3) && it17.isInternalNode() == false)
									{
										K2d_tree::tree_iterator it18 = it1.getLeftChild().getLeftChild().getLeftChild();
										if(it18.getSplitCoord() == 0 && it18.getSplitValue() == 0 && it18.getLeafPoint() == Point2d(1,0) && it18.isInternalNode() == false)
										{
											K2d_tree::tree_iterator it19 = it1.getLeftChild().getLeftChild().getRightChild();
											if(it19.getSplitCoord() == 0 && it19.getSplitValue() == 0 && it19.getLeafPoint() == Point2d(2,1) && it19.isInternalNode() == false)
											{
												if(tree1.size() == 5)
												{
													test_pass1 = true;
												}
											}
										}
									}
								}
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
		}
		cas++;
	}
	
	
	write_str << "\n\n";
}