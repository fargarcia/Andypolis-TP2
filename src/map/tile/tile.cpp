#include "tile.h"
#include "../../consts/consts.h"
#include <string>

Tile::Tile(){};
Tile::~Tile(){};

void Tile::setType(std::string type){
    tileType = type;
}

std::string Tile::getType(){
    return tileType;
}

LakeTile::LakeTile() {
    setType(LAKE);
}

GroundTile::GroundTile() {
    setType(GROUND);
    available = true;
}

Template GroundTile::getBuildingTemplate() {
    return *building;
}

void GroundTile::addBuilding(Template* buildingTemplate) {
    available = false;
    building = buildingTemplate;
}
bool GroundTile::isAvailable() {
    return available;
};

void GroundTile::removeBuilding(){
    available = true;
    building = nullptr;
}

RoadTile::RoadTile() {
    setType(ROAD);
    available = true;
}

void RoadTile::addMaterial(Material* newMaterial){
    available = false;
    material = newMaterial;
}

