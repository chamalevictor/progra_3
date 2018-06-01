/*******************************************************
* Codigo desarrollado por Victor Chamale 5990-13-20413 *
*******************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int a;
struct nodo{

	nodo* anterior;
	int codigo;
	string nombre;
	int identificacion;
	int telefono;
	nodo* siguiente;
};
