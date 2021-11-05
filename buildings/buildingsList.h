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

    void addBuilding(Building *newBuilding);
    
};

#endif