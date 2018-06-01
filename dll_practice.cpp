#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
    int data;
    struct node* father;
    struct node* son1;
    struct node* son2;
};

struct node* getNode();

int main(){

    node* ptrTemp = getNode();
    node* prtStored = getNode();




return 0;
}

struct node* getNode(){
    node* ptrNode = (node*)malloc(sizeof(node));
}
