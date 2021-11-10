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

City::~City(){
    saveBuildings(this);
    saveMaterials(this);
    saveMap(this);
    saveLocations(this);
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
        static_cast<GroundTile*>(map -> getTile(xCoord, yCoord)) -> addBuilding(buildingTemplate);
    }
    
    return response;
}

bool City::removeBuilding(int xCoord, int yCoord){
    Tile* tile = map -> getTile(xCoord, yCoord);
    int status = false;
    if(tile -> getType() == GROUND){
        GroundTile* groundTile = static_cast<GroundTile*>(tile);
        if(!groundTile -> isAvailable()){
            Template buildingTemplate = groundTile -> getBuildingTemplate();
            materials -> increaseMaterial(ROCK, buildingTemplate.getStoneQuantity()/2);
            materials -> increaseMaterial(METAL, buildingTemplate.getMetalQuantity()/2);
            materials -> increaseMaterial(WOOD, buildingTemplate.getWoodQuantity()/2);
            buildings -> getBuildingType(buildingTemplate.getName()) -> removeBuilding();
            groundTile -> removeBuilding();
            status = true;
        }
    }
    return status;
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
    Tile* tile = map -> getTile(xCoord, yCoord);
    int status = OK;
    if(tile -> getType() != GROUND) status =  TERRAIN_NOT_SUITALBE;
    if(status && !(static_cast<GroundTile*>(tile) -> isAvailable())) status = OCUPIED_TILE;
    return status;
};

void City::collectResources(){
    int height = map -> getHeight();
    int width = map -> getWidth();
    Tile** tiles = map -> getTilesVector();
    for (int x = 0; x < height; x++){
        for (int y = 0; y < width; y++){
            if(tiles[x][y].getType() == GROUND){
            GroundTile * groundTile = static_cast<GroundTile*>(&tiles[x][y]);
            if (!(groundTile -> isAvailable())){
                std::string name = groundTile -> getBuildingTemplate().getName();
                if(name == MINE){

                }   
                if(name == SAWMILL){

                }
                if(name == FACTORY){
                    
                }             
            };
        }
        if(tiles[x][y].getType() == ROAD){
            RoadTile * roadTile = static_cast<RoadTile*>(&tiles[x][y]);
            if (!(roadTile -> isAvailable())){

            };
        }
        }
        
        
    }
    
}

void City::materialsRain() {
    //int roadTilesAmount = map -> getRoadTileAmount();
    /*
    Piedra: 1 o 2 
    Madera: 0 o 1
    Metal: 2, 3 o 4

    1) Tengo la cantidad de casilleros transitables si es menor a 3 no puedo hacer la lluvia (informarlo)
    2) Hago un rand() para saber cuantos materiales voy a poner (minimo 3 (1 piedra y 2 metales), maximo 7)
    3) Hago un rand() entre los casilleros para ver en cual voy a poner el material y guardo el numero en un vector
    4) Recorro el mapa hasta encontrar el casillero que salio en el rand() y elimino ese numero de los casilleros posibles
    5) Hago un rand() entre 1 piedra y 2 metales a ver cual voy a colocar en el casillero que salio
    6) Coloco el material en el casillero    
    7) Hago un rand entre lo que quedo en 5) y vuelvo a hacer un rand para ver en que casillero ponerlo
    8) Hago un rand para ver donde poner el material que quedo en 7)
    9) Si el rand() de la cantidad de materiales a poner es mayor a 3 y menor a 7, vuelvo a hacer un rand para encontrar un casillero
    10) Hago un rand() para elegir que material va a ir en el casillero
    11) Recorro el mapa para encontrar el casillero  y elimino ese numero de los casilleros posibles
    12) Repito pasos del 9) al 11)



    Generar 1 materialList vacio (vector de materiales)
    Generar entre 1 y 2 de piedra, 0 y 1 de madera, y 2, 3, 4 de metal
    Hago un while recorriendo el mapa para ver si pongo o no un material en el casillero
    


    */

    //rand() % 3;

}