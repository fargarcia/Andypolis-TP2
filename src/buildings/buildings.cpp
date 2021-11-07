#include <iostream>
#include "buildings.h"

using namespace std;

//// Building
// Constructor
Building::Building(std::string name, int stone, int wood, int metal, int newAllowedAmount) {
	buildingName = name;
	stoneQuantity = stone;
	woodQuantity = wood;
	metalQuantity = metal;
	builtAmount = 0;
	allowedAmount = newAllowedAmount;
	locations = new int *[0];
}

void Building::addBuilding(int xCoord, int yCoord){
	int** newLocations = new int *[builtAmount + 1];
	copy(locations, locations + builtAmount, newLocations);
	int newLocation [2] = {xCoord, yCoord};
	newLocations[builtAmount] = newLocation;
	locations = newLocations;
	builtAmount++;
}

// getters
std::string Building::getName() {
  	return buildingName;
}

int Building::getStoneQuantity() {
 		return stoneQuantity;
}

int Building::getWoodQuantity() {
  	return woodQuantity;
}

int Building::getMetalQuantity() {
  	return metalQuantity;
}

int Building::getBuiltAmount() {
  	return builtAmount;
}

int Building::getAllowedAmount() {
  	return allowedAmount;
};

int** Building::getLocations() {
	return locations;
}