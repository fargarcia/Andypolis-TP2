#include <iostream>
#include "buildingsList.h"
#include "buildings.h"

using namespace std;

//// BuildingsList
// Constructor sin argumentos
BuildingsList::BuildingsList() {
	buildings = new Building * [0];
	numberOfBuildings = 0;
}

int BuildingsList::getNumberOfBuildings() {
  return numberOfBuildings;
}

Building ** BuildingsList::getBuildings() {
  return buildings;
};

void BuildingsList::addBuilding(Building *newBuilding) {
	Building** newBuildingsVector = new Building *[numberOfBuildings+1];
  copy(buildings, buildings + numberOfBuildings , newBuildingsVector);
  newBuildingsVector[numberOfBuildings] = newBuilding;
  buildings = newBuildingsVector;
  numberOfBuildings++;
}