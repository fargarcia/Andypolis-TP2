#include <iostream>
#include "buildings.h"
#include "buildingType.h"
#include "../consts/consts.h"
#include "template.h"

using namespace std;

//// BuildingsList
// Constructor sin argumentos
Buildings::Buildings(){
  buildingTypes = new BuildingType *[0];
  numberOfBuildings = 0;
}

int Buildings::getNumberOfBuilding(){
  return numberOfBuildings;
}

BuildingType **Buildings::getBuildingTypes(){
  return buildingTypes;
};

void Buildings::addBuildingType(std::string name, int stone, int wood, int metal, int allowedAmount){
  BuildingType **newTypes = new BuildingType *[numberOfBuildings + 1];
  copy(buildingTypes, buildingTypes + numberOfBuildings, newTypes);

  Template* buildingTemplate;
  if (name == MINE){
    buildingTemplate = new Mine(name, stone, wood, metal);
  } else if (name == SAWMILL) {
    buildingTemplate = new Sawmill(name, stone, wood, metal);
  } else if (name == FACTORY) {
    buildingTemplate = new Factory(name, stone, wood, metal);
  } else if (name == SCHOOL) {
    buildingTemplate = new School(name, stone, wood, metal);
  } else if (name == OBELISK) {
    buildingTemplate = new Obelisk(name, stone, wood, metal);
  } else if (name == POWER_PLANT) {
    buildingTemplate = new PowerPlant(name, stone, wood, metal);
  } else {
    buildingTemplate = new GenericBuilding(name, stone, wood, metal);
  };
  newTypes[numberOfBuildings] = new BuildingType(name, allowedAmount, buildingTemplate);

  buildingTypes = newTypes;
  numberOfBuildings++;
};