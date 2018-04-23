VPATH=../../

test_CH2d_dlclist : test_CH2d_dlclist.cpp Point2d.o Predicates.o Edge2d.o
	g++ -lm -o test_CH2d_dlclist test_CH2d_dlclist.cpp Point2d.o Predicates.o Edge2d.o
	
Point2d.o : Point2d.cpp
	g++ -c ../../Point2d.cpp 
	
Predicates.o : Predicates.cpp
	g++ -c ../../Predicates.cpp

Edge2d.o : Edge2d.cpp
	g++ -c ../../Edge2d.cpp
	
clean : 
	rm test_CH2d_dlclist Point2d.o Predicates.o Edge2d.o