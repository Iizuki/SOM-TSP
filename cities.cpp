#include "cities.h"

Cities::Cities()
{

}

/**
 * @brief Cities::Initialize creates a random map of citites.
 * @param numberOfCities
 */
void Cities::Initialize(int numberOfCities){
    for(int i=0; i<numberOfCities; i++){
        points.push_back(Point());
    }
}
