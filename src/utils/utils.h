#ifndef UTILS_H
#define UTILS_H

#include "../materials/materials.h"
#include "../materials/materialsList.h"
#include "../buildings/buildings.h"
#include "../map/map.h"

void showMenu();

void loadMap(Map* map);
void loadMaterials(MaterialsList* materialsList);
void loadBuildings(Buildings* buildingsList);
void loadLocations(Map* map, Buildings* buildingList);

void buildByName();
void listBuilt();
void listAllBuildings(Buildings* buildingsList);
void demolishByCoordinates();
void showMap();
void checkCoordinates();
void showInventory(MaterialsList* materialsList);
void collectResources();
void resourcesRain();
void saveAndExit();


#endif