#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iterator>

#include "utils.h"
#include "auxUtils.h"
#include "../materials/materials.h"
#include "../materials/materialsList.h"
#include "../buildings/buildings.h"
#include "../consts/consts.h"
#include "../consts/colors.h"
#include "../map/map.h"

using namespace std;

void showMenu() {
    cout << "\n" << "\t\t\t\t\t\t" << BGND_DARK_AQUA_24 << "                 Menu:                   " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "                                         " << END_COLOR << endl;
  	cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  1.  Construir edificio por nombre      " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  2.  Listar los edificios construidos   " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  3.  Listar todos los edificios         " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  4.  Demoler un edificio por coordenada " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  5.  Mostrar mapa                       " << END_COLOR << endl;
  	cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  6.  Consultar coordenada               " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  7.  Mostrar inventario.                " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  8.  Recolectar recursos producidos     " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  9.  Lluvia de recursos                 " << END_COLOR << endl;
    cout << "\t\t\t\t\t\t"         << BGND_DARK_AQUA_24 << "  10. Guardar y salir                    " << END_COLOR << "\n" <<endl;
}

void loadMap(Map* map){
  fstream mapFile(PATH_MAP, ios::in);
    if (!mapFile.is_open())
        cout << "File not found: " << PATH_MAP << endl;

  int height, width;
  std::string tileType;
  mapFile >> height;
  mapFile >> width;

  map = new Map(height, width);

  for (int yCoord = 0; yCoord < height; yCoord++){
    for (int xCoord = 0; xCoord < width; xCoord++){
      mapFile >> tileType;
      map -> addTile(xCoord, yCoord, tileType);
    }
  } 
  return;
}

void loadMaterials(MaterialsList* materialsList) {
  fstream materialsFile(PATH_MATERIALS, ios::in);
    if (!materialsFile.is_open())
        cout << "File not found: " << PATH_MATERIALS << endl;
    
    Material* newMaterial;
    string name;
    int materialQuantity;
    while (materialsFile >> name) {
        newMaterial = new Material();
        newMaterial->setName(name);
        materialsFile >> materialQuantity;
        newMaterial->setQuantity(materialQuantity);
        materialsList->addMaterial(newMaterial);
    }
    materialsFile.close();
}

void loadBuildings(Buildings* buildingsList) {
  fstream buildingsFile(PATH_BUILDINGS, ios::in);
  if (!buildingsFile.is_open()) {
    cout << "File not found: " << PATH_BUILDINGS << endl;
    return;
  }
    
  string name, location, xCoord, yCoord;
  int stone, wood, metal, allowedAmount;
  while (buildingsFile >> name) {
    buildingsFile >> stone;
    buildingsFile >> wood;
    buildingsFile >> metal;
    buildingsFile >> allowedAmount;
    buildingsList->addBuildingType(name, stone, wood, metal, allowedAmount);
  }
  buildingsFile.close();
  
  /*
  fstream locationsFile(PATH_LOCATIONS, ios::in);
  if (!locationsFile.is_open())
    cout << "File not found: " << PATH_LOCATIONS << endl;
  */
}

void showInventory(MaterialsList* materialsList) {
  Material** materialsVector = materialsList->getMaterials();
  int numberOfMaterials =  materialsList->getNumberOfMaterials();
  cout << "----------------------" << endl;
  cout << "Listado de materiales:\n" << endl;
  for (int i = 0; i < numberOfMaterials; i++)
    cout << materialsVector[i] -> getName() << ":\t" << materialsVector[i] -> getQuantity() << endl;
  cout << "----------------------" << endl;
}

void listAllBuildings(Buildings* buildingsList) {
  BuildingType** buildingsVector = buildingsList -> getBuildingTypes();
  int numberOfBuildings = buildingsList -> getNumberOfBuilding();
  cout << "----------------------------------------------------------------------------" << endl;
    cout << "Listado de edificios:\n" << endl;
    cout << "Nombre\t\tPiedra\t\tMadera\t\tMetal\t\tConstruidos\t\tPermitidos restantes" << endl;
    for (int i = 0; i < numberOfBuildings; i++) {
        cout << buildingsVector[i] -> getName() <<" "<< "\t";
        cout << buildingsVector[i] -> getTemplate() -> getStoneQuantity() << "\t\t";
        cout << buildingsVector[i] -> getTemplate() -> getWoodQuantity() << "\t\t";
        cout << buildingsVector[i] -> getTemplate() -> getMetalQuantity()<< "\t\t";
        cout << buildingsVector[i] -> getBuiltAmount() << "\t\t\t";
        cout << buildingsVector[i] -> getRemaining() << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
}
