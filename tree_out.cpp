/*******************************************************************
I understand and have abided by the UNCG Academic Integrity Policy:
Andrew Holman
1060
CSC 330-01
Spring 2010
********************************************************************
********************************************************************
The following will output a binary tree and denote each leaf's 
level by a series of dashes (-).
*******************************************************************/

#include <iostream>
#include <iostream>
#include <strstream>
#include <iomanip>
#include <string>
#include <queue>
using namespace std;

#ifndef NULL
#include <cstddef>
#endif  // NULL

class binaryTree
{
private:
	struct TreeNode
	{
		char letter;			//value in node
		TreeNode *left;		//pointer to left leaf
		TreeNode *right;	//pointer to right leaf
	};

	TreeNode *root;			//points to root

	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(char, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void inOrder(TreeNode *);
	void preOrder(TreeNode*);
public:
	binaryTree()
	{ root = NULL; }

	~binaryTree()
	{ destroySubTree(root); }

	void insertNode(char);
	bool searchNode(char);
	void remove(char);
	void inOrder()
	{	inOrder(root);	}
	void preOrder()
	{	preOrder(root);	}
};

void binaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
      nodePtr = newNode;                  //new node inserted
   else if (newNode->letter < nodePtr->letter)
      insert(nodePtr->left, newNode);     //check left branch and compare
   else 
      insert(nodePtr->right, newNode);    //check right branch and compare
}

void binaryTree::insertNode(char x)
{
   TreeNode *newNode;      //points to the new node

   newNode = new TreeNode;
   newNode->letter = x;
   newNode->left = newNode->right = NULL;
   
   //insert node
   insert(root, newNode);
}

void binaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
  
bool binaryTree::searchNode(char x)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->letter == x)
         return true;
      else if (x < nodePtr->letter)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

void binaryTree::remove(char x)
{
   deleteNode(x, root);
}

void binaryTree::deleteNode(char x, TreeNode *&nodePtr)
{
   if (x < nodePtr->letter)
      deleteNode(x, nodePtr->left);
   else if (x > nodePtr->letter)
      deleteNode(x, nodePtr->right);
   else
      makeDeletion(nodePtr);
}

void binaryTree::makeDeletion(TreeNode *&nodePtr)
{
   //reattach the left subtree
   TreeNode *tempNodePtr;

   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   //reattach the left leaf
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  //reattach the right leaf
      delete tempNodePtr;
   }
   else
   {
      //move node to the right if it already has two
      tempNodePtr = nodePtr->right;
      //go to the end of the left subtree
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      //reattach the left tree
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      //the right tree
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

void binaryTree::inOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      inOrder(nodePtr->left);
      cout << nodePtr->letter << endl;
      inOrder(nodePtr->right);
   }
}

void binaryTree::preOrder(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      cout << nodePtr->letter << endl;
      preOrder(nodePtr->left);     
      preOrder(nodePtr->right);
   }
}



int main()
{
	binaryTree a;
	a.insertNode('A');
	a.insertNode('B');
	a.insertNode('C');
	a.insertNode('D');
	a.insertNode('E');
	a.insertNode('F');
	a.insertNode('G');
	a.insertNode('H');
	a.insertNode('I');

	cout << "Inorder:\n";
	a.preOrder();

	return 0;
}