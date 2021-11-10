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
        ~City();
        Material** getMaterials();
        int getNumberOfMaterials();
        BuildingType** getBuildingTypes();
        int getNumberOfBuilding();
        Map* getMap();
        std::string getBuildingName(int xCoord, int yCoord);
        int addBuilding(std::string name, int xCoord, int yCoord, bool fromFile);
        bool removeBuilding(int xCoord, int yCoord);

        void materialsRain();
        void collectResources();
        int checkResources(std::string type);
        int checkAvailability(std::string type);
        int checkLocation(int xCoord, int yCoord);

};


#endif