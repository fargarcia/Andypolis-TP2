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
    cout << "5" << endl;
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
        cout << "d" << endl;
        if (map -> getTile(xCoord, yCoord).getType() == GROUND){
            cout << "e" << endl;
            Template * buildingTemplate = type -> getTemplate();
            cout << "f" << endl;
            static_cast<GroundTile*>(&(map -> getTile(xCoord, yCoord))) -> addBuilding(buildingTemplate);
            cout << "g" << endl;
        } else {
            cout << "e2" << endl;
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



