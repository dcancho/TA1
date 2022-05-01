#pragma once
#include"Entidad.h"

class Cliente : public Entidad {

protected:
	bool isVIP;
	char** caracteres;
public:
	//constructores
	Cliente() {}
	Cliente(short x, short y, short v, short desX, short desY, bool isVIP) : Entidad(x, y, v, desX, desY) {
		System::Random r;
		this->isVIP = isVIP;
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
	bool MoverCliente() 
	{
		posX += dX;
		posY += dY;
		if (posX > 79 || posY > 39)
		{
			posX = 79;
			posY = 39;
			BorrarCliente();
			return true;
		}
		return false;
	}

	void DibujarCliente() {
		if (isVIP)
		{
			Console::ForegroundColor = ConsoleColor::Red;
		}
		Console::SetCursorPosition(posX, posY);
		cout << "O";
		Console::ForegroundColor = ConsoleColor::White;
	}
};