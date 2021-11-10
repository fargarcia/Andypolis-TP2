#ifndef UTILS_H
#define UTILS_H

#include "../materials/materials.h"
#include "../materials/materialsList.h"
#include "../buildings/buildings.h"
#include "../map/map.h"
#include "../city/city.h"

// Pre: -
// Post: Muestra el menu
void showMenu();

// Pre: -
// Post: Solicita al usuario que ingrese una opcion
void requestOption(int* option);
// Pre: -
// Post: Solicita al usuario que ingrese el nombre de un edificio
void RequestBuildingName(string* buildingName);
// Pre: Recibir el nombre
// Post: Devuelve true si el nombre es correcto y false en caso contrario
bool isValidBuildingName(string buildingName);
// Pre: -
// Post: Solicita al usuario que ingrese las coordenadas x e y
void RequestCoord(int* xCoord, int* yCoord);
// Pre: Recibir las coordenadas y un puntero a la ciudad
// Post: Devuelve true si las coordenadas son correctas y false en caso contrario
bool isValidCoord(int xCoord, int yCoord, City* city);
// Pre: -
// Post: Devuelve true si el usuario confirma que desea construir el edificio y 
// false en caso contrario
bool confirmBuildingRequest(string name, int xCoord, int yCoord);
// Pre: -
// Post: Devuelve true si el usuario confirma que desea demoler el edificio y 
// false en caso contrario
bool confirmDemolishionRequest(string name, int xCoord, int yCoord);
// Pre: Recibir la opcion seleccionada
// Post: Valida que la opcion seleccionada sea correcta, es decir, 
// que se encuentre dentro de los limites de opciones y que sea un numero
void validateSelectedOption(int& selectedOption);
// Pre: Recibir un puntero a la ciudad, y la opcion seleccionada
// Post: Se encarga de invocar a distintas funciones dependiendo de la opcion 
// seleccionada por el usuario
void processOption(City* city, int &option);

// Pre: Recibir un puntero a la ciudad
// Post: Se encarga de guardar los archivos con los datos actualizados y
// salir del programa
void saveAndQuit(City* city);
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


// Pre: Recibir un puntero a la ciudad
// Post: Muestra por consola todos los edificios construidos hasta el 
// momento con su informacion
void listBuiltBuildings(City* city);
// Pre: Recibir un puntero a la ciudad
// Post: Muestra por consola todos los edificios que se encuentren en el 
// archivo edificios.txt con su informacion sin importar si se encuentran
// construidos o no
void listAllBuildings(City* city);
// Pre: Recibir un puntero a la ciudad
// Post: Muestra todos los materiales que se tienen en el momento
void showInventory(City* city);


/*
* ESTAS FUNCIONES NO ESTAN EN EL ARCHIVO utils.cpp
*/

// Pre: Recibir el nombre del edificio que se desee crear
// Post: Crea un edificio con el nombre recibido
void buildByName(City* city);
// Pre: Recibir coordenadas validas
// Post: Destruye el edificio ubicado en las coordenadas recibidas
void demolishByCoordinates();
// Pre: -
// Post: 
void showMap();
// Pre: -
// Post: 
void checkCoordinates();
// Pre: -
// Post: 
void collectResources();
// Pre: -
// Post: 
void resourcesRain();
#endif