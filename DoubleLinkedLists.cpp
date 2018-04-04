#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

void reservation();
void showAvailable();

struct seat {
    string name;
    string lName;
    int seatNum;
    int destination;
    bool window;
    seat* prev;
    seat* next;
};

string seats[50];


int main (){

// Initializing seats array.
    for (int i = 0; i <50; i++){
        seats[i]="Disponible";
    }
seats[12]="Ocupado   ";
seats[31]="Ocupado   ";
seats[5]="Ocupado   ";
seats[46]="Ocupado   ";
    reservation();

return 0;
}


/* Determinar si aun hay asientos disponibles en la ventana y saber cuantos pasajeros bajaron*/


void reservation(){
    int asiento;

    cout << "Por favor ingrese el numero del asiento que desea reservar.\n" << endl;
    showAvailable();
    cin>>asiento;
    asiento = asiento-1;
    if(seats[asiento]=="Ocupado   ")
        cout << "esta ocupado" << endl;
    else
        cout << "esta disponible" << endl;

}




void showAvailable(){

    int i = 0;
    int iplus = 25;
for (int i = 0; i < 25; i++){

        cout.flush();
        if (i<9)
        cout << "0" << i+1 << " " << seats[i] << "     " << iplus+1 << " " << seats[iplus] << endl;
        else
        cout << i+1 << " " << seats[i] << "     " << iplus+1 << " " << seats[iplus] << endl;
        iplus++;

    }
}

