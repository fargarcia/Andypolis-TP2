#ifndef MATERIALSLIST_H
#define MATERIALSLIST_H

#include "materials.h"

class MaterialsList { 
	private:
		Material ** materials;
		int numberOfMaterials;
    
	public:
    // Constructores
		MaterialsList();

		// Getters
		Material ** getMaterials();
		int getNumberOfMaterials();
		Material * getMaterial(std::string name);
		int getAvailableRock();
		int getAvailableWood();
		int getAvailableMetal();

    // Setters
		void addMaterial(Material *newMaterial);
};

#endif