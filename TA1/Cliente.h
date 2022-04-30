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
	//Destructor
	~Cliente() {}
	//getters
	short getposX_Cliente() { return posX; }
	short getposY_Cliente() { return posY; }
	short getdX_Cliente() { return dX; }
	short getdY_Cliente() { return dY; }
	short isVIP() { return isVIP; }
	//setters
	void setposX_Cliente(short v) { posX = v; }
	void setposY_Cliente(short v) { posY = v; }
	void setdX_Cliente(short v) { dX = v; }
	void setdY_Cliente(short v) { dY = v; }
	void setisVIP(bool v) {isVIP = v; }



};