#pragma once
#include"Entidad.h"

class Cliente : public Entidad{

protected:
	bool isVIP;
	char** caracteres;
public:
	//constructores
	Cliente() {}
	Cliente(short posX, short posY, short v, short dX, short dY, bool isVIP, char** carcateres) :Entidad(posX, posY, v, dX, dY) {
		this->isVIP = isVIP;
		caracteres = new char* [0];
	}
	~Cliente() {}
	//Destructor



};