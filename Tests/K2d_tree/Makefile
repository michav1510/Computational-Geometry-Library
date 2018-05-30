VPATH=../../

test_K2d_tree : test_K2d_tree.cpp Point2d.o Pred.o Edge2d.o
	g++ -lm -o test_K2d_tree test_K2d_tree.cpp Point2d.o Pred.o Edge2d.o
	
Point2d.o : Point2d.cpp
	g++ -c ../../Point2d.cpp 
	
Predicates.o : Pred.cpp
	g++ -c ../../Pred.cpp

Edge2d.o : Edge2d.cpp
	g++ -c ../../Edge2d.cpp
	
clean : 
	rm test_K2d_tree Point2d.o Pred.o Edge2d.o 