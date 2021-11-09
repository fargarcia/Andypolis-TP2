#include "city.h"
#include "./utils/utils.h"
#include "../consts/consts.h"

City::City(){
    map = new Map();
    buildings = new Buildings();
    materials = new MaterialsList();
    loadMap(map);
    loadBuildings(buildings);
    loadMaterials(materials);
    loadLocations(this);
}

int City::addBuilding(std::string name, int xCoord, int yCoord){
    int i = 0;
    while (
        i < buildings -> getNumberOfBuilding() && 
        name != buildings -> getBuildingTypes()[i] -> getName()
        ) i++;
    if (i == buildings -> getNumberOfBuilding()) return 0;

    BuildingType* type = buildings -> getBuildingTypes()[i];
    
    if (type -> addBuilding()){
        if (map -> getTile(xCoord, yCoord).getType() == GROUND){
            Template * buildingTemplate = type -> getTemplate();
            static_cast<GroundTile*>(&(map -> getTile(xCoord, yCoord))) -> addBuilding(buildingTemplate);
        } else {
            type -> removeBuilding();
            return 0;
        }
    }
    return 1;
}

Material** City::getMaterials(){
    return materials -> getMaterials();
}

int City::getNumberOfMaterials(){
    return materials -> getNumberOfMaterials();
}

BuildingType** City::getBuildingTypes(){
    return buildings -> getBuildingTypes();
}

int City::getNumberOfBuilding(){
    return buildings -> getNumberOfBuilding();
}



