#include "som.h"
#include <cmath>

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
