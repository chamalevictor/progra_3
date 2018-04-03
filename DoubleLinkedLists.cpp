t#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

void showAvailable();

struct seat {
    string name;
    string lName;
    int seat;
    string destination;
};

string seats[50];


int main (){

// Inicializando todos los asientos del bus como disponibles.
    for (int i = 1; i <= 25; i++){
        seats[i]="Disponible";
    }

    showAvailable();
// this is a test
return 0;
}


/*opciones para asiento: Nombre, apellido, numero de asiento y parada*/

/* Para saber que asientos estan ocupados se puede crear un array con la palabra "disponible" por defecto,
luego al momento de reservar un asiento, se cambia el texto a "ocupado" */



void showAvailable(){
for (int i = 1; i <= 25; i++){
        if (i<10)
        cout << "0" << i << " " << seats[i] << "     " << i+25 << " " << seats[i] << endl;
        else
        cout << i << " " << seats[i] << "     " << i+25 << " " << seats[i] << endl;
    }
}

