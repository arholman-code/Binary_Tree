/*
Andrew Holman

********************************************************************
The following will output a binary tree and denote each leaf's 
level by a series of dashes (-).
*******************************************************************/

#include <iostream>
#include <iostream>
#include <iostream>
#include <strstream>
#include <iomanip>
#include <string>
#include <queue>
using namespace std;

template <typename T>
class tnode
{
   public:
		// tnode is a class implementation structure. making the
		// data public simplifies building class functions
		T nodeValue;
		tnode<T> *left, *right;

		// default constructor. data not initialized
		tnode()
		{}

      // initialize the data members
		tnode (const T& item, tnode<T> *lptr = NULL, 
				 tnode<T> *rptr = NULL):
					nodeValue(item), left(lptr), right(rptr)
		{}
};

#ifndef NULL
#include <cstddef>
#endif  // NULL

// objects hold a formatted label string and the level,column
// coordinates for a shadow tree node
class tnodeShadow
{
	public:
		string nodeValueStr;	// formatted node value
		int level,column;
		tnodeShadow *left, *right;

		tnodeShadow ()
		{}
};

// create one of three binary trees with character data.
// the argument n selects from tree 0 - tree 2
tnode<char> *buildTree(int n);


// traverse the tree level by level and output each node in a
// binary tree. output separator after each node value. default value
// of separator is "  "
template <typename T>
void levelorderOutput(tnode<T> *t, const string& separator);

tnode<char> *buildTree(int n)
{
	// 9 tnode pointers; points to the 9 items in the tree
	tnode<char> *root, *b, *c, *d, *e, *f, *g, *h, *i;

	// parameter n specifies a tree in the range 0 - 2
	switch(n)
	{
		// nodes d and e are leaf nodes
		case 0:
			d = new tnode<char> ('D');
			e = new tnode<char> ('E');
			b = new tnode<char> ('B',(tnode<char> *)NULL, d);
			c = new tnode<char> ('C',e, (tnode<char> *)NULL);
			root = new tnode<char> ('A',b, c);
			break;

		// nodes g, h, i, and d are leaf nodes
		case 1:
			g = new tnode<char> ('G');
			h = new tnode<char> ('H');
			i = new tnode<char> ('I');
			d = new tnode<char> ('D');
			e = new tnode<char> ('E',g, (tnode<char> *)NULL);
			f = new tnode<char> ('F',h, i);
			b = new tnode<char> ('B',d, e);
			c = new tnode<char> ('C',(tnode<char> *)NULL, f);
			root = new tnode<char> ('A',b, c);
			break;

		// nodes g, h, i and f are leaf nodes
		case 2:
			g = new tnode<char> ('G');
			h = new tnode<char> ('H');
			i = new tnode<char> ('I');
			d = new tnode<char> ('D',(tnode<char> *)NULL, g);
			e = new tnode<char> ('E',h, i);
			f = new tnode<char> ('F');
			b = new tnode<char> ('B',d, (tnode<char> *)NULL);
			c = new tnode<char> ('C',e, f);
			root = new tnode<char> ('A',b, c);
			break;
	}

	return root;
}


template <typename T>
void levelorderOutput(tnode<T> *t, const string& separator = "  ")
{
   // store siblings of each node in a queue so that they are
   // visited in order at the next level of the tree
   queue<tnode<T> *> q;
   tnode<T> *p;

   // initialize the queue by inserting the root in the queue
   q.push(t);

   // continue the iterative process until the queue is empty
   while(!q.empty())
   {
      // delete front node from queue and output the node value
      p = q.front();
		q.pop();
      cout << p->nodeValue << separator;
		
		// if a left child exists, insert it in the queue
      if(p->left != NULL)
		  q.push(p->left);

      // if a right child exists, insert next to its sibling
      if(p->right != NULL)	
		  q.push(p->right);
   }
}

int main()
{
	cout << "Inorder:\n";

	levelorderOutput(buildTree(1), "-");
	

	return 0;
}
