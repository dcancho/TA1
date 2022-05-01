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

	Partida* partida = new Partida(hSize, vSize, n, x, t, 120000, 0);
	
	


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
