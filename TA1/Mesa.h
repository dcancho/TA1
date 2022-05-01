#pragma once
#include "Silla.h"

using namespace System;

class Mesa {
private:
	char ID;
	Silla** sillas;
	short posX;
	short posY;
	char ASCII[2][7] = { "______","[____]" };
public:
	Mesa();
	~Mesa();
	Mesa(char id, short x, short y)
	{
		ID = id;
		posX = x;
		posY = y;
		sillas = InitSillas();
	}
	Silla** InitSillas(short nSillas = 4)
	{
		Silla** sillas = new Silla*[4];
		sillas[0] = new Silla(posX, posY + 1);
		sillas[1] = new Silla(posX + 5, posY + 1);
		sillas[2] = new Silla(posX, posY + 2);
		sillas[3] = new Silla(posX + 5, posY + 2);
		return sillas;
	}
	void PrintMesa()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				Console::SetCursorPosition(9+i,9+j);
				cout << ASCII[i][j];
			}
		}
		
	}
};