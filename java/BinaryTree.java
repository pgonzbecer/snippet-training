// Created by Paul Gonzalez Becerra

import	java.util.Random;

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
	public static void main(String[] args)
	{
		// Variables
		int[]	array=	new int[20];
		Random	rng=	new Random();
		BinaryTree	tree=	new BinaryTree();
		
		for(int i= 0; i< array.length; i++)
			array[i]=	rng.nextInt(132)+12;
		
		tree.populateTree(array);
		tree.displayTree();
	}
	
	// Methods
	
	// Populates the binary tree
	public void populateTree(int[] array)
	{
		for(int i= 0; i< array.length; i++)
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
			System.out.println("--- Tree is Empty ---");
		else
			root.display(0, 0);
	}
	
	// Nested objects
	
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
			if(key== id)
				return;
			
			if(key< id)
			{
				if(left== null)
					left=	new Node(key);
				else
					left.insert(key);
			}
			else
			{
				if(right== null)
					right=	new Node(key);
				else
					right.insert(key);
			}
		}
		
		// Displays the binary tree
		public void display(int index, int type)
		{
			for(int i= 0; i< index; i++)
				System.out.print("  |");
			System.out.print("+"+id+"  :  ");
			switch(type)
			{
				case 0:	System.out.println("ROOT");	break;
				case 1:	System.out.println("RIGHT");	break;
				case 2:	System.out.println("LEFT");	break;
			}
			if(left!= null)
				left.display(index+1, 2);
			if(right!= null)
				right.display(index+1, 1);
		}
	}
}

// End of File