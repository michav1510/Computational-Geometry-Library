Computational Geometry Library.

Implementation of a Computational Geometry Library. 
There is an implementation of Point2d class that represents a point on the plane.
The Edge2d class that consists of two points.
In the Predicates class I implement the predicates I have to implement in order to 
build more complex algorithms.
The CH2d_dlclist is a class that represents a convex hull of 2d points on the plane, its name come from the
double linked cyclic list. This class can find the convex hull of a set of 2d points using the "Jarvis March"
or "Gift-Wrapping" algorithm. It can also insert a point into the convex hull with the push function. It keeps
the number of the vertices of the convex hull as a "size" and as "area" the area that the convex hull occupies.
This class can also return an iterator that if you increase it you are moving clockwise at the convex hull if 
you decrease it you are moving counter clockwise at the convex hull. 


This version is a beta version in future there will be much more functionality and of
course a Makefile and few examples that will show how my implementations work. At this time you can see the Tests
I have developed and they can shed light on what I have implemented. 

My ambitions is to make also the 3d case where we must construct a convex hull given a set of 3d point.