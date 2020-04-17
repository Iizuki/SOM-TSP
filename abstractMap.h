#ifndef MAP_H
#define MAP_H
#include "point.h"
#include <QVector>

/**
 * @brief The Map class is an abstract class representing a set of 2D points.
 */
class AbstractMap
{
protected:
    QVector<Point> points;
    QVector<double> axisExtractor(bool axis) const;
public:
    AbstractMap();
    void InitializeRandom(int number);
    virtual QVector<double> getXaxis() const;
    virtual QVector<double> getYaxis() const;
    const QVector<Point> &getPoints() const;
};

#endif // MAP_H
