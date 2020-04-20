#ifndef CITIES_H
#define CITIES_H
#include "abstractMap.h"

class Cities : public AbstractMap
{

public:
    Cities();

    const QVector<Point> shuffle() const;
};

#endif // CITIES_H
