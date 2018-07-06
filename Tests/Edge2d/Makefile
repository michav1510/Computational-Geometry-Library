VPATH=../..

test_Edge2d : test_Edge2d.cpp Edge2d.o Point2d.o
	g++ -std=c++11 -lm -o test_Edge2d test_Edge2d.cpp Edge2d.o Point2d.o

Point2d.o : Point2d.cpp
	g++ -std=c++11 -c ../../Point2d.cpp
	
Edge2d.o : Edge2d.cpp
	g++ -std=c++11 -c ../../Edge2d.cpp
	
clean :
	rm test_Edge2d Edge2d.o Point2d.o	