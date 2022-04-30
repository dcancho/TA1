#pragma once
#include"Entidad.h"

class Cliente : public Entidad {

protected:
	bool isVIP;
	char** caracteres;
public:
	//constructores
	Cliente() {}
	Cliente(short posX, short posY, short v, short dX, short dY, bool isVIP, char** carcateres) :Entidad(posX, posY, v, dX, dY) {
		this->isVIP = isVIP;
		caracteres = new char* [0];
		posX = 5 - rand() % (75 + 1 - 5);
		posY= 5 - rand() % (35 + 1 - 5);
		dY = 2;
	}
	//Destructor
	~Cliente() {}
	//getters
	short getposX_Cliente() { return posX; }
	short getposY_Cliente() { return posY; }
	short getdX_Cliente() { return dX; }
	short getdY_Cliente() { return dY; }
	short getisVIP() { return isVIP; }
	//setters
	void setposX_Cliente(short v) { posX = v; }
	void setposY_Cliente(short v) { posY = v; }
	void setdX_Cliente(short v) { dX = v; }
	void setdY_Cliente(short v) { dY = v; }
	void setisVIP(bool v) { isVIP = v; }
    // min - rand()%(maximo + 1-min)//
	//Metodos - borrar - mover - dibujar
	void Borrar() {
		Console::SetCursorPosition(posX, posY);
		cout << " ";
	}
	void Mover() {
		if (posY > 38 || posY < 1) {
			Borrar();
		}
		posY += dY;
	}
	void Dibuujar() {
		Console::SetCursorPosition(x, y); cout << "O";
	}


};