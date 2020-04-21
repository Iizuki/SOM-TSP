#ifndef SOM_H
#define SOM_H
#include "abstractMap.h"
#include "cities.h"
#include "dPoint.h"
#include <QObject>

//These values are hyperparameters for the SOM training algorithm
#define INITIAL_LEARNING_RATE 0.999
#define NEIGHBOURHOOD_MULTIPLIER 0.1

class SOM : public QObject, public AbstractMap
{
    Q_OBJECT

public:
    SOM();
    void InitializeCircular(int numberOfNodes);
    QVector<double> getXaxis() const override;
    QVector<double> getYaxis() const override;
    void train(Cities &cities,int iterations);

private:
    static std::function<DPoint (const Point&)> mapperFactory(const Point& city);
    static void reducer(DPoint &winner, const DPoint &competitor);
    void moveNodes(Point& BMU, const Point& city, double learningRate);

signals:
    void trainingIterationDone();
    void trainingDone(bool b);

};

#endif // SOM_H
