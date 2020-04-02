#include "cities.h"

Cities::Cities()
{

}

void Cities::Initialize(int numberOfCities){
    for(int i=0; i<numberOfCities; i++){
        points.push_back(Point());
    }
}
