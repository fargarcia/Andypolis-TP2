#ifndef	BUILDINGS_H
#define BUILDINGS_H

#include <vector>

class Building {
	private:
		std::string buildingName;
		int stoneQuantity;
		int woodQuantity;
		int metalQuantity;
		int builtAmount;
		int allowedAmount;
		int** locations;

	public:
		// Constructores
    	Building(std::string name, int stone, int wood, int metal, int newAllowedAmount);
    
		// Destructor
		~Building();

		void addBuilding(int xCoord, int yCoord);

		// Getters
		std::string getName();
		int getStoneQuantity();
		int getWoodQuantity();
		int getMetalQuantity();
		int getBuiltAmount();
		int getAllowedAmount();
		int** getLocations();
};

class Mine : public Building {
	using Building::Building;
};
class Sawmill : public Building {
	using Building::Building;
};
class Factory : public Building {
	using Building::Building;
};
class School : public Building {
	using Building::Building;
};
class Obelisk : public Building {
	using Building::Building;
};
class PowerPlant : public Building {
	using Building::Building;
};
class GenericBuilding : public Building {
	using Building::Building;
};

#endif
