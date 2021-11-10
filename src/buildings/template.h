#ifndef	TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include "../consts/consts.h"

using namespace std;

class Template {
	private:
		std::string name;
		int stoneQuantity;
		int woodQuantity;
		int metalQuantity;
		std::string resourceProduced;
		int amountProduced;

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

		void collectResource(std::string& name, int& amount);
};

class Mine : public Template {
	using Template::Template;
	public:
		std::string resourceProduced = ROCK;
		int amountProduced = 15;
};
class Sawmill : public Template {
	using Template::Template;
	public:
		std::string resourceProduced = WOOD;
		int amountProduced = 25;
};
class Factory : public Template {
	using Template::Template;
	public:
		std::string resourceProduced = METAL;
		int amountProduced = 40;
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

