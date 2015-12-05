// Created by Paul Gonzalez Becerra

#include<iostream>
#include<stdio.h>

#define SIZE(a)	(sizeof(a)/sizeof(*a));

using namespace std;

struct Node
{
	int	id;
	Node*	left;
	Node*	right;

	Node(int n)	{
		id=	n;
		left=	nullptr;
		right=	nullptr;
	}
};

class BinaryTree
{
	public:
		Node*	start;

		// Constructors

		BinaryTree()
		{
			start=	new Node(0);
		}

		// Methods
		void insert(int n, int a[], int asize)
		{
			while(n< asize)	{
				insertIntoNode(a[n], start);
				n++;
			};
		}

		void insertIntoNode(int n, Node *node)
		{
			if(node== nullptr)
			{
				node=	new Node(n);
				(*node).id=	n;
				(*node).left=	nullptr;
				(*node).right=	nullptr;
				cout<< node<< "\n";

				return;
			}

			if(n< (*node).id) // Go Left
			{
				insertIntoNode(n, (*node).left);

				return;
			}
			else if(n== (*node).id) // Duplicate
			{
				(*node).id=	n;
				return;
			}
			else // Go Right
			{
				insertIntoNode(n, (*node).right);
				return;
			}
		}

		int search(int key)
		{
			return searchFromNode(key, start);
		}
		int searchFromNode(int key, Node *node)
		{
			if(node== nullptr)
				return -1;
			if(key< (*node).id) // Go Left
			{
				return searchFromNode(key, (*node).left);
			}
			else if(key== (*node).id) // Found it!
				return key;
			else // Go right
			{
				return searchFromNode(key, (*node).right);
			}
			
		}
};

// End of File