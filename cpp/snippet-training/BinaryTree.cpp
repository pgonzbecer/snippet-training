// Created by Paul Gonzalez Becerra

#include<iostream>
#include<stdio.h>
#include<ctime>

#define SIZE(a)	(sizeof(a)/sizeof(*a));

using namespace std;

class Node
{
	public:
		// Variables
		int	id;
		Node*	left;
		Node*	right;

		// Constructors

		Node(int n)
		{
			id=	n;
			left=	(Node*)0;
			right=	(Node*)0;
		}

		// Methods

		// Inserts the given key into the nodes
		void insert(int key)
		{
			if(key== id) // No duplicates
				return;
			if(key< id)
			{
				if(left== (Node*)0)
					left=	new Node(key);
				else
					(*left).insert(key);
			}
			else
			{
				if(right== (Node*)0)
					right=	new Node(key);
				else
					(*right).insert(key);
			}
		}

		// Displays the node
		void display(int index, char type)
		{
			for(int i= 0; i< index; i++)
				cout<< "  |";
			cout<< "+"<< id<< "  :  ";
			switch(type)
			{
				case 0:	cout<< "ROOT\n";	break;
				case 1:	cout<< "RIGHT\n";	break;
				case 2:	cout<< "LEFT\n";	break;
			}

			if(left!= (Node*)0)
				(*left).display(index+1, 2);
			if(right!= (Node*)0)
				(*right).display(index+1, 1);
		}
};

class BinaryTree
{
	public:
		Node*	root;

		// Constructors

		BinaryTree()
		{
			root=	(Node*)0;
		}

		// Methods

		// Populates the tree with the given array
		void populateTree(int a[], int asize)
		{
			for(int i= 0; i< asize; i++)
			{
				if(root== (Node*)0)
					root=	new Node(a[i]);
				else
					(*root).insert(a[i]);
			}
		}

		// Displays the tree
		void displayTree()
		{
			if(root== (Node*)0)
				cout<< "--- Tree is empty ---";
			else
				(*root).display(0, 0);
		}
};

/*
// Starts up the app
void main()
{
	// Variables
	BinaryTree	tree=	BinaryTree();
	int	asize=	20;
	int	a[20];

	srand(time(0));

	for(int i= 0; i< asize; i++)
		a[i]=	i+(rand()%132);

	tree.populateTree(a, asize);
	tree.displayTree();
}*/

// End of File