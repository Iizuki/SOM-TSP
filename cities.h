#ifndef CITIES_H
#define CITIES_H
#include "abstractMap.h"

class Cities : public AbstractMap
{

public:
    Cities();
    void Initialize(int numberOfCities);
};

#endif // CITIES_H
