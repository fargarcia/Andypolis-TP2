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

Material* MaterialsList::getMaterial(std::string name){
  int i = 0;
  cout << "number of materials" << numberOfMaterials << endl;
  while (i < numberOfMaterials && name != materials[i] -> getName()) {

      cout << "nombre:: " << name << endl;
      cout << "nombre" << materials[i] -> getName() << endl;
      i++;
      cout << "i:" << i << endl;
  }
  cout << i << endl;
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
  cout << "a" << endl;
  Material* material = getMaterial(name);
  cout << "b" << endl;
  cout << name << endl;;
  cout << material -> getQuantity()<< endl;
  int newAmount = material -> getQuantity() + amount;
  cout << "c" << endl;
  material -> setQuantity(newAmount);
  cout << "d" << endl;
}