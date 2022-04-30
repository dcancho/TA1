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
	//getters
	short getposX_Mozo() { return posX; }
	short getposY_Mozo() { return posY; }
	short getdX_Mozo() { return dX; }
	short getdY_Mozo() { return dY; }
	short getScore() { return score; }
	//setters
	void setposX_Mozo(short v) { posX = v; }
	void setposY_Mozo(short v) { posY = v; }
	void setdX_Mozo(short v) { dX = v; }
	void setdY_Mozo(short v) { dY = v; }
	void setScore(short v) { score = v; }
};