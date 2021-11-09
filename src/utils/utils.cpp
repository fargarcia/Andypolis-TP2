#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iterator>
#include <limits>

#include "utils.h"
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

void showInventory(City* city) {
  Material** materials = city -> getMaterials();
  int numberOfMaterials =  city -> getNumberOfMaterials();
  cout << "----------------------" << endl;
  cout << "Listado de materiales:\n" << endl;
  for (int i = 0; i < numberOfMaterials; i++)
    cout << materials[i] -> getName() << ":\t" << materials[i] -> getQuantity() << endl;
  cout << "----------------------" << endl;
}

void listAllBuildings(City* city) {
    BuildingType** buildingTypes = city -> getBuildingTypes();
    int numberOfBuildings = city -> getNumberOfBuilding();
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "Listado de edificios:\n" << endl;
    cout << "Nombre\t\tPiedra\t\tMadera\t\tMetal\t\tConstruidos\t\tPermitidos restantes" << endl;
    for (int i = 0; i < numberOfBuildings; i++) {
        cout << buildingTypes[i] -> getName() <<" "<< "\t";
        cout << buildingTypes[i] -> getTemplate() -> getStoneQuantity() << "\t\t";
        cout << buildingTypes[i] -> getTemplate() -> getWoodQuantity() << "\t\t";
        cout << buildingTypes[i] -> getTemplate() -> getMetalQuantity()<< "\t\t";
        cout << buildingTypes[i] -> getBuiltAmount() << "\t\t\t";
        cout << buildingTypes[i] -> getRemaining() << endl;
    }
    cout << "----------------------------------------------------------------------------" << endl;
}

void listBuiltBuildings(City* city) {
    BuildingType** buildingTypes = city -> getBuildingTypes();
    int numberOfBuildings = city -> getNumberOfBuilding();
    cout << "----------------------------------------------------------------------------" << endl;
    for(int i = 0; i < numberOfBuildings; i++) {
        cout << "building amount" << buildingTypes[i] -> getBuiltAmount() << endl;
        if(buildingTypes[i] -> getBuiltAmount() != 0) {
            cout << buildingTypes[i] -> getName() <<" "<< "\t";
            cout << buildingTypes[i] -> getBuiltAmount() << "\t\t\t";
            // FALTA AGREGAR LAS COORDENADAS DONDE ESTÁ CADA EDIFICIO
        }
    }
    cout << "----------------------------------------------------------------------------" << endl;
}

void askForOption(int* option) {
    cout << "Ingrese el numero de la accion que desea realizar." << endl;
    cin >> *option;
}

void validateSelectedOption(int& selectedOption) {
    bool validOption = false;
    while(validOption == false) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(sizeof(int), '\n');
            cout << TXT_RED_196 << "La opcion elegida no es una opcion valida, por favor seleccione otra opcion" << END_COLOR << endl;
            askForOption(&selectedOption);
        }
        else if (selectedOption <= 0  || selectedOption > 10) {
            cout << TXT_RED_196 << "La opcion elegida no es una opcion valida, por favor seleccione otra opcion" << END_COLOR << endl;
            askForOption(&selectedOption);
        }
            validOption = true;
    }
}

void processOption(City* city, int &option) {
    switch(option) {
        case BUILD_BY_NAME:
            //buildByName();
            break;
        case LIST_BUILT_BUILDINGS:
            listBuiltBuildings(city);
            break;
        case LIST_ALL_BUILDINGS:
            listAllBuildings(city);
            break;
        case DEMOLISH_BUILDING_BY_COORDINATES:
            //demolishByCoordinates();
            break;
        case SHOW_MAP:
            city -> getMap() ->showMap();
            //showMap();
            break;
        case CHECK_COORDINATE:
            //checkCoordinates();
            break;
        case SHOW_INVENTORY:
            showInventory(city);
            break;
        case COLLECT_RESOURCES_PRODUCED:
            //collectResources();
            break;
        case RAIN_OF_RESOURCES:
            //resourcesRain();
            break;
        case QUIT_AND_SAVE:
            //saveAndExit();
            break;
        case QUIT:
            break;
        default:
            cout << "ERROR" << endl;
            break;

    }
}