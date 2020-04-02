#ifndef CITIES_H
#define CITIES_H
#include "map.h"

class Cities : public Map
{
public:
    Cities();
    void Initialize(int numberOfCities);
};

#endif // CITIES_H
