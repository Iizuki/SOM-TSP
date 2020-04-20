#ifndef DPOINT_H
#define DPOINT_H
#include "point.h"

/**
 * @brief The DPoint struct simply wraps together one point and a double distance to another point.
 * Convenience struct that's used with Qt's concurrentMappedReduced function.
 */
struct DPoint{
    Point point;
    double distance;
};

#endif // DPOINT_H
