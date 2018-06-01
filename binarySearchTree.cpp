#include <iostream>
#include <string>

using namespace std;

struct node {
	string data;
	node* childLeft;
	node* childRight;
};


node* GetNewNode(string data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->childLeft = newNode->childRight = NULL;
	return newNode;
}


node* Insert(node* root,string data) {
	if(root == NULL) {
		root = GetNewNode(data);
	}

	else if((data.compare(root->data))==-1) {
		root->childLeft = Insert(root->childLeft,data);
	}

	else {
		root->childRight = Insert(root->childRight,data);
	}
	return root;
}

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
	node* root = NULL;
	/*Code to test the logic*/
	root = Insert(root,"m");
	root = Insert(root,"o");
	root = Insert(root,"q");
	root = Insert(root,"z");
	root = Insert(root,"w");
	root = Insert(root,"r");
	root = Insert(root,"t");
	root = Insert(root,"u");
	root = Insert(root,"a");
	root = Insert(root,"b");
	root = Insert(root,"c");
	root = Insert(root,"d");
	root = Insert(root,"e");
	root = Insert(root,"f");
	root = Insert(root,"g");
	root = Insert(root,"h");

	cout << "Si desea hacer una comprobacion, por favor revise el codigo fuente." << endl;
 // Si se desea comprobar que los valores han sido guardados, por favor eliminar /**/ del ultimo comentario.
/*	string letter;
	cout<<"Ingrese la letra que desea buscar:\n";
	cin>>letter;

	if(Search(root,letter) == true)
        cout<<"Encontrada.\n";
	else cout<<"Letra no encontrada.\n";
        */
}

