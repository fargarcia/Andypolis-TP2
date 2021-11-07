#ifndef CONSTS_H
#define CONSTS_H
const int VALID_OPTIONS = 10;

enum option_t
{
	ERROR 								= -1,
	BUILD_BY_NAME 						= 1,
	LIST_BUILT_BUILDINGS 				= 2,
	LIST_ALL_BUILDINGS 					= 3,
	DEMOLISH_BUILDING_BY_COORDINATES 	= 4,
	SHOW_MAP 							= 5,
	CHECK_COORDINATE 					= 6,
	SHOW_INVENTORY 						= 7,
	COLLECT_RESOURCES_PRODUCED 			= 8,
	RAIN_OF_RESOURCES 					= 9,
	QUIT_AND_SAVE 						= 10,
	QUIT 								= 11
};

const std::string	MINE 		= "mina";
const std::string	SAWMILL 	= "aserradero";
const std::string	FACTORY 	= "fabrica";
const std::string	SCHOOL 		= "escuela";
const std::string	OBELISK 	= "obelisco";
const std::string	POWER_PLANT = "planta electrica";

const std::string 	PATH_MATERIALS 	= "./textFiles/materiales.txt";
const std::string 	PATH_BUILDINGS 	= "./textFiles/edificios.txt";
const std::string 	PATH_LOCATIONS 	= "./textFiles/ubicaciones.txt";
const std::string 	PATH_MAP 		= "./textFiles/map.txt";


#endif