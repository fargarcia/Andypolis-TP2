#include <iostream>
#include "../utils/utils.h"
#include "../materials/materials.h"
#include "../buildings/buildings.h"
#include "../buildings/buildingsList.h"

using namespace std;

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif

int main() {
  std::cout << "Hello World!\n";

  system(CLR_SCREEN);

  //showMenu();

  //MaterialsList materialsList = MaterialsList();
  BuildingsList buildingsList = BuildingsList();

  //loadMaterials(&materialsList);
  //showInventory(&materialsList);

  loadBuildings(&buildingsList);
  listAllBuildings(&buildingsList);
  



  return 0;

}