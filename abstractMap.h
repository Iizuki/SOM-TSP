#ifndef MAP_H
#define MAP_H
#include <vector>
#include "point.h"
#include <QVector>

/**
 * @brief The Map class is an abstract class representing a set of 2D points.
 */
class AbstractMap
{
protected:
    std::vector<Point> points;
    QVector<double> axisExtractor(bool axis) const;
public:
    AbstractMap();
    void InitializeRandom(int number);
    QVector<double> getXaxis() const;
    QVector<double> getYaxis() const;
    const std::vector<Point> &getPoints() const;
};

#endif // MAP_H
