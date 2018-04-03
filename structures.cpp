#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

struct alumno{
    string nombre;
    string apellido;
    int clave;
};


int main(){

    alumno alumnos[3];

    for (int i = 0; i <3; i++){
        cout << "ingrese nombre: " << endl;
        cin>>alumnos[i].nombre;
        cout << "ingrese apellido: " << endl;
        cin>>alumnos[i].apellido;
        cout << "ingrese clave: " << endl;
        cin>>alumnos[i].clave;
        system("CLS");


    }

    for (int i = 0; i <3; i++){
     cout << "Alumno: " << endl;
     cout << alumnos[i].nombre+" "+alumnos[i].apellido<< endl;
     cout << "Clave: " << endl;
     cout << alumnos[i].clave << endl;

    }


return 0;
}



