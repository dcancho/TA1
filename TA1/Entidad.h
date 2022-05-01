#pragma once
#include <iostream>
using namespace std;
using namespace System;

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
	void MoverEntidad()
	{
		posX = posX + int(dX * v);
		posY = posY + int(dY * v);

		if (posX == -1 || posX == 80)
		{
			posX = posX - int(dX * v);
			dX = dX * -1;
		}
		else if (posY == -1 || posY == 40)
		{
			posY = posY - int(dY * v);
			dY = dY * -1;
		}
	}
	void setX(short x)
	{
		posX = x;
	}
	void setY(short y)
	{
		posY = y;
	}
};

