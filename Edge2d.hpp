/**
    Purpose: To be used to the Computational Geometry Library

    @author Chaviaras Michalis
    @version 1.1  2/2018 
*/


#ifndef EDGE2DDEF
#define EDGE2DDEF

#include <vector>
#include "Point2d.hpp"


class Edge2d
{
	
private: 
	std::vector<Point2d> mypoints;
	
public:
	Edge2d(const Edge2d& other_edge);
	Edge2d(const Point2d& p1, const Point2d& p2);
	//~Edge2d(); soon 
	
	/**
	 * @returns A vector with the 2d points corresponds to the edge 
	 */
	std::vector<Point2d> GetPoints() const;
	
	/**
	 * @returns true if other_edge is neighbour to *this 
	 * @param other_edge an edge 
	 */
	bool IsNeighbour(const Edge2d& other_edge);
	
	
	 
};

#endif
