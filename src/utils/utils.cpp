#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iterator>

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
