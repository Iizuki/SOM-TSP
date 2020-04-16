#include "point.h"
#include <stdexcept>
#include <random>

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
double Point::getX(){return x;}
double Point::getY(){return y;}
