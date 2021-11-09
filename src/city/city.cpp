#include "city.h"
#include "./utils/utils.h"
#include "../consts/consts.h"
#include "consts/errors.h"

City::City(){
    map = new Map();
    buildings = new Buildings();
    materials = new MaterialsList();
    loadMap(map);
    loadBuildings(buildings);
    loadMaterials(materials);
    loadLocations(this);
}

Map* City::getMap() {
    return map;
}

int City::addBuilding(std::string name, int xCoord, int yCoord, bool fromFile){
    BuildingType* type = buildings -> getBuildingType(name);
    int resourceCheck, availabilityCheck, locationCheck;
    int response = OK;

    if (type  == NULL) 
        response = TYPE_NOT_FOUND;
    if (!response && (availabilityCheck = checkAvailability(name))) 
        response = availabilityCheck;
    if (!response && (locationCheck = checkLocation(xCoord, yCoord))) 
        response = locationCheck;
    if (!response && !fromFile && (resourceCheck = checkResources(name)))
        response = resourceCheck;
    if (!response){
        type -> addBuilding();

    Template * buildingTemplate = type -> getTemplate();
    static_cast<GroundTile*>(&(map -> getTile(xCoord, yCoord))) -> addBuilding(buildingTemplate);
    }
    return response;
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

int City::checkResources(std::string type){
    Template* buildingTemplate = buildings -> getBuildingType(type) -> getTemplate();
    if(buildingTemplate -> getMetalQuantity() > materials -> getAvailableMetal()) return NOT_ENOUGH_METAL;
    if(buildingTemplate -> getWoodQuantity() > materials -> getAvailableWood()) return NOT_ENOUGH_WOOD;
    if(buildingTemplate -> getStoneQuantity() > materials -> getAvailableRock()) return NOT_ENOUGH_ROCK;
    return OK;
};

int City::checkAvailability(std::string type){
    return buildings -> getBuildingType(type) -> getRemaining() > 0 ? OK : NOT_AVAILABLE;
};

int City::checkLocation(int xCoord, int yCoord){
    Tile* tile = &map -> getTile(xCoord, yCoord);

    if (tile -> getType() != GROUND) 
        return TERRAIN_NOT_SUITALBE;
// ALDU
if(static_cast<GroundTile*>(tile) == nullptr) cout << "hola aldu" << endl;

    if(!(static_cast<GroundTile*>(tile) -> isAvailable())) 
        return OCUPIED_TILE;
    return OK;
};

void City::materialsRain(Map *map) {
    //int roadTilesAmount = map -> getRoadTileAmount();

    //rand() % 3;

}