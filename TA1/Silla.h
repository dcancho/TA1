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
	char ASCII[2];
public:
	Silla()
	{
		isOccupied = false;
		posX = 0;
		posY = 0;
		ASCII[0] = '[';
		ASCII[1] = ']';
	}
	Silla(short x, short y)
	{
		isOccupied = false;
		posX = x;
		posY = y;
		ASCII[0] = '[';
		ASCII[1] = ']';
	}

	~Silla()
	{
		delete[] ASCII;
	}


	void PrintSilla()
	{
		for (int i = 0; i < 2; i++)
		{
			Console::SetCursorPosition(posX+i, posY);
			cout << ASCII[i];
		}
	}

	bool getIsOccupied()
	{
		return isOccupied;
	}

	short getPosX()
	{
		return posX;
	}

	short getPosY()
	{
		return posY;
	}

	char* getAscii()
	{
		return ASCII;
	}

	void setIsOccupied(bool state)
	{
		isOccupied = state;
	}

	void setPosX(short posx)
	{
		posX = posx;
	}

	void setPosY(short posy)
	{
		posY = posy;
	}
};