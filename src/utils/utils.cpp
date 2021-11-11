#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iterator>
#include <string>

#include "utils.h"
#include "../materials/materials.h"
#include "../materials/materialsList.h"
#include "../buildings/buildings.h"
#include "../consts/consts.h"
#include "../consts/colors.h"
#include "../map/map.h"
#include "../city/utils/paths.h"
#include "../city/consts/errors.h"

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
    cout << "----------------------" << endl;
    cout << "Edificios construidos:\n" << endl;
    int height = city -> getMap() -> getHeight();
    int width = city -> getMap() -> getWidth();
    for(int x = 0; x < height; x++) {
        for(int y = 0; y < width; y++) {
            Tile * tile = city -> getMap() -> getTile(x, y);
            if(tile -> getType() == GROUND) {
              GroundTile* groundTile = static_cast<GroundTile*>(tile);
              if(groundTile -> isAvailable() == false){
                cout << groundTile -> getBuildingTemplate().getName();
                cout << " (" << x << ", " << y << ")" << endl;
                }
                
            }  
        }
    }
    cout << "----------------------" << endl;
}

void requestOption(int* option) {
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
            requestOption(&selectedOption);
        }
        else if (selectedOption <= 0  || selectedOption > 10) {
            cout << TXT_RED_196 << "La opcion elegida no es una opcion valida, por favor seleccione otra opcion" << END_COLOR << endl;
            requestOption(&selectedOption);
        }
            validOption = true;
    }
}

void processOption(City* city, int &option) {
    switch(option) {
        case BUILD_BY_NAME:
            buildByName(city);
            break;
        case LIST_BUILT_BUILDINGS:
            listBuiltBuildings(city);
            break;
        case LIST_ALL_BUILDINGS:
            listAllBuildings(city);
            break;
        case DEMOLISH_BUILDING_BY_COORDINATES:
            demolishByCoordinates(city);
            break;
        case SHOW_MAP:
            city -> getMap() ->showMap();
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
            option = QUIT;
            break;
        default:
            cout << "ERROR" << endl;
            break;

    }
}

void RequestBuildingName(string* buildingName) {
    string aux;
    cout << "Por favor, ingrese el nombre del edificio" << endl;
    cin >> *buildingName;
    if(*buildingName == "planta") {
        cin >> aux;
        *buildingName = *buildingName + aux;
    }
}

bool isValidBuildingName(string buildingName) {
    bool isValid = true;
    if(buildingName != MINE && buildingName != SAWMILL && buildingName != FACTORY && 
    buildingName != SCHOOL && buildingName != OBELISK && buildingName != POWER_PLANT) {
        isValid = false;
    }

    return isValid;
}

void requestCoord(int* coord, char axe) {
    cout << "Por favor, ingrese la coordenada " << axe << endl;
    cin >> *coord;
}

bool isValidCoord(int coord, int max, char axe) {
    bool validOption = false;
    while(validOption == false) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(sizeof(int), '\n');
            cout << TXT_RED_196 << "La coordenada ingresada es invalida, por favor ingrese nuevamente" << END_COLOR << endl;
            requestCoord(&coord, axe);
        }
        else if (coord <= 0  || coord > max) {
            cout << TXT_RED_196 << "La coordenada ingresada es invalida, por favor ingrese nuevamente" << END_COLOR << endl;
            requestCoord(&coord, axe);
        }
            validOption = true;
    }

    return validOption;
}

bool areValidCoords(int xCoord, int yCoord, City* city) {
    bool isValid = false;
    int height = city -> getMap() -> getHeight();
    int width = city -> getMap() -> getWidth();

    if(isValidCoord(xCoord, height, 'x'))
        isValid = true;
    if(isValidCoord(yCoord, width, 'y'))
        isValid = true;
  
    return isValid;
}

bool confirmActionRequest(string name, string action, int xCoord, int yCoord) {
    int option = ERROR;
    bool confirmation = false;
    while(option != 1 && option != 2) {
        cout << "¿Esta seguro que desea " << action << " el edificio " << name << 
        " en " << "la posicion (" << xCoord << ", " << yCoord << ")" << "?" << endl;
        cout << "\t 1. Si" << endl;
        cout << "\t 2. No" << endl;
        cin >> option;
        if(option == 1)
            confirmation = true;
    }
    return confirmation;
}

void buildByName(City* city) {
    string name;
    RequestBuildingName(&name);
    while(!(isValidBuildingName(name))) {
        RequestBuildingName(&name);
    }

    int xCoord, yCoord;
    requestCoord(&xCoord, 'x');
    requestCoord(&yCoord, 'y');
    
    while(!(areValidCoords(xCoord, yCoord, city)));
        
    if(confirmActionRequest(name, "construir", xCoord, yCoord)) {
        printError(city -> addBuilding(name, xCoord, yCoord, false));
    }
}

void demolishByCoordinates(City* city) {
    int xCoord, yCoord;
    requestCoord(&xCoord, 'x');
    requestCoord(&yCoord, 'y');

    areValidCoords(xCoord, yCoord, city);

    string name = city -> getBuildingName(xCoord, yCoord);

    if(confirmActionRequest(name, "demoler", xCoord, yCoord)) {
        if(city -> removeBuilding(xCoord, yCoord)){
            cout << "Se ha demolido un " << name << " en (" << xCoord << ", " << yCoord << ")" << endl;
        } else {
            cout << "No hay un edificio en esa coordenada "<< endl;
        }
    }
}

void checkCoordinates(City* city) {
    int xCoord, yCoord;
    requestCoord(&xCoord, 'x');
    requestCoord(&yCoord, 'y');

    Tile* tile = city -> getMap() -> getTile(xCoord, yCoord);
    std::string type = tile -> getType();
    if(type == LAKE){
        cout << "Soy un casillero del lago."<< endl;
    }
    if(type == GROUND){
        GroundTile* groundTile = static_cast<GroundTile*>(tile);
        if (groundTile->isAvailable()){
            cout << "Soy un construible y me encuentro vacío."<< endl;
        } else {
            std::string name = groundTile -> getBuildingTemplate().getName();
            cout << "Soy un/a "<< name << " y me encuentro en el casillero consultado." << endl;
        }
    }
    if(type == ROAD){
        RoadTile* roadTile = static_cast<RoadTile*>(tile);
        if (roadTile -> isAvailable()){
            cout << "Soy un transitable y me encuentro vacío."<< endl;
        } else {
            //roadTile ->
        }
    }
}

void printError(int error){
    switch (error){
    case NOT_ENOUGH_WOOD:
        cout << "No hay madera suficiente para construir el edificio" << endl;
        break;
    case NOT_ENOUGH_ROCK:
        cout << "No hay piedra suficiente para construir el edificio" << endl;
        break;
    case NOT_ENOUGH_METAL:
        cout << "No hay metal suficiente para construir el edificio" << endl;
        break;
    case NOT_AVAILABLE:
        cout << "No se pueden construir más edicfios de este tipo" << endl;
        break;
    case TERRAIN_NOT_SUITALBE:
        cout << "No se pueden construir edificios en este casillero" << endl;
        break;
    case OCUPIED_TILE:
        cout << "Ya existe un edificio en este casillero" << endl;
        break;
    case TYPE_NOT_FOUND:
        cout << "No existen edicfios de este tipo" << endl;
        break;   
    default:
        break;
    }
}
