#ifndef UTILS_H
#define UTILS_H

#include "../../materials/materials.h"
#include "../../materials/materialsList.h"
#include "../../buildings/buildings.h"
#include "../../map/map.h"
#include "../city.h"

void loadMap(Map* map);
void loadMaterials(MaterialsList* materialsList);
void loadBuildings(Buildings* buildingsList);
void loadLocations(City* city);

int trimCoords(std::string coord);


#endif