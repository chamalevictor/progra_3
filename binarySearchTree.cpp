#include <iostream>
#include <string>

using namespace std;
//Definition of Node for Binary search tree
struct node {
	string data;
	node* childLeft;
	node* childRight;
};

// Function to create a new Node
node* GetNewNode(string data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->childLeft = newNode->childRight = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
node* Insert(node* root,string data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in childLeft subtree.
	else if((data.compare(root->data))==-1) {
		root->childLeft = Insert(root->childLeft,data);
	}
	// else, insert in childRight subtree.
	else {
		root->childRight = Insert(root->childRight,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(node* root,string data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->childLeft,data);
	}
	else {
		return Search(root->childRight,data);
	}
}
int main() {
	node* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,"m");
	root = Insert(root,"b");
	root = Insert(root,"o");
	root = Insert(root,"p");
	root = Insert(root,"a");
	root = Insert(root,"r");


	string letter;
	cout<<"Ingrese la letra que desea buscar:\n";
	cin>>letter;

	if(Search(root,letter) == true)
        cout<<"Encontrada.\n";
	else cout<<"Letra no encontrada.\n";
}






/*

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



//Declaring functions.
struct node* newNode(string data);


string a = "c";
string b = "";


//************* Main Function *************
int main(){

cout << a.compare(b) << endl;

return 0;

}




//Creating a new node.
struct node* newNode(string data){
    node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->childLeft = newNode->childRight = NULL;

    return newNode;
}
*/
