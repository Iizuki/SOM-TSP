#include "abstractMap.h"

AbstractMap::AbstractMap() : points()
{

}

/**
 * @brief Map::getPoints returns the collection of points in the map.
 * @return A constant vector of points.
 */
const std::vector<Point> &AbstractMap::getPoints() const{
    return points;
}

/**
 * @brief AbstractMap::getXaxis gets the X-axis as Qvector
 * @return
 */
QVector<double> AbstractMap::getXaxis() const{
    return this->axisExtractor(true);
}

/**
 * @brief AbstractMap::getYaxis gets the Y-axis as Qvector
 * @return
 */
QVector<double> AbstractMap::getYaxis() const{
    return this->axisExtractor(false);
}

/**
 * @brief AbstractMap::axisExtractor is a helper method that extracts a QVector representation of the points.
 * @param axis determins which axis will be extracted. True for X, false for Y.
 * @return
 */
QVector<double> AbstractMap::axisExtractor(bool axis) const{
    QVector<double> vector;
    for(Point p : points){
        double coordinate = axis ? p.getX() : p.getY();
        vector.append(coordinate);
    }
    return vector;
}
