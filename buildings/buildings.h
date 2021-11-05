#ifndef	BUILDINGS_H
#define BUILDINGS_H

#include <vector>

class Building {
	private:
		std::string buildingName;
		int stoneQuantity;
		int woodQuantity;
		int metalQuantity;
		int quantityBuilt;
		int allowedAmount;
		std::vector<std::pair<int, int>> positions;

	public:
		// Constructores
		Building();
    	Building(std::string name, int stone, int wood, int metal, int newAllowedAmount);
    
		// Destructor
		~Building();

		// Getters
		std::string getName();
		int getStoneQuantity();
		int getWoodQuantity();
		int getMetalQuantity();
		int getQuantityBuilt();
		int getAllowedAmount();
};

class Mine : public Building {};
class Sawmill : public Building {};
class Factory : public Building {};
class School : public Building {};
class Obelisk : public Building {};
class PowerPlant : public Building {};

#endif
