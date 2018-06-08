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


// Declaracion de funciones.
void menu();
struct nodo* insertar(nodo* raiz);
//struct nodo* proceso(nodo* padre, nodo* nuevo);
void pedirInfo(nodo* nuevo);
struct nodo* crearNodo();
void title();
void opciones();



// Variables Globales
struct nodo* root = NULL;

nodo* nodo1 = crearNodo();

nodo* nodo2 = crearNodo();


/**** Funcion Principal ****/


int main(){

return 0;
}

/**** Finaliza funcion principal ****/



// Funcion recursiva para insertar un nodo en el arbol.
struct nodo* insertar(nodo* raiz){

    // Se crea y llena un nuevo nodo.
    nodo* nuevo = crearNodo();
    pedirInfo(nuevo);
    nodo* padre = raiz;

    nodo* proceso(nodo* padre, nodo* nuevo){
        if (padre == NULL){
            padre =nuevo;
        }
        else if(nuevo->clave<=padre->clave){
            proceso(padre->izquierdo);
        }
        else{
            proceso(padre->derecho);
        }
        return padre;
    }
        padre=proceso(padre, nuevo);
    return padre;
}



// Pedir informacion.
void pedirInfo(nodo* nuevo){
    cout << "Por favor ingrese la clave del alumno: " << endl;
    cin >> nuevo->clave;
    cout << "Ingrese el nombre del alumno: " << endl;
    cin >> nuevo->nombre;

}


// Crea un nuevo nodo en memoria usando Malloc.
struct nodo* crearNodo(){
    nodo* nuevo = (nodo*)malloc(sizeof(struct nodo));
    nuevo->izquierdo = nuevo->derecho = NULL;
    nuevo-> nombre = "Vacio";

    return nuevo;
}



