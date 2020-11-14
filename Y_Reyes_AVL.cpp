/* AVL Assignment

Populate a tree via a text file (input.txt) Make sure that after every insert, the tree is balanced. At the end, display the tree in level format. Make sure to include the height and the balance factor of every node in your output. Redirect the display to an output file (output.txt)
*/

#include <iostream>
#include <fstream>

using namespace std;

struct BinaryTree     					//Declare a structure for the AVL Tree
{
	int height;         //Height will hold the height of the node for determining balance factor
	int key;            //Value of the node
	BinaryTree *left;   //Left child pointer
	BinaryTree *right;  //Right child pointer
};

ofstream write("output.txt");		//File our redirected output will be saved to

/*
 ______                _   _
|  ____|              | | (_)
| |__ _   _ _ __   ___| |_ _  ___  _ __  ___
|  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
| |  | |_| | | | | (__| |_| | (_) | | | \__ \
|_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
*/
void displayExplanation()
{
 cout << "\n\nThe purpose of this program is to test my ability to implement an AVL Tree. \nI will populate the tree from a text file named input.txt, making sure \nthe tree is balanced. At the end I will display the tree in level format. I will also\noutput the height and balance factor of every node in my output. This will be \nredirected to an output file named output.txt\n";
}

void yoliesProgramHeader()
{
 cout << "\n\n\t\t\t\t\t************* YOLIE REYES ***************\n";
 cout << "\t\t\t\t    ********** AVL Tree Assignment **********\n";
 cout << "\t\t\t\t\t************* 11-15-2020 ****************\n";
 cout << "\t\t\t\t\t************** CISP 430 *****************\n";
}

void yoliesProgramFooter()
{
 cout << "\n\n\t\t\t*********** Intended for Educational Purposes Only! ***********\n\n";
 cout << "\t\t\t\t\t**************** End of Program ****************\n\n\n\n";
}

//For Range loop to determine if a is more than b, return a, else return b
int max(int a, int b)
{ return (a > b) ? a : b; }

//For determining the height of the node
int height(BinaryTree *node)
{
  if (!node) { return 0; } //Empty node height is 0

	return node->height;     //We make it here if the node is not empty returning the height member variable
}

//For determining the balace factor of a node
int getBalance(BinaryTree *N)
{
	{
		if (N == NULL) { return 0; }                //If a node is not present

		return height(N->left) - height(N->right);  //We make it here if there is a valid node, we calculate the balance factor
	}
}

/*
node *leftRotate(node *x){
   struct node *y=x->right;
   //add more code to rotate to the left, update heights for x and y
   //return y
}

*/
BinaryTree *leftRotate(BinaryTree *x)
{
	BinaryTree *y = x->right;
	BinaryTree *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

/*
node *rightRotate(node *x){
   struct node *y=x->left;
   //add more code to rotate to the right, update heights for x and y
   //return y
}
*/
BinaryTree *rightRotate(BinaryTree *y)
{
	BinaryTree *x = y->left;
	BinaryTree *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

/*
//This is not a recursive algorithm
node * rebalance(node *node){
    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);  //node->left - node->right

    do rotations as necessary
      If Left heavy outside :  return rightRotate(node);
      If right heavy outside:  return leftRotate(node);
      If left heavy inside:  left rotation first, right rotation 2nd, return top node
    		node->left =  leftRotate(node->left);
    		return rightRotate(node);
     if right heavy inside: right rotation first, left rotation 2nd, return top node
		node->right = rightRotate(node->right);
        	return leftRotate(node);
     if no rotation, return node

}

*/
BinaryTree *rebalance(BinaryTree *node, int key)
{

	//asign the current node height
	node->height = max(height(node->left), height(node->right)) + 1;

	//get the balance of the current node
	int balance = getBalance(node);

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

/*
//non-tail recursive algorithm because of rebalance
node* insert(node* node, int key)
{
    //recursive Code for inserting a node
    //When insert happens set height to 0 for the node
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    node=rebalance(node);  //update heights and rebalance
    return node;
}
*/
BinaryTree *avlInsert(BinaryTree *leaf, int data)
{
//This if statement only executes if our tree is empty
	if (!leaf)
	{
		leaf = new BinaryTree;			//Create a new binaryTree structure
		leaf->right = NULL;					//Setting its left and right pointers to null
		leaf->left = NULL;
		leaf->key = data;						//Assigning the value of data node's key
		leaf->height = 0;						//Empty trees have a hieght of 0!
	}

//We get here if a node exists and place value accordingly if it is < or >
	else if (data < leaf->key) { leaf->left = avlInsert(leaf->left, data); }
	else if (data > leaf->key) { leaf->right = avlInsert(leaf->right, data); }

	leaf = rebalance(leaf, data); //Rebalance the tree
	return leaf;
}

void printLevel(BinaryTree *root, int level)
{

	if (root == NULL) return;								//If there is no node at this level return

	if (level == 1)													//We have a valid node, and it's level is 1
	{
//Print the current node's member variable named key in integer format printf("%d \t\t\t", root->key);
		int balanceFactor = 0;
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->key << " Leaf Node! ";
			write << root->key << " Leaf Node! ";
			break;
		}
		cout << root->key << ", ";
		write << root->key << ", ";										//Send that integer to the ofstream object linked to output.txt

    if (root->left != NULL && root->right != NULL)
		{
			int balanceFactor = (root->left->height) - (root->right->height);

				if( balanceFactor == 2 || balanceFactor == -2)
				{
					cout << " Balance Factor:"<< balanceFactor << ", ";
					write << " Balance Factor:"<< balanceFactor <<", " ;
				}

				else
				{
					cout << " Balance Factor:"<< balanceFactor << ", ";
					write << " Balance Factor:"<< balanceFactor <<", " ;
				}
		}

	}

	else if (level > 1)											//We make it here if we have a valid node with level>1
	{																				//Meaning we are still moving through AVL tree
		printLevel(root->left, level - 1);		//Print both the left and right children recursively
		printLevel(root->right, level - 1);		//Till we get to the base case of a node @ level 1
	}
}

void printLevelOrder(BinaryTree *root)
{
	int h = height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		printLevel(root, i);
		cout << "\n";											//If you want... printf("\n"); explain the difference between the two?
	}																		//I.e format specifiers!
}

/*
 __  __       _         ______                _   _
|  \/  |     (_)       |  ____|              | | (_)
| \  / | __ _ _ _ __   | |__ _   _ _ __   ___| |_ _  ___  _ __
| |\/| |/ _` | | '_ \  |  __| | | | '_ \ / __| __| |/ _ \| '_ \
| |  | | (_| | | | | | | |  | |_| | | | | (__| |_| | (_) | | | |
|_|  |_|\__,_|_|_| |_| |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|
*/

int main()
{
yoliesProgramHeader();
displayExplanation();

	BinaryTree *root = NULL;								//Create an empty tree

	ifstream read("input.txt");							//Declare a ifstream object to read from input.txt

	while (read.good())											//While we are not at the end of the file
	{
		int value;														//Variable to hold the current value from file
		read >> value;												//Read the current value from file
		root = avlInsert(root, value);				//Insert the value into the tree
	}

	read.close();														//Dont' forget to close your files!

	printLevelOrder(root);

	write.close();													//Don't forget to close your files!

yoliesProgramFooter();
	return 0;
}
