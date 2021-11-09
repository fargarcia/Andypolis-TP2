#include <iostream>
#include "./utils/utils.h"
#include "./materials/materials.h"
#include "./buildings/buildings.h"
#include "./map/map.h"
#include "./city/city.h"
#include "./consts/consts.h"

using namespace std;

#ifdef __linux__
#define CLR_SCREEN "clear"
#endif

#ifdef __MINGW32__
#define CLR_SCREEN "CLS"
#endif

int main() {
  int option = ERROR;
  City city = City();

  while(option != QUIT) {
      showMenu();
      askForOption(&option);
      validateSelectedOption(option);
      system(CLR_SCREEN);
      processOption(&city, option);
  }
 
  return 0;
}