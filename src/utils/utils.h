#ifndef UTILS_H
#define UTILS_H

#include "../materials/materials.h"
#include "../materials/materialsList.h"
#include "../buildings/buildings.h"
#include "../map/map.h"
#include "../city/city.h"

void showMenu();

void askForOption(char* option);
int castCharToInt(char selectedOption);
bool validateSelectedOption(char& selectedOption);
void checkValidOption(char option);
void processOption(City* city, char &option);

void buildByName();
void listBuilt();
void listAllBuildings(City* city);
void demolishByCoordinates();
void showMap();
void checkCoordinates();
void showInventory(City* city);
void collectResources();
void resourcesRain();
void saveAndExit();


#endif