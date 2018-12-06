#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//BASIC BINARY SEARCH TREE STRUCTURE
struct tree
{
	int value;
	tree* left;
	tree* right;
};

tree* branch(int val);

int main()
{
	//VARIABLE INSTANTIATION
	tree* head = (tree*)malloc(sizeof(tree));	// creates the head node of the BST
	head->right = NULL;
	head->left = NULL;
	tree* temp;		// pointer to a temporary tree for placement in the BST
	tree* current = head;	// pointer to the current point in the BST
	int n;			// holds the number of nodes on the BST to create
	int value;		// holds the user inputted value of the node

	//INPUTS
	cout << "Enter the value of the head node: ";
	cin >> value;
	head->value = value;
	cout << "How many nodes to create: ";
	cin >> n;
	
	//CREATING THE BST
	for(int i = 0; i < n; i++)
	{
		cout << "Enter the value of the node: ";
		cin >> value;
		temp = branch(value);
		
		while(true)
		{
			if(temp->value > current->value)	// check to see if moving right
			{
				if(current->right == NULL)	// check to see if there is an empty spot for the created node
				{
					current->right = temp;	// places the created node in the tree
					break;
				}
				else
				{
					current = current->right;	// moves right
					cout << "Going right" << endl;
				}
			}
			else					// going left
			{
				if(current->left == NULL)	// check to see if there is an empty spot for the created node
				{
					current->left = temp;	// places the created node in the tree
					break;			
				}
				else
				{	
					current = current->left;	// moves left
					cout << "Going left" << endl;
				}
			}
		}
		current = head;
	}
}

//FUNCTION TO CREATE AN EMPTY NODE
tree* branch(int val)
{
	tree* newTree = (tree*)malloc(sizeof(tree));
	newTree->right = NULL;
	newTree->left = NULL;
	newTree->value = val;
	return newTree;
}
