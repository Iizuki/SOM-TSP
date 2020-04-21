#include "point.h"
#include <stdexcept>
#include <random>
#include <cmath>

/**
 * @brief Point::Point Creates a new point with specified coordinates.
 * @param x X-coordinate must be within range [0,1]
 * @param y Y-coordinate must be within range [0,1]
 */
Point::Point(double x, double y)
{
    if (x > 1 || x < 0 || y > 1 || y < 0){
        throw std::out_of_range("Point must be within range [(0,0)-(0,0)]");
    }
    this->x = x;
    this->y = y;
}

/**
 * @brief Point::Point Creates a point with random coordinates in range [0,1].
 */
Point::Point(){
    //Initialize RNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0,1);

    //Randomize coordinates
    this->x = dist(gen);
    this->y = dist(gen);
}

//Getters
double Point::getX() const {return x;}
double Point::getY() const {return y;}


/**
 * @brief Point::distance returns the euclidean distance between this and another point
 * @param anotherPoint
 * @return
 */
double Point::distance(const Point& anotherPoint) const{
    return sqrt(pow( (x - anotherPoint.getX()), 2) + pow( (y - anotherPoint.getY()), 2));
}

/**
 * @brief Point::move moves this point towards another point.
 * @param anotherPoint gives the direction for movement. Will not be modified.
 * @param precent double value in range [0,1] tells how much to move the point.
 * 0 won't move at all and 1 will move this point to the same location as anotherPoint.
 */
void Point::move(const Point& anotherPoint, double percent){
    if (percent > 1 || percent < 0){
        throw std::out_of_range("Point must be within range [(0,0)-(0,0)]");
    }

    //Handles the special case of two points with the same x-coordinates
    if (x == anotherPoint.getX()){
       double distance = this->distance(anotherPoint);
       double Yupdate = distance * percent;
       //Apply a positive update if anotherPoint is above this one
       if (y < anotherPoint.getY()){
           y = y + Yupdate;
       } else{ //Negative update if anotherPoint is below this one
           y = y - Yupdate;
       }
       return; //Prevent the normal update
    }

    //The normal update
    double distance = this->distance(anotherPoint);
    double slope = (anotherPoint.getY() - y) / (anotherPoint.getX() - x);
    double updateLength = distance * percent;
    double slopeLength = sqrt(1 + pow(slope, 2));

    double Xupdate = updateLength / slopeLength;
    double Yupdate = (updateLength * slope) / slopeLength;

    //Apply a positive update if another point is to the right
    if (x < anotherPoint.getX()){
        x = x + Xupdate;
        y = y + Yupdate;
    }else{ //Negative update if another point is to the left
        x = x - Xupdate;
        y = y - Yupdate;
    }
}


bool operator== (Point &p1, const Point &p2){
    return (p1.getX() == p2.getX() && p1.getY() == p2.getY());
}
