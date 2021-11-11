#include "template.h"

//// Building
// Constructor
Template::Template(){};
Template::Template(std::string templateName, int stone, int wood, int metal) {
	name = templateName;
	stoneQuantity = stone;
	woodQuantity = wood;
	metalQuantity = metal;
}

Template::~Template(){};

Template::Template(const Template& copy){
	name = copy.name;
	stoneQuantity = copy.stoneQuantity;
	woodQuantity = copy.woodQuantity;
	metalQuantity = copy.metalQuantity;
	return;
};

void Sawmill::collectResource(std::string& name, int& amount){
	name = "madera";
	amount = 25;
}

void Mine::collectResource(std::string& name, int& amount){
	name = "piedra";
	amount = 15;
}

void Factory::collectResource(std::string& name, int& amount){
	name = "metal";
	amount = 40;
}

// getters
std::string Template::getName() {
  	return name;
}

int Template::getStoneQuantity() {
 		return stoneQuantity;
}

int Template::getWoodQuantity() {
  	return woodQuantity;
}

int Template::getMetalQuantity() {
  	return metalQuantity;
}
