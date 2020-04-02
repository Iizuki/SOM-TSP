#ifndef MAP_H
#define MAP_H
#include <vector>
#include "point.h"

/**
 * @brief The Map class is an abstract class representing a set of 2D points.
 */
class Map
{
protected:
    std::vector<Point> points;
public:
    Map();
    const std::vector<Point> &getPoints() const;
};

#endif // MAP_H
