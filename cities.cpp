#include "cities.h"

Cities::Cities()
{

}

/**
 * @brief Cities::Initialize creates a random map of citites. Also clears any pre-existing cities.
 * @param numberOfCities
 */
void Cities::Initialize(int numberOfCities){
    points.clear();
    for(int i=0; i<numberOfCities; i++){
        points.push_back(Point());
    }
}
