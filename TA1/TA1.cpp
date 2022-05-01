#include "pch.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <tuple>
#include <ctime>
#include "Partida.h"

using namespace std;

void splashScreen()
{
	printf("Hola. Introduce valor de n, x y t (en ms):\n");
}


int main()
{
    srand(time(NULL));
	short hSize = 80;
	short vSize = 40;
	short n, x;
	int t;
    Console::SetWindowSize(hSize, vSize);
	splashScreen();

	do {
		ignore = scanf("%hd %hd %d", &n, &x, &t);
	} while (!(t > 0 || t <= 120000 || (t*n)<=120000));
	system("cls");


	Partida* partida = new Partida(hSize, vSize, n, x, t, 120000, 0);
	int timeElapsed = 0;
	short nRemainingClientes = n;
	short nRemainingClientesVIP = 3;
	short cantClientes = 0;
	do
	{
		Console::CursorVisible = false;
		if (timeElapsed % t == 0 && nRemainingClientes > 0)
		{
			partida->InvokeClientes();
			nRemainingClientes--;
		}
		if (timeElapsed % 30000 == 0 && nRemainingClientesVIP > 0)
		{
			partida->InvokeClientesVIP();
			nRemainingClientesVIP--;
		}
		for (int i = 0; i < 4; i++)
		{
			partida->getMesas()[i]->PrintMesa();
		}
		for (int i = 0; i < 6; i++)
		{
			partida->getMozos()[i]->Borrar();
			partida->getMozos()[i]->MoverEntidad();
			partida->getMozos()[i]->Dibujar();
		}

		cantClientes = partida->getClientesSize();

		partida->moverClientes();

		/*for (short i = 0; i < cantClientes; i++)
		{
			partida->getClientes()[i].BorrarCliente();
			partida->getClientes()[i].MoverCliente();
			partida->getClientes()[i].DibujarCliente();
		}*/


		_sleep(250);
		timeElapsed += 250;
		partida->setTimeElapsed(timeElapsed);
	} while (timeElapsed < 120000);
	partida->~Partida();


	for (int i = 0; i < 4; i++)
	{
		partida->getMesas()[0]->PrintMesa();
		partida->getMesas()[1]->PrintMesa();
		partida->getMesas()[2]->PrintMesa();
		partida->getMesas()[3]->PrintMesa();
	}
	_getch();
	return 0;
}
