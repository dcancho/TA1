#pragma once
#include "Mesa.h"
#include "Mozo.h"
#include "Cliente.h"
#include <vector>

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
	vector<Cliente>clientes;

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
		mozos[0] = new Mozo(short(r.Next(0, 79)), short(r.Next(0, 39)), 1, short(r.Next(0, 2) - 1), short(r.Next(0, 2) - 1), 0, 1);
		mozos[1] = new Mozo(short(r.Next(0, 79)), short(r.Next(0, 39)), 1, short(r.Next(0, 2) - 1), short(r.Next(0, 2) - 1), 0, 2);
		mozos[2] = new Mozo(short(r.Next(0, 79)), short(r.Next(0, 39)), 1, short(r.Next(0, 2) - 1), short(r.Next(0, 2) - 1), 0, 3);
		mozos[3] = new Mozo(short(r.Next(0, 79)), short(r.Next(0, 39)), 1, short(r.Next(0, 2) - 1), short(r.Next(0, 2) - 1), 0, 4);
		mozos[4] = new Mozo(short(r.Next(0, 79)), short(r.Next(0, 39)), 1, short(r.Next(0, 2) - 1), short(r.Next(0, 2) - 1), 0, 5);
		mozos[5] = new Mozo(short(r.Next(0, 79)), short(r.Next(0, 39)), 1, short(r.Next(0, 2) - 1), short(r.Next(0, 2) - 1), 0, 6);
		return mozos;
	}
	void InvokeClientes()
	{
		System::Random r;
		for (int i = 0; i < xCliente; i++)
		{
			clientes.push_back(Cliente(short(r.Next(0, 80)), 0, 1, 0, 1, false));
		}
	}
	void InvokeClientesVIP()
	{
		System::Random r;
		for (int i = 0; i < 6; i++)
		{
			clientes.push_back(Cliente(0, (short(r.Next(0, 40))), 1, 1, 0, true));
		}
	}
	void TerminarPartida()
	{
		short position = 0;
		short maxScore = 0;
		for (int i = 0; i < 6; i++)
		{
			if (mozos[i]->getScore() > maxScore)
			{
				maxScore = mozos[i]->getScore();
				position = i;
			}
		}
		system("cls");
		printf("El mozo %hd es el ganador  con %hd puntos y es el nuevo duenno del restaurante!!!", &position, &maxScore);
	}
	Mesa** getMesas() { return mesas; }
	Mozo** getMozos() { return mozos; }
	int getTimeElapsed()
	{
		return timeElapsed;
	}
	short getClientesSize()
	{
		return clientes.size();
	}

	vector<Cliente> getClientes()
	{
		return clientes;
	}

	void moverClientes()
	{
		bool deleteAll = false;
		for (int i = 0; i < clientes.size(); i++)
		{
			clientes[i].BorrarCliente();
			deleteAll = clientes[i].MoverCliente();
			if (!deleteAll)
			{
				clientes[i].DibujarCliente();
			}
		}
	}

	void setTimeElapsed(int timeelapsed)
	{
		timeElapsed = timeelapsed;
	}

	};