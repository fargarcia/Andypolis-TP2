#ifndef CITY_H
#define CITY_H

#include "../buildings/buildings.h"
#include "../map/map.h"
#include "../materials/materialsList.h"

class City {
    private:
        Map* map;
        Buildings* buildings;
        MaterialsList* materials;
    public:
        City();
        Material** getMaterials();
        int getNumberOfMaterials();
        BuildingType** getBuildingTypes();
        int getNumberOfBuilding();
        int addBuilding(std::string name, int xCoord, int yCoord);

};


#endif