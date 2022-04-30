#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class Silla {
private:
	bool isOccupied;
	short posX;
	short posY;
	char* ASCII;
public:
	Silla();
	~Silla();
	void PrintSilla();
	bool getIsOccupied();
	short getPosX();
	short getPosY();
	char* getAscii();
	void setIsOccupied(bool state);
	void setPosX(short posx);
	void setPosY(short posy);
};

Silla::Silla()
{

}

Silla::~Silla()
{
	delete[] ASCII;
}


void Silla::PrintSilla()
{
	
}

bool Silla::getIsOccupied()
{
	return isOccupied;
}

short Silla::getPosX()
{
	return posX;
}

short Silla::getPosY()
{
	return posY;
}

char* Silla::getAscii()
{
	return ASCII;
}

void Silla::setIsOccupied(bool state)
{
	isOccupied = state;
}

void Silla::setPosX(short posx)
{
	posX = posx;
}

void Silla::setPosY(short posy)
{
	posY = posy;
}