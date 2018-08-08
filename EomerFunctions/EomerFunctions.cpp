// EomerFunctions.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/*int vida_de(int* arreglo, int n)
{
	return arreglo[n * 2];
}

// disminuye la vida del personaje por la cantidad solicitada (vida de personaje - cantidad)
int quitar_vida_de(int* arreglo, int n, int cantidad) {

	return arreglo[n * 2] -= cantidad;

}

// chequear murio? devuelve true si la vida del personaje es inferior o igual a 0
bool murio(int * arreglo, int n) {

	if (arreglo[n * 2] <= 0) { return true; }
	else { return false; }

}
*/
// pelear : hace que el personaje num_de_personaje_a del arreglo personajes_a se pelee hasta morir con el num_de_personaje_b del arreglo personajes _b
// devuelve true si el personaje_a gano y false si el personaje_b gano
bool pelear(int* personajes_a, int* personajes_b, int num_personaje_a, int num_personaje_b) {

	while (personajes_a[num_personaje_a * 2] > 0 && personajes_b[num_personaje_b * 2] > 0) 
	{
		personajes_a[num_personaje_a * 2] -= personajes_b[(num_personaje_b * 2) + 1];
		personajes_b[num_personaje_b * 2] -= personajes_a[(num_personaje_a * 2) + 1];
	}
	if (personajes_b[num_personaje_b * 2] < 1) {
		return true;
	}
	if (personajes_a[num_personaje_a * 2] < 1 || personajes_a[num_personaje_a * 2] < 1 && personajes_b[num_personaje_b * 2] < 1) {
		return false;
	}
	

}

// brawl : todos los personajes pelean de manera contigua (p0 vs c0) hasta que uno de los dos sale victorioso o ambos mueran.
// si alguno sale victorioso, pelea contra el siguiente oponente del grupo,
// si ambos mueren, los siguientes de cada grupo peleean.
// la peleea continua hasta que ambos grupos estan todos muertos o hay un ganador.
// devuelve 1 si los personajes_a ganaron, devuelve 2 si los personajes b ganaron, devuelve 0 si ninguno gano;
int brawl(int* personajes_a, int* personajes_b, int cantidad_de_personajes_a, int cantidad_de_personajes_b) {

	
	while (cantidad_de_personajes_a < 2 || cantidad_de_personajes_b < 2) 
	{
		while (personajes_a[cantidad_de_personajes_a * 2] > 0 && personajes_a[cantidad_de_personajes_a * 2] > 0)
		{
			personajes_a[cantidad_de_personajes_a * 2] -= personajes_b[(cantidad_de_personajes_b * 2) + 1];
			personajes_b[cantidad_de_personajes_b * 2] -= personajes_a[(cantidad_de_personajes_a * 2) + 1];
		}
		if (personajes_a[cantidad_de_personajes_a * 2] < 1) {
			cantidad_de_personajes_a ++;
		}
		if (personajes_b[cantidad_de_personajes_b * 2] < 1) {
			cantidad_de_personajes_b ++;
		}
	}
	if (cantidad_de_personajes_a == 3 && cantidad_de_personajes_b == 3) 
	{ 
		return 0;
		cout << "ninguno ganó" << endl;
	
	}
	if (cantidad_de_personajes_a == 3 && cantidad_de_personajes_b < 3)
	{
		return 2;
		cout << "ganaron los personajes B" << endl;
	}
	if (cantidad_de_personajes_b == 3 && cantidad_de_personajes_a < 3)
	{
		return 1;
		cout << "ganaron los personajes A" << endl;
	}


}

int* crear_personajes() {

	int personajes[6];
	int vida;
	int ataque = (rand() % 100);


	for (int i = 0; i < 6; i += 2) {

		vida = (rand() % 10);
		ataque = (rand() % 5);

		personajes[i] = vida;
		personajes[i + 1] = ataque;
	}

	return &personajes[0];

}



int main() {

	int* heroes = crear_personajes();
	// int vida = personajes[0];
	int* enemigos = crear_personajes();


	pelear(heroes, enemigos, 0, 0);
	brawl(heroes, enemigos, 0, 0);

	cout << brawl << endl;




	//int a = vida_de(heroes, 0);
	//int b = heroes[0];

	//cout << a << endl;
	//cout << b << endl;

	//while (personajes[0] > 0 && enemigos[0] > 0) 
	//{
	//	personajes[0] -= enemigos[1];
	//	enemigos[0] -= personajes[1];		
	//}

	//if (personajes[0] <= 0 && enemigos[0] > 1) {
	//
	//	cout << "gano el enemigo" << endl;

	//}
	//if (enemigos[0] <= 0 && enemigos[0] > 1) {

	//	cout << "gano el personaje" << endl;

	//}
	//if (enemigos[0] <= 0 && personajes[0] <= 0) 
	//{
	//	cout << "se murieron los 2";
	//}

	// cout << *personajes << endl;

	// *(puntero_pj + 1) = 0;
	// puntero_pj[1] = 0;

	// cout << *(puntero_pj + 1) << endl;

	// matar(personajes, 0);

	// int a[10];
	// int* b = a;

	getchar();
	return 0;
}

