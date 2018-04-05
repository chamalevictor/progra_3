#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct prueba{

    int numero;
    string nombre;
};

int main(){

struct prueba test;
struct prueba* ptrTest;

ptrTest=&test;

cout << "ingrese numero" << endl;
cin>> test.numero;
cout <<"ingrese nombre" << endl;
cin>> test.nombre;



cout << "El resultado del numero es: " << ptrTest->numero << endl;
cout << "El nombre inresado es: " << ptrTest->nombre << endl;

return 0;
}



