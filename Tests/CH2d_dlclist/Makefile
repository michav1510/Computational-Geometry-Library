VPATH=../../

test_CH2d_dlclist : test_CH2d_dlclist.cpp Point2d.o Pred.o Edge2d.o
	g++ -lm -o test_CH2d_dlclist test_CH2d_dlclist.cpp Point2d.o Pred.o Edge2d.o
	
Point2d.o : Point2d.cpp
	g++ -c ../../Point2d.cpp 
	
Predicates.o : Pred.cpp
	g++ -c ../../Pred.cpp

Edge2d.o : Edge2d.cpp
	g++ -c ../../Edge2d.cpp
	
clean : 
	rm test_CH2d_dlclist convex_hull_res.dat ch_push_res_of_all_cases.dat Point2d.o Pred.o Edge2d.o 