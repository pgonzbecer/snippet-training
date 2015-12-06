// Created by Paul Gonzalez Becerra

public class ListRemoveDuplication
{
	// Variables
	public String[]	items;
	public int	size;
	
	// Constructors
	
	public ListRemoveDuplication(String[] array)
	{
		items=	array;
		size=	array.length;
	}
	
	// Static Methods
	
	public static void main(String[] args)
	{
		// Variables
		ListRemoveDuplication	lrd;
		
		if(args.length== 0)
		{
			System.out.println("Please enter an array of integers in the command window");
			return;
		}
		lrd=	new ListRemoveDuplication(args);
		
		System.out.print("Original array: ");
		for(int i= 0; i< lrd.size; i++)
		{
			if(i== lrd.size-1)
				System.out.println(lrd.items[i]);
			else
				System.out.print(lrd.items[i]+", ");
		}
		
		lrd.removeAllDuplicates();
		System.out.print("Non-duplication array: ");
		for(int i= 0; i< lrd.size; i++)
		{
			if(i== lrd.size-1)
				System.out.println(lrd.items[i]);
			else
				System.out.print(lrd.items[i]+", ");
		}
	}
	
	// Methods
	
	// Removes all the duplications of the given value not deleting the one in the given index
	public void removeDuplicatesOf(String value, int index)
	{
		for(int i= size-1; i>= 0; i--)
		{
			if(i== index)
				continue;
			if(value.equals(items[i]))
				items[i]=	null;
		}
	}
	public void removeDuplicatesOf(String value)	{	removeDuplicatesOf(value, getIndexOf(value));	}
	
	// Removes any and all duplicates within the array stored
	public void removeAllDuplicates()
	{
		// Variables
		int	i=	0;
		
		while(i< size)
		{
			if(items[i]!= null)
				removeDuplicatesOf(items[i], i);
			i++;
		}
	}
	
	// Gets the index of the given value
	public int getIndexOf(String value)
	{
		for(int i= 0; i< size; i++)
		{
			if(value.equals(items[i]))
				return i;
		}
		
		return -1;
	}
}

// End of File