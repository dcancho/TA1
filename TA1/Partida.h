#pragma once
#include "Mesa.h"
#include "Mozo.h"
#include "Cliente.h"

class Partida
{
private:
	short sizeX;
	short sizeY;
	int duration;
	int timeElapsed;
	short nCliente;
	short xCliente;
	short tCliente;
	Mesa** mesas;
	Mozo** mozos;
	Cliente** clientes;

public:
	/// <summary>
	/// Constructor por defecto. NO USAR.
	/// </summary>
	Partida()
	{
		sizeX = 80;
		sizeY = 40;
		duration = 120000;
		timeElapsed = 0;
		nCliente = 3;
		xCliente = 8;
		tCliente = 30000;
		mesas = nullptr;
		mozos = nullptr;
		clientes = nullptr;
	}

	/// <summary>
	/// Constructor de objeto Partida.
	/// </summary>
	/// <param name="dimX">Tamanno horizontal de consola</param>
	/// <param name="dimY">Tamanno vertical de consola</param>
	/// <param name="n">Veces a invocar conjunto de clientes</param>
	/// <param name="x">Cantidad de clientes por invocacion</param>
	/// <param name="t">Tiempo entre invocaciones (en ms)</param>
	/// <param name="gameDuration">Duracion total de la partida (en ms)</param>
	/// <param name="gameTimeElapsed">Tiempo transcurrido (por defecto, 0)(en ms)</param>
	Partida(short dimX, short dimY, short n, short x, short t, int gameDuration, int gameTimeElapsed = 0)
	{
		sizeX = dimX;
		sizeY = dimY;
		nCliente = n;
		xCliente = x;
		tCliente = t;
		duration = gameDuration;
		timeElapsed = gameTimeElapsed;
		mesas = InitMesas();
		mozos = InitMozos();
	}

	~Partida()
	{
		TerminarPartida();
		delete[] mesas;
		delete[] mozos;
		delete[] clientes;
	}

	Mesa** InitMesas(short nMesas=4)
	{
		Mesa** mesas = new Mesa * [4];
		mesas[0] = new Mesa('A', 9, 9);
		mesas[1] = new Mesa('B', 63, 9);
		mesas[2] = new Mesa('C', 9, 29);
		mesas[3] = new Mesa('D', 63, 29);
		return mesas;
	}
	Mozo** InitMozos(short nMozos=6)
	{
		System::Random r;

		Mozo** mozos = new Mozo * [6];
		mozos[1] = new Mozo(r.Next(0, 81), r.Next(0, 41), 1, r.Next(0,2), r.Next(0,2), 0, 1);
	}
	void InvokeClientes()
	{

	}
	void InvokeClientesVIP()
	{

	}
	void TerminarPartida()
	{

	}
	Mesa** getMesas() { return mesas; }
	Mozo** getMozos() { return mozos; }
};