#pragma once
#include "motora.h"
#include <iostream>

	//contructor
Motora::Motora(int pPosition, int pVelocidad, std::string pPilotName, std::string pNombre, int pRecorrido, bool pTurbo, int pSeleccionado) {
	
	position = pPosition;
	velocidad = pVelocidad;
	nombre = pNombre;
	pilotName = pPilotName;
	recorrido = pRecorrido;
	turbo = pTurbo;
	seleccionado = pSeleccionado;
}


	//getters

int Motora::getPos() {
	return position;
}
int Motora::getVel() {
	return velocidad;
}

std::string Motora::getName() {
	return nombre;
}

std::string Motora::getPilotName() {
	return pilotName;
}

int Motora::getRec() {
	return recorrido;
}

bool Motora::getTurbo() {
	return turbo;
}


int Motora::getSelec() {
	return seleccionado;
}


	//setters
void Motora::setPos(int pPosition) {
	position = pPosition;
}

void Motora::setVel(int pVelocidad) {
	velocidad = pVelocidad;
}

void Motora::setRec(int pRecorrido) {
	recorrido = pRecorrido;
}

void Motora::setName(std::string pNombre) {
	nombre = pNombre;
}

void Motora::setPilotName(std::string pPilotName) {
	pilotName = pPilotName;
}

void Motora::setTurbo(bool pTurbo) {
	turbo = pTurbo;
}

void Motora::setSelect(int pSeleccionado) {
	seleccionado = pSeleccionado;
}

	//metodos propios
void Motora::presentation() {
	std::cout << "El piloto " << getPilotName() << " con su vehiculo " << getName() << " estan listos para la carrera." << std::endl;
}

void Motora::posicionFinal() {
	std::cout << "El piloto " << getPilotName() << " ha finalizado la carrera en " << getPos() << " con una distancia de " << getRec() << " kilometros. Buena carrera!" << std::endl;
}


