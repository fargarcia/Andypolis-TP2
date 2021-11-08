#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iterator>

#include "utils.h"
#include "paths.h"

#include <string>
#include <regex>


using namespace std;

void loadMap(Map* map){
  fstream mapFile(PATH_MAP, ios::in);
    if (!mapFile.is_open())
        cout << "File not found: " << PATH_MAP << endl;
  int height, width;
  std::string tileType;
  mapFile >> height;
  mapFile >> width;
  map = new Map(height, width);
  for (int xCoord = 0; xCoord < height; xCoord++){
    for (int yCoord = 0; yCoord < width; yCoord++){
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
    
  string name;
  int stone, wood, metal, allowedAmount;
  while (buildingsFile >> name) {
    buildingsFile >> stone;
    buildingsFile >> wood;
    buildingsFile >> metal;
    buildingsFile >> allowedAmount;
    buildingsList->addBuildingType(name, stone, wood, metal, allowedAmount);
  }
  buildingsFile.close();
  return;
}

void loadLocations(City* city){
  fstream locationsFile(PATH_LOCATIONS, ios::in);
  if (!locationsFile.is_open()) {
    cout << "File not found: " << PATH_LOCATIONS << endl;
    return;
  }
  string name, xCoord, yCoord;
  while (locationsFile >> name) {
    locationsFile >> xCoord;
    locationsFile >> yCoord;
    city -> addBuilding(name, trimCoords(xCoord), trimCoords(yCoord));
  }
}

int trimCoords(std::string coord){
    return stoi(std::regex_replace(coord, std::regex(R"([\D])"), ""));
};