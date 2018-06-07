/*******************************
* Victor Chamale 5990-13-20413 *
********************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

// Estructura de los nodos.
struct Nodo
{
    int clave;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
    int altura;
    string nombre;
};

// Declaracion de funciones a utilizar en el programa.
int altura();
int maximo(int a, int b);
struct Nodo* crearNodo(int clave);
struct Nodo* girarDerecha(struct Nodo* y);
struct Nodo* girarIzquierda(struct Nodo* x);
int Balance(struct Nodo* N);
struct Nodo* insertar(struct Nodo* nodo, int clave);
void mostrar(struct Nodo* raiz);
void titulo();
void menu();
void opciones();
void preInsert();

// Variable global.
struct Nodo* raiz = NULL;


/* Funcion principal del programa. */

int main()
{

    menu();

  return 0;
}


// Obtener la altura/nivel de un nodo.
int altura(struct Nodo *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}

// Obtener el valor mas grande entre dos enteros.
int maximo(int a, int b)
{
//(condicion)? Si se cumple : No Se cumple.
    return (a > b)? a : b;
}

// Funcion que crea un nuevo nodo
struct Nodo* crearNodo(int clave)
{
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->clave = clave;
    //nodo->nombre = "vacio";
    nodo->izquierdo   = NULL;
    nodo->derecho  = NULL;
    nodo->altura = 1;
  //  nodo->nombre = nombre;
    return(nodo);
}

// Rotar hacia la derecha.
struct Nodo* girarDerecha(struct Nodo* y)
{
    struct Nodo* x = y->izquierdo;
    struct Nodo* T2 = x->derecho;

    // Realizar la rotacion.
    x->derecho = y;
    y->izquierdo = T2;

    // Actualizando la altura en los nodos.
    y->altura = maximo(altura(y->izquierdo), altura(y->derecho))+1;
    x->altura = maximo(altura(x->izquierdo), altura(x->derecho))+1;

    // Regresando la nueva raiz.
    return x;
}

// Rotar hacia la izquierda.
struct Nodo* girarIzquierda(struct Nodo* x)
{
    struct Nodo* y = x->derecho;
    struct Nodo* T2 = y->izquierdo;

    // Realizar la rotacion.
    y->izquierdo = x;
    x->derecho = T2;

    //  Actualizando las alturas.
    x->altura = maximo(altura(x->izquierdo), altura(x->derecho))+1;
    y->altura = maximo(altura(y->izquierdo), altura(y->derecho))+1;

    // Regresando la nueva raiz.
    return y;
}

// Obtener el factor de balance de un nodo.
int Balance(struct Nodo* N)
{
    if (N == NULL)
        return 0;
    return altura(N->izquierdo) - altura(N->derecho);
}

// Funcion recursiva para insertar un nuevo nodo.
struct Nodo* insertar(struct Nodo* nodo, int clave)
{

    /* 1.  Insertar un nodo normalmente en un Arbol de Busqueda Binario */
    if (nodo == NULL)
        return(crearNodo(clave));


    if (clave < nodo->clave)
        nodo->izquierdo  = insertar(nodo->izquierdo, clave);
    else if (clave > nodo->clave)
        nodo->derecho = insertar(nodo->derecho, clave);
    else // Claves iguales seran descartadas.

     return nodo;

    /* 2. Actualizando la altura. */
    nodo->altura = 1 + maximo(altura(nodo->izquierdo), altura(nodo->derecho));

    /* 3. Verificando si el nodo a salido de balance. */
    int balance = Balance(nodo);

    // Si el nodo ha salido de balance, hay 4 casos:

    // Caso Izquierda, Izquierda.
    if (balance > 1 && clave < nodo->izquierdo->clave)
        return girarDerecha(nodo);

    // Caso Derecha, Derecha.
    if (balance < -1 && clave > nodo->derecho->clave)
        return girarIzquierda(nodo);

    // Caso Izquierda, Derecha.
    if (balance > 1 && clave > nodo->izquierdo->clave)
    {
        nodo->izquierdo =  girarIzquierda(nodo->izquierdo);
        return girarDerecha(nodo);
    }

    // Caso Derecha, Izquierda.
    if (balance < -1 && clave < nodo->derecho->clave)
    {
        nodo->derecho = girarDerecha(nodo->derecho);
        return girarIzquierda(nodo);
    }

    /* Regresando el puntero nodo (sin cambio) */
    return nodo;
 }


//Imprimir en pantalla los valores guardados.
void mostrar(struct Nodo* raiz)
{

    if(raiz != NULL)
    {
        cout << raiz->clave << endl;;
        mostrar(raiz->izquierdo);
        mostrar(raiz->derecho);
    }

}

void titulo(){
    system("CLS");
    cout << "********************************" << endl;
    cout << "*          Arbol AVL           *" << endl;
    cout << "********************************" << endl;
    cout << "\n\n" << endl;
}

void menu(){
    int opcion;
    titulo();
    cout << "\n\nPor favor, ingrese una opcion y luego presione 'ENTER'.\n\n" << endl;
    cout << "1. Registrar un Alumno. " << endl;
    cout << "2. Ver Almunos registrados. " << endl;
    cout << "3. Eliminar un Alumno. " << endl;
    cout << "   Presione cualquier otra tecla para salir. " << endl;
    cin >> opcion;

    switch (opcion){
    case 1:
        preInsert();
        cout << "\nEl Alumno se ha registrado con exito. \n" << endl;
        break;
    case 2:
        titulo();
        if(raiz == NULL)
        cout << "ADVERTENCIA! Este Arbol se encuentra vacio. \n\n" << endl;
        else{
            cout << "\nLos Alumnos registrados son: " << endl;
            mostrar(raiz);
        opciones();
        }
        break;
    case 3:
        titulo();
        cout << "Lo sentimos, esta opcion no esta disponible en este momento. \n\n" << endl;
        opciones();
        break;
    default:
        titulo();
        cout << "Saliendo del programa..." << endl;
        exit(0);
    }

}

void opciones(){

int opcion;
        cout << "\n\nPor favor, ingrese una opcion y luego presione 'ENTER'. \n" << endl;
        cout << "1. Ingresar un Alumno. " << endl;
        cout << "2. Volver al Menu principal. " << endl;
        cout << "   Presione cualquier otra tecla para salir." << endl;
        cin >> opcion;
        if(opcion==1)
            preInsert();
        else if(opcion==2)
            menu();
        else{
        titulo();
        cout << "Saliendo del programa..." << endl;
        exit(0);
        }

    }

void preInsert(){

    int clave;
    string nombre;

    titulo();
    cout << "\nPor favor, ingrese la clave para el nuevo Alumno. " << endl;
    cin >> clave;
    raiz = insertar(raiz, clave);
    cout << "El Alumno se ha registrado con exito." << endl;
    opciones();
}

/* Ingeniero:
como puede observar, el codigo sigue en fase de desarrollo.
Por el momento cumple con la funcion de estructurar el arbol automaticamente,
sin embargo, estoy trabajando en la parte del ingreso de los nombres ya que
da problema al momento de inicializar el dato String y tambien sigo trabajando
la parte de eliminacion y la representacion grafica. */


⊂_ヽ
　 ＼＼ ＿
　　 ＼(　•_•) F
　　　 <　⌒ヽ A
　　　/ 　 へ＼ B
　　 /　　/　＼＼ U
　　 ﾚ　ノ　　 ヽ_つ L
　　/　/ O
　 /　/    U
　(　(ヽ S
　|　|、＼.
　| 丿 ＼ ⌒)A
　| |　　) /
 ノ )　　Lﾉ__
(／___﻿
