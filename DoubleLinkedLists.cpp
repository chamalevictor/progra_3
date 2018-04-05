#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>


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

struct seat* ptrHead;
struct seat* ptrTail;
struct seat* ptrTemp;

void title();
void menu();
void fillSeats();
void reservation();
void showAvailable();
void showDestinations();
/*struct seat createNode();*/
seat createSeat();


string seats[50];








int main (){

ptrHead = NULL;
ptrTail = NULL;
ptrTemp = NULL;

    fillSeats();
    cout << "\n ADVERTENCIA! " << endl;
    cout << " Por favor, maximizar la ventana antes de continuar y luego presione ENTER." << endl;
    getch();

    //menu();
    reservation();
    system("cls");
    cout << "ya corrio una vez" << endl;
    reservation();
    system("cls");
    cout << "ya corrio dos veces" << endl;

    ptrTemp =



return 0;
}






struct seat* createNode(){
    struct seat* newNode = (struct seat*)malloc(sizeof(struct seat));
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void reservation(){

    int asiento;
    title();
    cout << "\nPor favor ingrese el numero del asiento que desea reservar." << endl;
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
        struct seat* newNode = createNode();

        if (ptrHead == NULL){

            cout << "Ingrese el nombre del pasajero" << endl;
            cin >> newNode->name;
            ptrHead = newNode;
            ptrTail = newNode;
            cout << "El nombre ingresado es: " << ptrTail->name << endl;

        }else{
        cout << "Ingrese el nombre del pasajero fuera if" << endl;
        cin >> newNode->name;

        ptrTail->next = newNode;
        newNode->prev = ptrTail;
        cout << "El nombre ingresado es: " << ptrTail->name << endl;
        ptrTail = newNode;


        }


    }

}


void showAvailable(){

    int i = 0;
    int iplus = 25;

    cout << "Los asientos con numero par, tienen ventana.\n" << endl;
for (int i = 0; i < 25; i++){

        cout.flush();
        if (i<9)
        cout << "0" << i+1 << " " << seats[i] << "     " << iplus+1 << " " << seats[iplus] << endl;
        else
        cout << i+1 << " " << seats[i] << "     " << iplus+1 << " " << seats[iplus] << endl;
        iplus++;

    }
}

void fillSeats(){
        for (int i = 0; i <50; i++){
        seats[i]="Disponible";
    }
}

seat createSeat(){
    seat nuevo;
    nuevo.next=NULL;
    return nuevo;

}

void title(){
    system("cls");
    cout << "*************************" << endl;
    cout << "**    BUSES LITEGUA    **" << endl;
    cout << "*************************" << endl;
}

void menu(){
    int choice = 0;

    title();
    cout << "\n\nPor favor, ingerese una opcion y luego presione ENTER.\n" << endl;
    cout << "1. Hacer una reservacion." << endl;
    cout << "2. Cancelar una reservacion." << endl;
    cout << "3. Ver asientos disponibles." << endl;
    cout << "4. Ver destinos." << endl;
    cout << "   Presione cualquier otra tecla para salir." << endl;
    cin >> choice;

    switch(choice){

    case 1:
        reservation();
        break;
    case 2:
        title();
        cout << "Aqui se mostrara la opcion para cancelar una reservacion." << endl;
        break;
    case 3:
        title();
        showAvailable();
        break;
    case 4:
        title();
        showDestinations();
        break;
    default:
        title();
        cout << "\nSaliendo del programa..." << endl;
        exit(0);
    }
}

void showDestinations(){
    cout << "\n1. El Progreso." << endl;
    cout << "2. Zacapa." << endl;
    cout << "3. Chiquimula." << endl;
}

