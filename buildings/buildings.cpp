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
	quantityBuilt = 0;
	allowedAmount = newAllowedAmount;
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

int Building::getQuantityBuilt() {
  	return quantityBuilt;
}

int Building::getAllowedAmount() {
  	return allowedAmount;
};
