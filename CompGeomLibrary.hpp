/**
    Purpose: To algorithms about Computational Geometry 

    @author Chaviaras Michalis
    @version 1.1  2/2018 
*/



#ifndef COMPGEOMLIBRARY
#define COMPGEOMLIBRARY

#include <list>
#include <vector>
#include "Point2d.hpp"
#include "Edge2d.hpp"

class CompGeomLibrary
{

public:

/**   
  @param list_of_edges The unsorted list of the edges of 2d the convex hull 
  @returns A list that contains the vertices of a 2d convex hull in a clockwise order
  @throws exception if there are colinear edges
*/
static std::list<Point2d> ComposeConvexHull2d(const std::list<Edge2d> list_of_edges);
	
};










#endif