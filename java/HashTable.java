// Created by Paul Gonzalez Becerra

import	java.util.Random;
import	java.util.Scanner;

public class HashTable<T>
{
	// Variables
	private int[]	keys; // Keys must be a positive number, any negatives suggest it does not exist
	private T[]	vals;
	private int	size;
	public static final int	DEFAULT_TABLE_SIZE=	128;
	
	// Constructors
	
	public HashTable(int pmSize)
	{
		size=	pmSize;
		keys=	new int[size];
		for(int i= 0; i< size; i++)
			keys[i]=	-1;
		vals=	(T[])(new Object[size]);
	}
	public HashTable()	{	this(HashTable.DEFAULT_TABLE_SIZE);	}
	
	// Static Methods
	
	// Starts up the application
	public static void main(String[] args)
	{
		// Variables
		HashTable	table=	new HashTable(500);
		Random	rng=	new Random();
		int	itema;
		float	itemb;
		String	line=	"";
		Scanner	reader=	new Scanner(System.in);
		
		for(int i= 0; i< table.getSize(); i++)
		{
			itema=	(i+rng.nextInt(table.getSize()))%table.getSize();
			itemb=	(table.getSize()*rng.nextFloat());
			
			System.out.println("Key: "+itema+"; Val: "+itemb+";");
			
			table.add(itema, itemb);
		}
		
		try
		{
			while(true)
			{
				System.out.print("Type any non-number to exit; or find the item by inputting a key.\n> ");
				line=	reader.nextLine();
				itema=	Integer.parseInt(line);
				System.out.println("Key: "+itema+"; Val: "+table.get(itema)+";");
			}
		}
		catch(Exception e){}
	}
	
	// Methods
	
	// Gets the size of the hash table
	public int getSize()
	{
		return size;
	}
	
	// Gets the value of the given key
	public T get(int key)
	{
		// Variables
		int	hash=	key%size;
		int	exitCache=	0;
		
		while(keys[hash]!= -1 && keys[hash]!= key || exitCache== size+4)
		{
			hash=	(hash+1)%size;
			exitCache++;
		}
		
		if(exitCache== size+4)
			return null;
		
		return vals[hash];
	}
	
	// Adds the given key and value to the hash table
	public void add(int key, T val)
	{
		// Variables
		int	hash=	key%size;
		int exitCache=	0;
		
		while(keys[hash]!= -1 && keys[hash]!= key || exitCache== size+4)
		{
			hash=	(hash+1)%size;
			exitCache++;
		}
		
		keys[hash]=	key;
		vals[hash]=	val;
	}
}

// End of File