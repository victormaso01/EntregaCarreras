#pragma once
#include <iostream>
class Motora
{
private:
	int position;
	int velocidad;
	std::string nombre;
	std::string pilotName;
	int recorrido;
	bool turbo;
	int seleccionado;

public:
	//constructor
	Motora(int position, int pVelocidad, std::string pPilotName, std::string pNombre, int pRecorrido, bool pTurbo, int pSeleccionado);
	
	


	//getters
	int getVel();

	int getPos();

	std::string getPilotName();

	std::string getName();

	int getRec();

	bool getTurbo();

	int getSelec();

	//setters

	void setVel(int pVelocidad);

	void setName(std::string pNombre);

	void setTurbo(bool turbo);

	void setRec(int pRecorrido);

	void setPilotName(std::string pPilotName);

	void setPos(int pPosition);

	void setSelect(int pSeleccionado);
	
	//metodos
	void presentation();
	void posicionFinal();
};

