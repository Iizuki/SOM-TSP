#ifndef SOM_H
#define SOM_H
#include "abstractMap.h"

class SOM : public AbstractMap
{
public:
    SOM();
    void Initialize(int numberOfNodes);
};

#endif // SOM_H
