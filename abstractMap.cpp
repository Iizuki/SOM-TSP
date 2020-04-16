#include "abstractMap.h"

AbstractMap::AbstractMap()
{

}

/**
 * @brief Map::getPoints returns the collection of points in the map.
 * @return A constant vector of points.
 */
const std::vector<Point> &AbstractMap::getPoints() const{
    return points;
}

QVector<double> AbstractMap::getXaxis() const{
    //TODO
}
QVector<double> AbstractMap::getYaxis() const{
    //TODO
}
