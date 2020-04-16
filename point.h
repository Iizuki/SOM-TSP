#ifndef POINT_H
#define POINT_H

/**
 * @brief The Point class represents a mutable double precission 2D point in [(0,0)-(1,1)] range.
 */
class Point
{
    double x;
    double y;
public:
    Point(double x, double y);
    Point();

    double getX();
    double getY();
};

#endif // POINT_H
