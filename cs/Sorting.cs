// Created by Paul Gonzalez Becerra

using System;

public class Sorting
{
	// Variables
	public int[]	items;
	
	// Constructors
	
	public Sorting(int[] pmItems)
	{
		items=	pmItems;
	}
	
	// Static Methods
	
	// Starts up the app
	public static void Main()
	{
		// Variables
		int[]	array=	new int[20];
		Random	rng=	new Random();
		Sorting	begin=	new Sorting(array);
		
		for(int i= 0; i< array.Length; i++)
			array[i]=	rng.Next(0, 300);
		
		Console.Write("Original array: ");
		displayArray(begin.items);
		Console.Write("Sorted array: ");
		begin.mergeSort();
		displayArray(begin.items);
	}
	
	// Displays the array
	public static void displayArray(int[] items)
	{
		for(int i= 0; i< items.Length; i++)
		{
			if(i== items.Length-1)
				Console.WriteLine(items[i]);
			else
				Console.Write(items[i]+", ");
		}
	}
	
	// Methods
	
	// Sorts the stored array and sorts it via the merge sort way
	public void mergeSort()
	{
		// Variables
		int[]	temp=	new int[items.Length];
		
		splitMerge(ref temp, 0, items.Length);
	}
	
	// Splits up the array into the smallest possible form then eventually merges them together
	private void splitMerge(ref int[] temp, int begin, int end)
	{
		if(end-begin< 2)
			return;
		
		// Variables
		int	middle=	(begin+end)/2;
		
		splitMerge(ref temp, begin, middle); // Left half
		splitMerge(ref temp, middle, end); // Right half
		merge(ref temp, begin, middle, end);
		copy(ref temp, begin, end);
	}
	
	// Merges together all the split up pieces of the original array
	private void merge(ref int[] temp, int begin, int middle, int end)
	{
		// Variables
		int	h=	begin;
		int	k=	middle;
		
		for(int i= begin; i< end; i++)
		{ 
			if(h< middle && (k>= end || items[h]<= items[k]))
			{
				temp[i]=	items[h];
				h++;
			}
			else
			{
				temp[i]=	items[k];
				k++;
			}
		}
	}
	
	// Copys the given array to the slots in the stored array with the given domain [begin,end]
	private void copy(ref int[] temp, int begin, int end)
	{
		for(int i= begin; i< end; i++)
			items[i]=	temp[i];
	}
}

// End of File