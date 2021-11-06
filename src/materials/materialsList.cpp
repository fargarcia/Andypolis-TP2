#include <iostream>
#include "materialsList.h"
#include "materials.h"

using namespace std;

//// MaterialsList
// Constructor sin argumentos
MaterialsList::MaterialsList() {
	materials = new Material * [0];
	numberOfMaterials = 0;
}

int MaterialsList::getNumberOfMaterials() {
  return numberOfMaterials;
}

Material ** MaterialsList::getMaterials() {
  return materials;
};

void MaterialsList::addMaterial(Material *newMaterial) {
	Material** newMaterialsVector = new Material *[numberOfMaterials+1];
  copy(materials, materials + numberOfMaterials , newMaterialsVector);
  newMaterialsVector[numberOfMaterials] = newMaterial;
  materials = newMaterialsVector;
  numberOfMaterials++;
}