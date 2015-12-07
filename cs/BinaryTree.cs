// Created by Paul Gonzalez Becerra

using System;

public class BinaryTree
{
	// Variables
	public Node	root;
	
	// Constructors
	
	public BinaryTree()
	{
		root=	null;
	}
	
	// Static Methods
	
	// Starts up the app
	public static void Main()
	{
		// Variables
		BinaryTree	tree=	new BinaryTree();
		int[]	array=	new int[20];
		Random	rng=	new Random();
		
		for(int i= 0; i< array.Length; i++)
			array[i]=	rng.Next(12, 144);
		
		tree.populateTree(array);
		tree.displayTree();
	}
	
	// Methods
	
	// Populates the binary tree
	public void populateTree(int[] array)
	{
		for(int i= 0; i< array.Length; i++)
		{
			if(root== null)
				root=	new Node(array[i]);
			else
				root.insert(array[i]);
		}
	}
	
	// Displays the tree
	public void displayTree()
	{
		if(root== null)
			Console.WriteLine("--- Tree is Empty ---");
		else
			root.display(0, 0);
	}
}

public class Node
{
	// Variables
	public int	id;
	public Node	left;
	public Node	right;
	
	// Constructors
	
	public Node(int pmID)
	{
		id=	pmID;
		left=	null;
		right=	null;
	}
	
	// Methods
	
	// Inserts the given key into the nodes
	public void insert(int key)
	{
		if(key== id) // No duplicates allowed
			return;
		if(key< id)
		{
			if(left== null) // There is no left, populate that
				left=	new Node(key);
			else
				left.insert(key);
		}
		else
		{
			if(right== null) // Second verse same as the first
				right=	new Node(key);
			else
				right.insert(key);
		}
	}
	
	// Displays the binary tree
	public void display(int index, byte type)
	{
		for(int i= 0; i< index; i++)
			Console.Write("  |");
		Console.Write("+"+id+"  :  ");
		switch(type)
		{
			case 0:	Console.WriteLine("ROOT");	break;
			case 1:	Console.WriteLine("RIGHT");	break;
			case 2:	Console.WriteLine("LEFT");	break;
		}
		if(left!= null)
			left.display(index+1, 2);
		if(right!= null)
			right.display(index+1, 1);
	}
}

// End of File