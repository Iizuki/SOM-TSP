#include "abstractMap.h"

AbstractMap::AbstractMap() : points()
{

}

/**
 * @brief Map::getPoints returns the collection of points in the map.
 * @return A constant vector of points.
 */
const QVector<Point> &AbstractMap::getPoints() const{
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


/**
 * @brief Cities::Initialize creates a random map of points. Also clears any pre-existing points.
 * @param number of points to be created.
 */
void AbstractMap::InitializeRandom(int number){
    points.clear();
    for(int i=0; i<number; i++){
        points.push_back(Point());
    }
}
