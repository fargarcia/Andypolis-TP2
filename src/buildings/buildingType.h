#ifndef	BUILDING_TYPE_H
#define BUILDING_TYPE_H
#include <iostream>
#include "template.h"

class BuildingType {
    private:
	    std::string name;
		int built;
		int allowed;
		Template buildingTemplate;

    public:
        BuildingType(std::string newName, int newAllowed, Template* newBuildingTemplate);
        ~BuildingType();

        std::string getName();
        int getBuiltAmount();
        int getRemaining();
        Template * getTemplate();
};


#endif