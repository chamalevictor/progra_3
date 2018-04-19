#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct node {
	int data;
	node* childLeft;
	node* childRight;
};

// Function to create a new Node
node* GetNewNode(int data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->childLeft = newNode->childRight = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node
node* Insert(node* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in childLeft subtree.
	else if(data <= root->data) {
		root->childLeft = Insert(root->childLeft,data);
	}
	// else, insert in childRight subtree.
	else {
		root->childRight = Insert(root->childRight,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(node* root,int data) {
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
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(Search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
}
