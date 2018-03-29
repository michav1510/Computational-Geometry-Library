#include"Predicates.hpp"


double Predicates::Orient_Pred(const Point2d& p_1, const Point2d& p_2, const Point2d& p_3)
{
	// we must return the (p1x-p2x)*(p3y-p2y)-(p1y-p2y)*(p3x-p2x)
	return (p_1.GetX() - p_2.GetX())*(p_3.GetY() - p_2.GetY()) - (p_1.GetY() - p_2.GetY())*(p_3.GetX() - p_2.GetX())  ;
}



bool Predicates::Edg_Inters_Pred(const Point2d& p_1, const Point2d& p_2, const Point2d& p_3, const Point2d& p_4)
{
	if( Orient_Pred(p_1,p_2,p_3)*Orient_Pred(p_1,p_2,p_4)<= 0 )
	{
		if( Orient_Pred(p_3,p_2,p_4)*Orient_Pred(p_3,p_1,p_4)<= 0 )
		{
			return true;
		}
	}
	return false;
}


bool Predicates::Edg_Inters_Pred(const double p1_x, const double p1_y, const double p2_x, const double p2_y, const double p3_x, const double p3_y, const double p4_x, const double p4_y)
{
	return Edg_Inters_Pred(Point2d(p1_x,p1_y),Point2d(p2_x,p2_y),Point2d(p3_x,p3_y),Point2d(p4_x,p4_y));
}


bool Predicates::Edg_Inters_Pred(const Edge2d& ed_1, const Edge2d& ed_2)
{
	return Edg_Inters_Pred(ed_1.GetPoints()[0],ed_1.GetPoints()[1],ed_2.GetPoints()[0],ed_2.GetPoints()[1]);
}
