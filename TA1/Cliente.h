#pragma once
#include"Entidad.h"

class Cliente : public Entidad {

protected:
	bool isVIP;
	char** caracteres;
public:
	//constructores
	Cliente() {}
	Cliente(short posX, short posY, short v, short dX, short dY, bool isVIP) :Entidad(posX, posY, v, dX, dY) {
		System::Random r;
		this->isVIP = isVIP;
		posX = r.Next(0,80);
		posY= r.Next(0,40);
		dY = 2;
		dX = 2;
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
	void BorrarCliente() {
		Console::SetCursorPosition(posX, posY);
		cout << " ";
	}
	void MoverCliente() {
		if (posY > 38 || posY < 1) {
			BorrarCliente();
		}
		posY += dY;
	}
	void DibujarCliente() {
		Console::ForegroundColor = ConsoleColor::White;
		Console::SetCursorPosition(posX, posY); cout << "O";
	}
	void ClientesVIP_Draw() {
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(posX, posY); cout << "O";
		Console::ForegroundColor = ConsoleColor::White;
	}
	void Mover_ClienteVIP() {
		if (posX > 78 || posX < 1) {
			BorrarCliente();
		}
		posX+= dX;
	}

};