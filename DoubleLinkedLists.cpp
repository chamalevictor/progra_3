#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct seat {
    string name;
    string lName;
    int seatNum;
    int destination;
    bool window;
    seat* prev;
    seat* next;
};

struct seat* start;

void reservation();
void showAvailable();
struct seat* createNode();


string seats[50];

int main (){

// Initializing seats array.
    for (int i = 0; i <50; i++){
        seats[i]="Disponible";
    }

    reservation();

return 0;
}

struct seat* createNode(){
    struct seat* newSeat = (struct seat*)malloc(sizeof(struct seat));
    newSeat->prev = NULL;
    newSeat->next = NULL;

    return newSeat;
}


void reservation(){

    int asiento;

    cout << "Por favor ingrese el numero del asiento que desea reservar.\n" << endl;
    showAvailable();
    cin>>asiento;
    asiento = asiento-1;
    if(asiento<0||asiento>49){
        cout << "el asiento seleccionado no es valido" << endl;
    }
    if(seats[asiento]=="Ocupado   ")
        cout << "esta ocupado" << endl;
    else{
        cout << "esta disponible" << endl;
        struct seat* newSeat = createNode();
        if (start == NULL){
            start = newSeat;
        }
        cout << "Ingrese el nombre del pasajero " << endl;
        cin>>newSeat->name;
        cout << "Ingrese el apellido del pasajero " << endl;
        cin>>newSeat->lName;

        start->prev = newSeat;
        newSeat->next = start;
        start = newSeat;

    }

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

