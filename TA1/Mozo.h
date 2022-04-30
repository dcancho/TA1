#pragma once
#include"Entidad.h"

class Mozo : public Entidad {
protected:
	short score;
	char caracteres;
public:
	//constructores
	Mozo(){}
	Mozo(short posX, short posY, short v, short dX, short dY, short score, char* caracteres) :Entidad(posX, posY, v, dX, dY) {
		this->score = score;
		caracteres = new char[2];
	}
	//Destructor
	~Mozo() {}
};