//Kirk Vasilas

#include<iostream>
using namespace std;

class TreeNode {
public:
	int value;
	TreeNode *left;
	TreeNode *right;

	TreeNode()
	{
		value = 0;
		left = NULL;
		right = NULL;
	}

	~TreeNode()
	{

	}
};

class BST {
public:
	TreeNode *root;
	BST(){
		root = NULL;
	}
	TreeNode* findParentOfSmall(TreeNode *ptr){
		if (root == NULL)
		{
			cout << "Tree is empty" << endl;
		}
		else
		{
			if (ptr->left != NULL)
				if (ptr->left->left != NULL)
					return findParentOfSmall(ptr->left);
			return ptr;
		}
	}
	void addNodeBST(int key){
		if (root == NULL)
		{
			root = new TreeNode;
			root->value = key;
			return;
		}
		TreeNode *chase, *follow;
		chase = follow = root;
		while (chase != NULL)
		{
			follow = chase;
			if (chase->value == key) {
				cout << "Duplicates not allowed" << endl;
				return;
			}
			if (key > chase->value)
				chase = chase->right;
			else
				chase = chase->left;
		}
		if (follow->value > key)
		{
			follow->left = new TreeNode;
			follow->left->value = key;
		}
		else
		{
			follow->right = new TreeNode;
			follow->right->value = key;
		}

	}
	void deleteNode(int key){
		TreeNode *chase, *follow;
		chase = follow = root;
		while (chase->value != key)
		{
			follow = chase;
			if (key > chase->value)
				chase = chase->right;
			else if (key < chase->value)
				chase = chase->left;
		}
		// CASE I No Child
		if (chase->right == NULL && chase->left == NULL)
		{
			if (follow->right)
			{
				if (follow->right->value == chase->value)
				{
					follow->right = NULL;
					delete chase;
				}
			}
			else if (follow->left)
			{
				if (follow->left->value == chase->value)
				{
					follow->left = NULL;
					delete chase;
				}
			}
		}
		// CASE III Two Child
		else if (chase->right != NULL && chase->left != NULL)
		{
			TreeNode* temp;
			follow = findParentOfSmall(chase->right);
			if (follow->left)
			{
				chase->value = follow->left->value;
				temp = follow->left;
				follow->left = follow->left->right;
				delete temp;
			}
			else
			{
				chase->value = follow->value;
				temp = follow;
				chase->right = follow->right;
				temp->right = NULL;
				delete temp;
			}

		}
		// CASE II One Child
		else if (chase->right != NULL || chase->left != NULL)
		{
			if (chase->right != NULL)
			{
				follow->right = chase->right;
				delete chase;
				chase = NULL;
			}
			else if (chase->left != NULL)
			{
				follow->right = chase->left;
				delete chase;
				chase = NULL;
			}
		}
	}
	void searchBST(int key, TreeNode *ptr){
		if (ptr == NULL)
		{
			cout << "Value not found" << endl;
		}
		else if (ptr->value == key) {
			cout << "Found the value!" << endl;
			return;
		}

		else if (key > ptr->value)
		{
				searchBST(key, ptr->right);
		}
		else if ( key < ptr->value)
		{
			searchBST(key, ptr->left);
		}
	}
	void printInOrder(TreeNode *ptr){
		if (root != NULL)
		{
			if (ptr->left != NULL)
			{
				printInOrder(ptr->left);
			}
				cout << ptr->value << "" << endl;

			if (ptr->right != NULL)
			{
				printInOrder(ptr->right);
			}
		}
		else
		{
			cout << "The Tree is empty" << endl;
		}
	}
	void printPreOrder(TreeNode *ptr){
		if (root != NULL)
		{
			cout << ptr->value << "" << endl;
			if (ptr->left != NULL)
			{
				printInOrder(ptr->left);
			}
			if (ptr->right != NULL)
			{
				printInOrder(ptr->right);
			}
		}
		else
		{
			cout << "The Tree is empty" << endl;
		}
	}
	void printPostOrder(TreeNode *ptr){
		if (root != NULL)
		{
			if (ptr->left != NULL)
			{
				printInOrder(ptr->left);
			}
			if (ptr->right != NULL)
			{
				printInOrder(ptr->right);
			}
			cout << ptr->value << "" << endl;
		}
		else
		{
			cout << "The Tree is empty" << endl;
		}
	}
	void deleteTree(int start){
		while(root != nullptr){
			deleteNode(root->value);
		}
	}
	int firstCommonParent(TreeNode *root,int V1, int V2){
		if(root == NULL) {cout << "no tree buddy, sorry";}
		if(root->value > V1 && root->value > V2)
		{
			return firstCommonParent(root->left,V1,V2);
		}
		if(root->value < V1 && root->value < V2)
		{
			return firstCommonParent(root->right,V1,V2);
		}
		else
		{
			cout << root << '\n';
		}
	}
};

int main()
{
	BST myBST;
	int choose;
	int addingNodeInput,removingNodeInput;
	while (1)
		{
			cout << "Hello what would you like to do\n (1) to add a node \n (2) to remove a node \n (3) to display the BST Tree <<  Anything else to leave" << endl;
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "What number would you like to add" << endl;
				cin >> addingNodeInput;
				myBST.addNodeBST(addingNodeInput);
				break;
			case 2:
				cout << "What node would you like to remove" << endl;
				cin >> removingNodeInput;
				myBST.deleteNode(removingNodeInput);
				break;
			case 3:
				cout << "In Order : " << endl;
				myBST.printInOrder(myBST.root);
				cout << "Post Order : " << endl;
				myBST.printPostOrder(myBST.root);
				cout << "Pre Order : " << endl;
				myBST.printPreOrder(myBST.root);
				break;
			default:
				cout << "Goodbye" << endl;
        break;

			}
		}
	system("Pause");
	return 0;

}
