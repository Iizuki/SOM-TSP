#include "map.h"

Map::Map()
{

}

/**
 * @brief Map::getPoints returns the collection of points in the map.
 * @return A constant vector of points.
 */
const std::vector<Point> &Map::getPoints() const{
    return points;
}
