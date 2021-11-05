#ifndef MATERIALS_H
#define MATERIALS_H

class Material {
	private:
		std::string materialName;
		int materialQuantity;

	public:
		// Constructores
		Material();
    //Material(&Material);
		
		// Destructor
		~Material();

		// Getters
		std::string getName();
		int getQuantity();

		// Setters
		void setName(std::string name);
		void setQuantity(int Quantity);
};



#endif
