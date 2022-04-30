#pragma once
#include <iostream>
using namespace std;

class Entidad {
protected:
	short posX;
	short posY;
	short v;
	short dX;
	short dY;
public:
	Entidad() {}
	Entidad(short posX, short posY, short v, short dX, short dY) {
		this->posX = posX;
		this->posY = posY;
		this->v = v;
		this->dX = dX;
		this->dY = dY;
	}
	~Entidad() {}

};

