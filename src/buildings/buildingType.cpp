#include "buildingType.h"

BuildingType::BuildingType(std::string newName, int newAllowed, Template* newBuildingTemplate){
    name = newName;
    built = 0;
    allowed = newAllowed;
    buildingTemplate = *newBuildingTemplate;
}

BuildingType::~BuildingType(){};

std::string BuildingType::getName() {
    return name;
};

int BuildingType::getBuiltAmount() {
    return built;
}

int BuildingType::getRemaining(){
    return allowed - built;
}

Template * BuildingType::getTemplate() {
    return &buildingTemplate;
}

bool BuildingType::addBuilding(){
    if(getRemaining() > 0){
        built ++;
        return true;
    }
    return false;
}

void BuildingType::removeBuilding(){
    built--;
}