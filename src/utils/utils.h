#ifndef UTILS_H
#define UTILS_H

#include "../materials/materials.h"
#include "../materials/materialsList.h"
#include "../buildings/buildings.h"
#include "../buildings/buildingsList.h"

void showMenu();

void loadMaterials(MaterialsList* materialsList);
void loadBuildings(BuildingsList* buildingsList);

void buildByName();
void listBuilt();
void listAllBuildings(BuildingsList* buildingsList);
void demolishByCoordinates();
void showMap();
void checkCoordinates();
void showInventory(MaterialsList* materialsList);
void collectResources();
void resourcesRain();
void saveAndExit();


#endif