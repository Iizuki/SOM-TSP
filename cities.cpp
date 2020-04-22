#include "cities.h"
#include <algorithm>
#include <random>

Cities::Cities()
{

}

/**
 * @brief Cities::shuffle returns a Qvector that holds the citypoints in random order.
 * @return
 */
const QVector<Point> Cities::shuffle() const{
    //Initialize randomEngine
    std::random_device rd;
    std::default_random_engine rEngine{rd()};

    //Copy points vector
    std::vector<Point> stdPoints (points.constBegin(), points.constEnd());

    //Shuffle the vector
    std::shuffle(std::begin(stdPoints), std::end(stdPoints), rEngine);

    //Return as QVector
    return QVector<Point>(stdPoints.begin(), stdPoints.end());
}

