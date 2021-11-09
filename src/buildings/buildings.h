#ifndef BUILDINGS_H
#define BUILDINGS_H

#include "buildingType.h"

class Buildings { 
	private:
		BuildingType ** buildingTypes;
		int numberOfBuildings;
    
	public:
    // Constructores
		Buildings();

		// Getters
		BuildingType ** getBuildingTypes();
		BuildingType * getBuildingType(std::string type);
		int getNumberOfBuilding();

    // Setters

    void addBuildingType(std::string name, int stone, int wood, int metal, int allowedAmount);
    
};

#endif