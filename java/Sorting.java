// Created by Paul Gonzalez Becerra

import java.util.Random;

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
	public static void main(String[] args)
	{
		// Variables
		int[]	array=	new int[21];
		Random	rng=	new Random();
		Sorting	sorted=	new Sorting(array);
		
		for(int i= 0; i< sorted.items.length; i++)
			sorted.items[i]=	rng.nextInt(300);
		
		System.out.print("Original array: ");
		displayArray(sorted.items);
		sorted.mergeSort();
		System.out.print("Sorted array: ");
		displayArray(sorted.items);
	}
	
	// Displays the given array
	public static void displayArray(int[] array)
	{
		for(int i= 0; i< array.length; i++)
		{
			if(i== array.length-1)
				System.out.println(array[i]);
			else
				System.out.print(array[i]+", ");
		}
	}
	
	// Methods
	
	// Sorts the array using the merge sort
	public void mergeSort()
	{
		// Variables
		int[]	temp=	new int[items.length];
		
		splitMerge(temp, 0, items.length);
	}
	
	// Splits the array in half over the given domain [begin, end]
	private void splitMerge(int[] temp, int begin, int end)
	{
		if(end-begin< 2)
			return;
		
		// Variables
		int	middle=	(begin+end)/2;
		
		splitMerge(temp, begin, middle);
		splitMerge(temp, middle, end);
		temp=	merge(temp, begin, middle, end);
		copy(temp, begin, end);
	}
	
	// Merges the fragments of the given domain [begin, end]
	private int[] merge(int[] temp, int begin, int middle, int end)
	{
		// Variables
		int	h=	begin;
		int	k=	middle;
		
		for(int i= begin; i< end; i++)
		{
			if(h< middle && (k>= end || items[h]<= items[k]))
				temp[i]=	items[h++];
			else
				temp[i]=	items[k++];
		}
		
		return temp;
	}
	
	// Copies over the array given the domain [begin, end]
	private void copy(int[] temp, int begin, int end)
	{
		for(int i= begin; i< end; i++)
			items[i]=	temp[i];
	}
}

// End of File