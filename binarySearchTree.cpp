#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>

using namespace std;


struct node{
    string data;
    struct node* parent;
    struct node* childLeft;
    struct node* childRight;

};

struct node* newNode(string data);

string a = "c";
string b = "";

int main(){

//if((value1.compare(value2))>0)
cout << a.compare(b) << endl;

return 0;
}

struct node* newNode(string data){
    node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->childLeft = newNode->childRight = NULL;

    return newNode;
}
