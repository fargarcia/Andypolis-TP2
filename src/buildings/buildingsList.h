#ifndef BUILDINGSLIST_H
#define BUILDINGSLIST_H

#include "buildings.h"

class BuildingsList { 
	private:
		Building ** buildings;
		int numberOfBuildings;
    
	public:
    // Constructores
		BuildingsList();

		// Getters
		Building ** getBuildings();
		int getNumberOfBuildings();

    // Setters

    void addBuildingType(std::string name, int stone, int wood, int metal, int allowedAmount);
	void addBuilding(std::string name, int xCoord, int yCoord);
    
};

#endif