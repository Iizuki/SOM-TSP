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
void SOM::train(Cities &cities, int iterations){
    double learningRate = INITIAL_LEARNING_RATE;

    for (int i=0; i<iterations; i++){ //one loop iteration is also one training iteration.
        //Step 1. Obtain a shuffled list of cities
        QVector<Point> shuffledCities = cities.shuffle();

        //Step 2. Traverse through all cities
        for (const Point& city : shuffledCities){
            //Step 3. Find the closest SOM-node aka the BMU (best matching unit)
            //This step has no dependencies so it's computed parallel.
            std::function<DPoint (const Point&)> mapper = mapperFactory(city);
            DPoint BMU = QtConcurrent::blockingMappedReduced(points, mapper, SOM::reducer);

            //Step 4. Move BMU and it's neigbouring SOM nodes towards the city
            moveNodes(BMU.point, city, learningRate);
        }
        //Step 5. Reduce learning rate
        learningRate = learningRate * INITIAL_LEARNING_RATE;
        emit trainingIterationDone();
    } //Step 6. return to step 1. until all iterations are done
    emit trainingDone(true);
}

/**
 * @brief SOM::mapperFactory genrates a suitable mapping function for MappedReduced()
 * @param city
 * @return a lambda function that takes a somNodes as argument and returns it wrapped with it's distance to city (which is specified here).
 */
std::function<DPoint (const Point&)> SOM::mapperFactory(const Point& city){
    return [=](const Point& somNode){
        DPoint wrappedSomNode;
        wrappedSomNode.distance = somNode.distance(city);
        wrappedSomNode.point = somNode;
        wrappedSomNode.wanted = true;
        return wrappedSomNode;
    };
}

/**
 * @brief reducer function for mappedReduced. Selects the point with smaller distance.
 * @param winner the reduce result
 * @param competitor
 */
void SOM::reducer(DPoint &winner, const DPoint &competitor){
    if (winner.wanted == false){
        winner = competitor;
    } else{
        winner = winner.distance < competitor.distance ? winner : competitor;
    }
}

/**
 * @brief SOM::moveNodes updates the som once the BMU is found. Total of 9 points are moved, including BMU.
 * @param BMU best matching unit
 * @param city nodes will move towards this city
 */
void SOM::moveNodes(Point& BMU, const Point& city, double rate){
    //Find and update BMU neighbours
    int BMU_index = points.indexOf(BMU);
    int somLength = points.length();
    //points[BMU_index].move(city, rate);
    for (int i=1; i<=4; i++){ //4 neighbours in each direction are updated.
        int rightNeighbourIndex = (BMU_index + i) % somLength;
        int leftNeighbourIndex = (somLength + ((BMU_index - i) % somLength)) % somLength; //python style modulus
        double neighbourLeraningRate = rate * pow(NEIGHBOURHOOD_MULTIPLIER, i);
        points[rightNeighbourIndex].move(city, neighbourLeraningRate);
        points[leftNeighbourIndex].move(city, neighbourLeraningRate);
    }
}
