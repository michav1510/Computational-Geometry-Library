VPATH=../../

test_Point2d : test_Point2d.cpp Point2d.o
	g++ -lm -o test_Point2d test_Point2d.cpp Point2d.o
	
	
Point2d.o : Point2d.cpp
	g++ -c ../../Point2d.cpp
	
	
clean : 
	rm test_Point2d Point2d.o