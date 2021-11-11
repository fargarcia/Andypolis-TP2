#include "city.h"
#include "./utils/utils.h"
#include "../consts/consts.h"
#include "consts/errors.h"

City::City()
{
    map = new Map();
    buildings = new Buildings();
    materials = new MaterialsList();
    loadMap(map);
    loadBuildings(buildings);
    loadMaterials(materials);
    loadLocations(this);
}

City::~City()
{
    //saveBuildings(this);
    //saveMaterials(this);
    //saveMap(this);
    saveLocations(this);
}

Map *City::getMap()
{
    return map;
}

int City::addBuilding(std::string name, int xCoord, int yCoord, bool fromFile)
{
    BuildingType *type = buildings->getBuildingType(name);
    int resourceCheck, availabilityCheck, locationCheck;
    int response = OK;

    if (type == NULL)
        response = TYPE_NOT_FOUND;
    if (!response && (availabilityCheck = checkAvailability(name)))
        response = availabilityCheck;
    if (!response && (locationCheck = checkLocation(xCoord, yCoord)))
        response = locationCheck;
    if (!response && !fromFile && (resourceCheck = checkResources(name)))
        response = resourceCheck;
    if (!response)
    {
        type->addBuilding();
        Template *buildingTemplate = type->getTemplate();
        static_cast<GroundTile *>(map->getTile(xCoord, yCoord))->addBuilding(buildingTemplate);
    }

    return response;
}

bool City::removeBuilding(int xCoord, int yCoord)
{
    Tile *tile = map->getTile(xCoord, yCoord);
    int status = false;
    if (tile->getType() == GROUND)
    {
        GroundTile *groundTile = static_cast<GroundTile *>(tile);
        if (!groundTile->isAvailable())
        {
            Template buildingTemplate = groundTile->getBuildingTemplate();
            materials->increaseMaterial(ROCK, buildingTemplate.getStoneQuantity() / 2);
            materials->increaseMaterial(METAL, buildingTemplate.getMetalQuantity() / 2);
            materials->increaseMaterial(WOOD, buildingTemplate.getWoodQuantity() / 2);
            buildings->getBuildingType(buildingTemplate.getName())->removeBuilding();
            groundTile->removeBuilding();
            status = true;
        }
    }
    return status;
}

Material **City::getMaterials()
{
    return materials->getMaterials();
}

int City::getNumberOfMaterials()
{
    return materials->getNumberOfMaterials();
}

BuildingType **City::getBuildingTypes()
{
    return buildings->getBuildingTypes();
}

int City::getNumberOfBuilding()
{
    return buildings->getNumberOfBuilding();
}

int City::checkResources(std::string type)
{
    Template *buildingTemplate = buildings->getBuildingType(type)->getTemplate();
    if (buildingTemplate->getMetalQuantity() > materials->getAvailableMetal())
        return NOT_ENOUGH_METAL;
    if (buildingTemplate->getWoodQuantity() > materials->getAvailableWood())
        return NOT_ENOUGH_WOOD;
    if (buildingTemplate->getStoneQuantity() > materials->getAvailableRock())
        return NOT_ENOUGH_ROCK;
    return OK;
};

int City::checkAvailability(std::string type)
{
    return buildings->getBuildingType(type)->getRemaining() > 0 ? OK : NOT_AVAILABLE;
};

int City::checkLocation(int xCoord, int yCoord)
{
    Tile *tile = map->getTile(xCoord, yCoord);
    int status = OK;
    if (tile->getType() != GROUND)
        status = TERRAIN_NOT_SUITALBE;
    if (status && !(static_cast<GroundTile *>(tile)->isAvailable()))
        status = OCUPIED_TILE;
    return status;
};

void City::collectResources()
{
    int height = map->getHeight();
    int width = map->getWidth();
    Tile **tiles = map->getTilesVector();
    std::string name;
    int amount;
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            if (tiles[x][y].getType() == GROUND)
            {
                GroundTile *groundTile = static_cast<GroundTile *>(&tiles[x][y]);
                if (groundTile->isAvailable() == false)
                {
                    amount = 0;
                    Template buildingTemplate = groundTile->getBuildingTemplate();
                    if (buildingTemplate.getName() == FACTORY){
                        static_cast<Factory *>(&buildingTemplate)->collectResource(name, amount);
                    }
                    if (buildingTemplate.getName() == SAWMILL){
                        static_cast<Sawmill *>(&buildingTemplate)->collectResource(name, amount);
                    }
                    if (buildingTemplate.getName() == MINE){
                        static_cast<Mine *>(&buildingTemplate)->collectResource(name, amount);
                    }
                    if (amount > 0)
                    {
                        materials->increaseMaterial(name, amount);
                        cout << "Se recolectaron " << amount << " de " << name << endl;
                    }
                };
            }
            if (tiles[x][y].getType() == ROAD)
            {
                RoadTile *roadTile = static_cast<RoadTile *>(&tiles[x][y]);
                if (!(roadTile->isAvailable()))
                {
                    roadTile->clearRoad(name, amount);
                    cout << "Se recolectaron " << amount << " de " << name << endl;
                };
            }
        }
    }
}
std::string City::getBuildingName(int xCoord, int yCoord)
{
    Tile *tile = map->getTile(xCoord, yCoord);
    GroundTile *groundTile = static_cast<GroundTile *>(tile);
    return groundTile->getBuildingTemplate().getName();
}
