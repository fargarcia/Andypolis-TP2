#include <iostream>
#include "materialsList.h"
#include "materials.h"
#include "../consts/consts.h"

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

Material * MaterialsList::getMaterial(std::string name){
  int i = 0;
  while (i < numberOfMaterials && name != materials[i] -> getName()) i++;
  return i == numberOfMaterials ? NULL : materials[i];
};

int  MaterialsList::getAvailableRock(){
  return getMaterial(ROCK) -> getQuantity();
};
int  MaterialsList::getAvailableWood(){
  return getMaterial(WOOD) -> getQuantity();
};
int  MaterialsList::getAvailableMetal(){
  return getMaterial(METAL) -> getQuantity();
};

void MaterialsList::increaseMaterial(std::string name, int amount){
  Material* material = getMaterial(name);
  int newAmount = material -> getQuantity() + amount;
  material -> setQuantity(newAmount);
}