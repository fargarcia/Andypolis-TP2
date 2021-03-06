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
    bool success = false;
    if(getRemaining() > 0){
        built++;
        success = true;
    }
    return success;
}

void BuildingType::removeBuilding(){
    built--;
}