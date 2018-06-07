/*******************************************************
* Codigo desarrollado por Victor Chamale 5990-13-20413 *
*******************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct nodo{
    nodo* padre;
    nodo* izquierdo;
    nodo* derecho;
    int clave;
    string nombre;
    bool direccion;
    int balance;

};

nodo* crearNodo();
void pedirInfo(nodo* nuevo);


int main(){



return 0;
}



//Crear nuevo nodo
nodo* crearNodo(){
    nodo* nuevo = (nodo*)malloc(sizeof(struct nodo));
    nuevo->nombre = "vacio";
    nuevo->padre = nuevo->izquierdo = nuevo->derecho = NULL;
    return nuevo;
}


//Pide la informacion al usuario y la asigna al nodo creado recientemente.
void pedirInfo(nodo* nuevo){

	cout << "Ingrese la clave del estudiante: " << endl;
	cin >> nuevo->clave;
	cout << "Ingrese el nombre del estudiante: " << endl;
	cin >> nuevo->nombre;

}



