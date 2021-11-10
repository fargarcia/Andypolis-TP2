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
		// Pre: -
		// Post: Devuelve el el tipo de edificio 
		BuildingType ** getBuildingTypes();
		// Pre: -
		// Post: Devuelve el tipo de edificio dependiendo del string que reciba
		BuildingType * getBuildingType(std::string type);
		// Pre: -
		// Post: Devuelve la cantidad de edificios construidos
		int getNumberOfBuilding();

	// Pre: Recibir los datos necesarios
	// Post: Crea un edificio con los datos especificados
    void addBuildingType(std::string name, int stone, int wood, int metal, int allowedAmount);
    
};

#endif