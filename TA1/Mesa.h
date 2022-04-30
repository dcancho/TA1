#pragma once
#include "Silla.h"

class Mesa {
private:
	char ID;
	Silla* sillas;
	short posX;
	short posY;
	char** ascii;
public:
	Mesa();
	~Mesa();
	void InitSillas();
	void PrintMesa();
};