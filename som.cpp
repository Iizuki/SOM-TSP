#include "som.h"
#include <cmath>
#include <QtConcurrent/QtConcurrent>

SOM::SOM()
{

}

/**
 * @brief SOM::InitializeCircular Initializes som nodes evenly along a circle with radius 0,35
 * @param numberOfNodes
 */
void SOM::InitializeCircular(int numberOfNodes){
    points.clear();
    for(int i=0; i < numberOfNodes; i++){
        double param = (2 * M_PI) * ((double)i / numberOfNodes);
        double x =0.5 + 0.35 * cos(param);
        double y =0.5 + 0.35 * sin(param);
        Point p(x, y);
        points.push_back(p);
    }
}

/**
 * @brief SOM::getXaxis gets the x-axis as looping Qvector
 * @return
 */
QVector<double> SOM::getXaxis() const {
    QVector<double> axis = this->axisExtractor(true);
    axis.append(axis.first()); //Complete the loop by adding the first element as the last one also.
    return axis;
}

/**
 * @brief SOM::getYaxis gets the y-axis as looping Qvector
 * @return
 */
QVector<double> SOM::getYaxis() const {
    QVector<double> axis = this->axisExtractor(false);
    axis.append(axis.first()); //Complete the loop by adding the first element as the last one also.
    return axis;
}

/**
 * @brief SOM::train trains the som. Should never be run in UI-thread. Assumes that cities and som are initialized.
 * @param iterations the number of training epocs to run.
 * @param cities the map of cities that the SOM is trying to learn.
 */
void SOM::train(const Cities &cities, int iterations){
    for (int i=0; i<iterations; i++){ //one loop iteration is also one training iteration.
        //Step 1. Obtain a shuffled list of cities
        QVector<Point> shuffledCities = cities.shuffle();

        //Step 2. Traverse through all cities
        for (const Point& city : shuffledCities){
            //Step 3. Find the closest SOM-node aka the BMU (best matching unit)
            std::function<DPoint (Point&)> mapper = mapperFactory(city);
            //REDUCER HERE
            DPoint BMU = QtConcurrent::blockingMappedReduced();

        }
    }
}

/**
 * @brief SOM::mapperFactory genrates a suitable mapping function for MappedReduced()
 * @param city
 * @return a lambda function that takes a somNodes as argument and returns it wrapped with it's distance to city (which is specified here).
 */
std::function<DPoint (Point&)> SOM::mapperFactory(const Point& city) const{
    return [=](Point& somNode){
        DPoint wrappedSomNode;
        wrappedSomNode.distance = city.distance(somNode);
        wrappedSomNode.point = somNode;
        return wrappedSomNode;
    };
}
