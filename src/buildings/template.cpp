#include <iostream>
#include "template.h"

using namespace std;

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
