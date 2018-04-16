VPATH=../../

test_Convexhull2d : test_Convexhull2d.cpp Point2d.o
	g++ -lm -o test_Convexhull2d test_Convexhull2d.cpp Point2d.o
	
Point2d.o : Point2d.cpp
	g++ -c ../../Point2d.cpp 

clean : 
	rm test_Convexhull2d Point2d.o 