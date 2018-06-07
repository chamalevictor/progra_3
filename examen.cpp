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

nodo* crearNodo();
void pedirInfo(nodo* nuevo);
void insertar();
void verLista();
void verListaReversa();
void title();
void menu();
void opcionInsertar();

nodo* primerNodo;
nodo* ptrInicio;
nodo* ptrFinal;
nodo* ptrRecorrido;

int main(){

	primerNodo = NULL;
	ptrInicio = NULL;
	ptrFinal = NULL;
	ptrRecorrido = NULL;
	/*	insertar();
	insertar();
	cout << "\n\n\n" << endl;
	verLista();
	cout << "\n\n\n" << endl;
	verListaReversa();
	cout << "\n\n\n" << endl;*/
	menu();
	return 0;
}


//Crea un nuevo nodo en memoria.
nodo* crearNodo(){
	nodo* nuevo=(nodo*)malloc(sizeof(struct nodo));
	nuevo->nombre = "vacio";
	nuevo->anterior = nuevo->siguiente = NULL;
	return nuevo;
}

//Pide la informacion al usuario.
void pedirInfo(nodo* nuevo){

	cout << "Ingrese el codigo del estudiante: " << endl;
	cin >> nuevo->codigo;
	cout << "Ingrese el primer nombre del estudiante: " << endl;
	cin >> nuevo->nombre;
	cout << "Ingrese la identificaion sin guiones (solo numeros): " << endl;
	cin >> nuevo->identificacion;
	cout << "Ingrese el telefono sin guiones del estudiante: " << endl;
	cin >> nuevo->telefono;

}

void insertar(){
	system("clear");
	nodo* nuevo = crearNodo();
	pedirInfo(nuevo);

	if(primerNodo==NULL){
		primerNodo=nuevo;
		ptrInicio=nuevo;
		ptrFinal=nuevo;
	cout << "El primer alumno ha sido guardado con exito. \n\n" << endl;
		opcionInsertar();

	}else if(nuevo->codigo < primerNodo->codigo){
		nuevo->siguiente = ptrInicio;
		ptrInicio->anterior = nuevo;
		ptrInicio = nuevo;
		cout << "El alumno ha sido registrado con exito al inicio de la lista. \n\n" << endl;
		opcionInsertar();
	}else{
		nuevo->anterior = ptrFinal;
		ptrFinal->siguiente = nuevo;
		ptrFinal= nuevo;
		cout << "El alumno ha sido registrado con exito al final de la lista. \n\n" << endl;
		opcionInsertar();
	}
}

void verLista(){
	system("clear");
	ptrRecorrido = ptrInicio;
	cout << "Los alumnos registrados hasta el momento son: " << endl;
	while(ptrRecorrido->siguiente!=NULL){
		cout << "Codigo: " << ptrRecorrido->codigo << endl;
		cout << "Nombre: " << ptrRecorrido->nombre << endl;
		cout << "Identificacion: " << ptrRecorrido->identificacion << endl;
		cout << "Telefono: " << ptrRecorrido->telefono << endl;
		cout << "\n\n\n " << endl;
		ptrRecorrido = ptrRecorrido->siguiente;
	}
	    cout << "Codigo: " << ptrRecorrido->codigo << endl;
		cout << "Nombre: " << ptrRecorrido->nombre << endl;
		cout << "Identificacion: " << ptrRecorrido->identificacion << endl;
		cout << "Telefono: " << ptrRecorrido->telefono << endl;
		cout << "\n\n\n " << endl;
}

void verListaReversa(){
	system("clear");
	ptrRecorrido = ptrFinal;
	cout << "Los alumnos registrados hasta el momento son: " << endl;
	while(ptrRecorrido->anterior!=NULL){
		cout << "Codigo: " << ptrRecorrido->codigo << endl;
		cout << "Nombre: " << ptrRecorrido->nombre << endl;
		cout << "Identificacion: " << ptrRecorrido->identificacion << endl;
		cout << "Telefono: " << ptrRecorrido->telefono << endl;
		ptrRecorrido = ptrRecorrido->anterior;
		cout << "\n\n\n " << endl;
	}
	    cout << "Codigo: " << ptrRecorrido->codigo << endl;
		cout << "Nombre: " << ptrRecorrido->nombre << endl;
		cout << "Identificacion: " << ptrRecorrido->identificacion << endl;
		cout << "Telefono: " << ptrRecorrido->telefono << endl;
		cout << "\n\n\n " << endl;
}

void title(){
	system("clear");
	cout << "\n***** Registro De Alumnos *****" << endl;
}

void menu(){
	int opcion = 0;
	int a = 0;

	title();
	cout << "Ingrese una opcion y luego presione ENTER. \n " << endl;
	cout << "1. Ingresar un estudiante. " << endl;
	cout << "2. Ver lista de estudiantes de inicio a final. " << endl;
	cout << "3. Ver lista de estudiantes de final a inicio. " << endl;
	cout << "   Presione cualquier otra tecla para salir. " << endl;
	cin >> opcion;

	switch(opcion){
		case 1:
			insertar();
			break;
		case 2:
			if(primerNodo==NULL){
				cout << "La lista se encuentra vacia, por favor registre un alumno. " << endl;
				cout << "1. registrar un alumno. " << endl;
				cout << "   Presione cualquier tecla para salir. " << endl;
				cin >> a;
				if (a==1)
					insertar();
				else
					exit(0);
			}else{
				verLista();
			}
			break;
		case 3:
			if(primerNodo==NULL){
				cout << "La lista se encuentra vacia, por favor registre un alumno. " << endl;
				cout << "1. registrar un alumno. " << endl;
				cout << "   Presione cualquier tecla para salir. " << endl;
				cin >> a;
				if (a==1)
					insertar();
				else
					exit(0);
			}else{
				verListaReversa();
			}
			break;

		default:
			exit(0);
	}
	}

void opcionInsertar(){

	int opcion = 0;
	cout << "1. Registrar otro Alumno. " << endl;
	cout << "2. Volver al menu. " << endl;
	cout << "   Presione cualquier otra tecla para salir. " << endl;
	cin >> opcion;
		if(opcion==1)
			insertar();
		else if(opcion==2)
			menu();
		else
			exit(0);
}
