#include <iostream>
#include "materials.h"

using namespace std;

//// Material
// Constructor sin argumentos
Material::Material() {
	materialName = ' ';
	materialQuantity = 0;
}

// Destructor
Material::~Material() {}

// Setters
void Material::setName(string name) {
	materialName = name;
}

void Material::setQuantity(int quantity) {
	materialQuantity = quantity;
}

// Getters
string Material::getName() {
	return materialName;
}

int Material::getQuantity() {
	return materialQuantity;
}


