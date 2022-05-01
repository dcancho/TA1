#pragma once
#include"Entidad.h"

class Mozo : public Entidad {
protected:
	short score;
	char caracteres;
public:
	//constructores
	Mozo(){}
	Mozo(short posX, short posY, short v, short dX, short dY, short score, char caracter) :Entidad(posX, posY, v, dX, dY) {
		this->score = score;
		caracteres = caracter;
		posX= 5 - rand() % (75 + 1 - 5);
		posY= 5 - rand() % (35 + 1 - 5);
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
	//Metodos - borrar - mover - dibujar
	void Borrar() {
		Console::SetCursorPosition(posX, posY);
		cout << "   ";
	}
	void Dibujar() {
		int opc;
		opc = 1 - rand() % (6 + 1 - 1);
		switch (opc)
		{
		case 1: Console::ForegroundColor = ConsoleColor::Red;
			;break;
		case 2:Console::ForegroundColor = ConsoleColor::Yellow;
			;break;
		case 3:Console::ForegroundColor = ConsoleColor::Green;
			;break;
		case 4:Console::ForegroundColor = ConsoleColor::DarkBlue;
			;break;
		case 5:Console::ForegroundColor = ConsoleColor::Gray;
			;break;
		case 6:Console::ForegroundColor = ConsoleColor::DarkCyan;
			;break;

		}
		Console::SetCursorPosition(posX, posY); cout << "/_\";
		Console::ForegroundColor = ConsoleColor::White;
	}


};