#include <iostream>
#include "buildingsList.h"
#include "buildings.h"
#include "../consts/consts.h"

using namespace std;

//// BuildingsList
// Constructor sin argumentos
BuildingsList::BuildingsList(){
  buildings = new Building *[0];
  numberOfBuildings = 0;
}

int BuildingsList::getNumberOfBuildings(){
  return numberOfBuildings;
}

Building **BuildingsList::getBuildings(){
  return buildings;
};

void BuildingsList::addBuildingType(std::string name, int stone, int wood, int metal, int allowedAmount){
  Building **newBuildingsVector = new Building *[numberOfBuildings + 1];
  copy(buildings, buildings + numberOfBuildings, newBuildingsVector);

  if (name == MINE){
    newBuildingsVector[numberOfBuildings] = new Mine(name, stone, wood, metal, allowedAmount);
  } else if (name == SAWMILL) {
    newBuildingsVector[numberOfBuildings] = new Sawmill(name, stone, wood, metal, allowedAmount);
  } else if (name == FACTORY) {
    newBuildingsVector[numberOfBuildings] = new Factory(name, stone, wood, metal, allowedAmount);
  } else if (name == SCHOOL) {
    newBuildingsVector[numberOfBuildings] = new School(name, stone, wood, metal, allowedAmount);
  } else if (name == OBELISK) {
    newBuildingsVector[numberOfBuildings] = new Obelisk(name, stone, wood, metal, allowedAmount);
  } else if (name == POWER_PLANT) {
    newBuildingsVector[numberOfBuildings] = new PowerPlant(name, stone, wood, metal, allowedAmount);
  } else {
    newBuildingsVector[numberOfBuildings] = new GenericBuilding(name, stone, wood, metal, allowedAmount);
  };

  buildings = newBuildingsVector;
  numberOfBuildings++;
}

void BuildingsList::addBuilding(std::string name, int xCoord, int yCoord){
  int index = 0;
  while(index < numberOfBuildings && buildings[index] -> getName() != name) index++;
  if (index < numberOfBuildings) buildings[index] -> addBuilding(xCoord, yCoord);
}