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
		// Pre: -
		// Post: Crea una instancia de la clase
		Template();
		// Pre: Recibir los datos necesarios
		// Post: Crea una instancia de la clase con los datos especificados
    	Template(std::string templateName, int stone, int wood, int metal);
		// Pre: Recibir el objeto el cual se va a copiar
		// Post: Crea una instancia de la clase mediante una copia del objeto recibido
		Template(const Template& copy);
    
		// Destructor
		~Template();

		// Getters
		// Pre: 
		// Post: Devuelve el atributo nombre de la clase
		std::string getName();
		// Pre: 
		// Post: Devuelve el atributo cantidad de piedra de la clase
		int getStoneQuantity();
		// Pre: 
		// Post: Devuelve el atributo cantidad de madera de la clase
		int getWoodQuantity();
		// Pre: 
		// Post: Devuelve el atributo cantidad de metal de la clase
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
