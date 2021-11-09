#ifndef UTILS_H
#define UTILS_H

#include "../materials/materials.h"
#include "../materials/materialsList.h"
#include "../buildings/buildings.h"
#include "../map/map.h"
#include "../city/city.h"

void showMenu();

void askForOption(int* option);
void validateSelectedOption(int& selectedOption);
void processOption(City* city, int &option);

void buildByName();
void listBuiltBuildings(City* city);
void listAllBuildings(City* city);
void demolishByCoordinates();
void showMap();
void checkCoordinates();
void showInventory(City* city);
void collectResources();
void resourcesRain();
void saveAndExit();


#endif