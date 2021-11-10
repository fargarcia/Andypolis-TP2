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
// Pre: Recibir un puntero a la ciudad
// Post: Sobreescribe el archivo de edificios.txt con los nuevos datos
void saveBuildings(City* city);
// Pre: Recibir un puntero a la ciudad
// Post: Sobreescribe el archivo de materiales.txt con los nuevos datos
void saveMaterials(City* city);
// Pre: Recibir un puntero a la ciudad
// Post: Sobreescribe el archivo de mapa.txt con los nuevos datos
void saveMap(City* city);
// Pre: Recibir un puntero a la ciudad
// Post: Sobreescribe el archivo de ubicaciones.txt con los nuevos datos
void saveLocations(City* city);

int trimCoords(std::string coord);


#endif