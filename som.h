#ifndef SOM_H
#define SOM_H
#include "abstractMap.h"

class SOM : public AbstractMap
{
public:
    SOM();
    void InitializeCircular(int numberOfNodes);
    QVector<double> getXaxis() const override;
    QVector<double> getYaxis() const override;
};

#endif // SOM_H
