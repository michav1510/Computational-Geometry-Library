/**
    Purpose: To be used to the Computational Geometry Library

    @author Chaviaras Michalis
    @version 1.1  2/2018 
*/


#ifndef POINT2DDEF
#define POINT2DDEF

#include <iostream>

class Point2d
{
private: 
	static const double TOL_OF_EQUALITY_OF_POINTS2D = 1e-9;
	double myx;
	double myy;
public:
	Point2d(const Point2d& otherPoint);
	Point2d(const double x, const double y);
	
	/**
	 * @returns the x coordinate of the 2d point 
	 */
	double GetX() const;
	
	
	/**
	 * @returns the y coordinate of the 2d point
	 */
	double GetY() const;
	
	
	
	/**
	 * @returns true if two points are distant smaller or equal than TOL_OF_EQUALITY_OF_POINTS2D
	 */
	bool operator==(const Point2d &other_point) const;
	
	
	/**
	 * @returns The tolerance of the class. If two points are distant smaller or equal to this number
	 * then they are considered equal
	 */
	double GetToleranceOfEquality() const;
	
	
	
	/**
	 * This member-function overloads the unary (+) operator 
	 * for Point2d
	 * @returns the Point2d corresponds to +(*this)
	 */
	Point2d operator+() const; // unary +
	
	
	
	
	/**
	 * This member-function overloads the unary (-) operator 
	 * for Point2d
	 * @returns the Point2d corresponds to -(*this)
	 */
	Point2d operator-() const; // unary -
	
	
	
	/**
	 *  This member-function overloads the binary (+) operator for Point2d,
	 *  and adds the corresponding coordinates with each other 
	 *  @param p1 the point that will be added to the *(this)
	 *  @returns the result of 
	 */
	Point2d operator+(const Point2d& p1) const; // binary +
	
	
	/**
	 *  This member-function overloads the binary (-) operator for Point2d,
	 *  and subtracts the corresponding coordinates with each other 
	 *  @param p1 the point that will be subtract to the *(this)
	 *  @returns the result of  
	 */
	Point2d operator-(const Point2d& p1) const; // binary -
	
	
	
	/**
	 * This friend-function calculate the distance between two points
	 * @returns The distance of 2 Points2d
	 */
	static double Distanceof2dPoints(const Point2d p1, const Point2d p2);
	
};


#endif