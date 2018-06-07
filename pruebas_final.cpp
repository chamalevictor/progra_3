#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;

// Estructura de los nodos.
struct nodo{

    int clave;
    string nombre;
    nodo* izquierdo;
    nodo* derecho;

};


// Declaracion de funciones y variables globales.



struct nodo* insertar(nodo* nuevo);
struct nodo* pedirInfo(nodo* nuevo);
struct nodo* crearNodo();
struct nodo* root = NULL;




/**** Funcion Principal ****/


int main(){

insertar(root);

cout << root->nombre;

return 0;

}

/**** Finaliza funcion principal ****/


// Funcion recursiva para insertar un nuevo nodo al arbol.
struct nodo* insertar(nodo* nuevo){
    if (nuevo==NULL)
        nuevo = pedirInfo(crearNodo());
    return nuevo;

}


// Asigna la informacion deseada al nodo nuevo.
struct nodo* pedirInfo(nodo* nuevo){
    cout << "Por favor ingrese la clave del estudiante: " << endl;
    cin >> nuevo->clave;
    cout << "Por favor ingrese el nombre del estudiante: " << endl;
    cin >> nuevo->nombre;

    return nuevo;
}



// Crea un nuevo nodo en memoria usando Malloc.
struct nodo* crearNodo(){
    nodo* nuevo = (nodo*)malloc(sizeof(struct nodo));
    nuevo->izquierdo = nuevo->derecho = NULL;
    nuevo-> nombre = "Vacio";

    return nuevo;
}


