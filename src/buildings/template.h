#ifndef	TEMPLATE_H
#define TEMPLATE_H

#include <iostream>

using namespace std;

class Template {
	private:
		std::string name;
		int stoneQuantity;
		int woodQuantity;
		int metalQuantity;

	public:
		// Constructores
		Template();
    	Template(std::string templateName, int stone, int wood, int metal);
		Template(const Template& copy);
    
		// Destructor
		~Template();

		// Getters
		std::string getName();
		int getStoneQuantity();
		int getWoodQuantity();
		int getMetalQuantity();
};

class Mine : public Template {
	using Template::Template;
};
class Sawmill : public Template {
	using Template::Template;
};
class Factory : public Template {
	using Template::Template;
};
class School : public Template {
	using Template::Template;
};
class Obelisk : public Template {
	using Template::Template;
};
class PowerPlant : public Template {
	using Template::Template;
};
class GenericBuilding : public Template {
	using Template::Template;
};

#endif
