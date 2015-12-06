// Created by Paul Gonzalez Becerra

using System;

public static class Start
{
	// Static Methods
	
	// Starts the app
	public static void Main(string[] args)
	{
		// Variables
		ListRemoveDuplication	lrd;
		
		if(args.Length== 0)
		{
			Console.WriteLine("Please enter an array of integers in the command prompt");
			return;
		}
		lrd=	new ListRemoveDuplication(args);
		
		Console.Write("Original array: ");
		for(int i= 0; i< lrd.size; i++)
		{
			if(i== lrd.size-1)
				Console.WriteLine(lrd.items[i]);
			else
				Console.Write(lrd.items[i]+", ");
		}
		Console.Write("Non-duplication array: ");
		lrd.removeAllDuplicates();
		for(int i= 0; i< lrd.size; i++)
		{
			if(i== lrd.size-1)
				Console.WriteLine(lrd.items[i]);
			else
				Console.Write(lrd.items[i]+", ");
		}
	}
}

public class ListRemoveDuplication
{
	// Variables
	public string[]	items;
	public int	size;
	
	// Constructors
	
	public ListRemoveDuplication(string[] array)
	{
		items=	array;
		size=	array.Length;
	}
	
	// Methods
	
	// Removes all the duplicates of the given value
	public void removeDuplicatesOf(string value, int index)
	{
		for(int i= size-1; i>= 0; i--)
		{
			if(i== index)
				continue;
			if(value== items[i])
				items[i]=	null;
		}
	}
	public void removeDuplicatesOf(string value)	{	removeDuplicatesOf(value, getIndexOf(value));	}
	
	// Gets the index of the given value
	public int getIndexOf(string value)
	{
		for(int i= 0; i< size; i++)
		{
			if(value== items[i])
				return i;
		}
		
		return -1;
	}
	
	// Removes any and all duplicates within the array stored
	public void removeAllDuplicates()
	{
		// Variables
		int	i=	0;
		
		while(i< size)
		{
			if(items[i]!= null)
				removeDuplicatesOf(items[i], i); // remove(i);
			i++;
		}
	}
}

// End of File