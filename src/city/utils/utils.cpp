#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iterator>

#include "utils.h"
#include "paths.h"
#include "../../consts/consts.h"

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
    map->createMap(height, width);
    for (int xCoord = 0; xCoord < height; xCoord++){
        for (int yCoord = 0; yCoord < width; yCoord++){
            mapFile >> tileType;
            map -> addTile(xCoord, yCoord, tileType);
            map -> setRoadTileAmount(map -> countRoadTileAmount(height, width, tileType));
        }
    }
}

void loadMaterials(MaterialsList* materialsList) {
  fstream materialsFile(PATH_MATERIALS, ios::in);
    if (!materialsFile.is_open()) {
        cout << "File not found: " << PATH_MATERIALS << endl;
        return;
    }
    
    Material* newMaterial;
    string name;
    int materialQuantity;
    while (materialsFile >> name) {
        newMaterial = new Material();
        newMaterial-> setName(name);
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
    int buildingError = city -> addBuilding(name, trimCoords(xCoord), trimCoords(yCoord), true);
    if (buildingError) {
      cout << "No se pudo crear el edifcio " << name << buildingError << endl;
    }
  }
}

void saveBuildings(City* city) {
    fstream buildingsFile(PATH_BUILDINGS, ios::out);
    if(!(buildingsFile.is_open())) {
        cout  << "No se pudo abrir el archivo " << PATH_BUILDINGS << " para guardar los datos."  << endl;
        return;
    }

    BuildingType** buildingTypes = city -> getBuildingTypes();
    int numberOfBuildings = city -> getNumberOfBuilding();
    for(int i = 0; i < numberOfBuildings; i++) {
        buildingsFile << buildingTypes[i] -> getName() << " ";
        buildingsFile << buildingTypes[i] -> getTemplate() -> getStoneQuantity() << " ";
        buildingsFile << buildingTypes[i] -> getTemplate() -> getWoodQuantity() << " ";
        buildingsFile << buildingTypes[i] -> getTemplate() -> getMetalQuantity() << " ";
        buildingsFile << buildingTypes[i] -> getBuiltAmount() + buildingTypes[i] -> getRemaining() << endl;
    }
    buildingsFile.close();
}

void saveMaterials(City* city) {
    fstream materialsFile(PATH_MATERIALS, ios::out);
    if(!(materialsFile.is_open())) {
        cout  << "No se pudo abrir el archivo " << PATH_MATERIALS << " para guardar los datos."  << endl;
        return;
    }

    Material** materials = city -> getMaterials();
    int numberOfMaterials =  city -> getNumberOfMaterials();
    for (int i = 0; i < numberOfMaterials; i++)
        materialsFile << materials[i] -> getName() << ":\t" << materials[i] -> getQuantity() << endl;
    materialsFile.close();
}

void saveMap(City* city) {
    fstream mapFile(PATH_MAP, ios::out);
    if(!(mapFile.is_open())) {
        cout  << "No se pudo abrir el archivo " << PATH_MAP << " para guardar los datos."  << endl;
        return;
    }

    int height = city -> getMap() -> getHeight();
    int width = city -> getMap() -> getWidth();
    mapFile << height << " " << width << endl;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            string tileType = city -> getMap() -> getTile(i, j) -> getType();
            if(tileType == LAKE) 
                mapFile << "L" << " ";
            else if(tileType == GROUND) 
                mapFile << "T" << " ";
            else if(tileType == ROAD)
                mapFile << "C" << " ";
        }
        mapFile << endl;
    }
    mapFile.close();
}

void saveLocations(City* city) {
    fstream locationsFile(PATH_LOCATIONS, ios::out);
    if(!(locationsFile.is_open())) {
        cout  << "No se pudo abrir el archivo " << PATH_LOCATIONS << " para guardar los datos."  << endl;
        return;
    }
    int height = city -> getMap() -> getHeight();
    int width = city -> getMap() -> getWidth();
    for(int x = 0; x < height; x++) {
        for(int y = 0; y < width; y++) {
            Tile * tile = city -> getMap() -> getTile(x, y);
            if(tile -> getType() == GROUND) {
              GroundTile* groundTile = static_cast<GroundTile*>(tile);
              if(groundTile -> isAvailable() == false){
                locationsFile << groundTile -> getBuildingTemplate().getName();
                locationsFile << " (" << x << ", " << y << ")" << endl;
                }
                
            }  
        }
    }
    locationsFile.close();
}



int trimCoords(std::string coord){
    return stoi(std::regex_replace(coord, std::regex(R"([\D])"), ""));
};