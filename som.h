#ifndef SOM_H
#define SOM_H
#include "abstractMap.h"
#include "cities.h"
#include "dPoint.h"

class SOM : public AbstractMap
{

    std::function<DPoint (Point&)> mapperFactory(const Point& city) const;

public:
    SOM();
    void InitializeCircular(int numberOfNodes);
    QVector<double> getXaxis() const override;
    QVector<double> getYaxis() const override;
    void train(const Cities &cities,int iterations);
};

#endif // SOM_H
