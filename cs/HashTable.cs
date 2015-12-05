// Created by Paul Gonzalez Becerra

using System;

public class Dummy
{
	public static void Main()
	{
		// Variables
		string	line;
		int	id=	0;
		HashTable	table=	new HashTable(50);
		Random	rng=	new Random();
		
		for(int i= 0; i< 500; i++)
		{
			table.insert((i+rng.Next(10, 200))%7000, (char)((i%26)+65)+"");
		}
		
		while(true)
		{
			Console.Write("--- Type any non-number to exit ---\nType in a number to find within the hash table\n> ");
			line=	Console.ReadLine();
			if(line.ToLower()== "display")
			{
				table.display();
				continue;
			}
			if(!int.TryParse(line, out id))
				break;
			Console.WriteLine("Key: "+id+"; Val: "+table.get(id)+";");
		}
	}
}

public class LinkedList<T>
{
	// Variables
	public LinkedNode<T>	root;
	
	// Constructors
	
	public LinkedList(T value)
	{
		root=	new LinkedNode<T>(value);
	}
}

public class LinkedNode<T>
{
	// Variables
	public T	val;
	public LinkedNode<T>	nextNode;
	
	// Constructors
	
	public LinkedNode(T value)
	{
		val=	value;
		nextNode=	null;
	}
	
	// Methods
	
	// Inserts the given value to the very back of the linked node
	public void insertToBack(T value)
	{
		if(value.Equals(val))
			return;
		if(nextNode== null) // Finds a place to add it
			nextNode=	new LinkedNode<T>(value);
		else
			nextNode.insertToBack(value);
	}
	
	// Gets the index of the given value within the linked nodes
	private int getIndexOf(T value, int id)
	{
		if(value.Equals(val))
			return id;
		if(nextNode== null)
			return -1;
		
		return nextNode.getIndexOf(value, id+1);
	}
	public int getIndexOf(T value)	{	return getIndexOf(value, 0);	}
	
	// Gets the last index of the linked nodes
	private int getLastIndex(int id)
	{
		if(nextNode== null)
			return id;
		
		return nextNode.getLastIndex(id+1);
	}
	public int getLastIndex()	{	return getLastIndex(1);	}
	
	// Gets the value from the given index within the linked nodes
	public T getFromIndex(int index)
	{
		if(index== 0)
			return val;
		if(nextNode== null)
			return (T)((object)null);
		
		return nextNode.getFromIndex(index-1);
	}
	
	// Removes the value and key from the given index within the linked nodes
	public bool removeFromIndex(int index)
	{
		if(index-1== 0 && nextNode!= null)
		{
			nextNode=	nextNode.nextNode;
			
			return true;
		}
		if(nextNode== null)
			return false;
		
		return nextNode.removeFromIndex(index-1);
	}
}

public class HashEntry
{
	// Variables
	public LinkedList<int>	key;
	public LinkedList<string>	val;
	
	// Constructors
	
	public HashEntry(int pmKey, string pmVal)
	{
		key=	new LinkedList<int>(pmKey);
		val=	new LinkedList<string>(pmVal);
	}
	
	// Methods
	
	// Adds the given key and value to the bucket list
	public void addToBucket(int pmKey, string pmVal)
	{
		key.root.insertToBack(pmKey);
		val.root.insertToBack(pmVal);
	}
	
	// Gets the value from the bucket using the given key
	public string getFromBucket(int pmKey)
	{
		// Variables
		int index=	key.root.getIndexOf(pmKey);
		
		if(index== -1)
			return null;
		
		return val.root.getFromIndex(index);
	}
	
	// Removes the value and key from the given key out of the bucket
	public bool removeFromBucket(int pmKey)
	{
		// Variables
		int	index=	key.root.getIndexOf(pmKey);
		
		if(index== -1)
			return false;
		
		key.root.removeFromIndex(index);
		val.root.removeFromIndex(index);
		
		return true;
	}
	
	// Displays the contents of the bucket
	public void display()
	{
		// Variables
		int	full=	key.root.getLastIndex();
		
		for(int i= 0; i< full; i++)
			Console.WriteLine("Key: "+key.root.getFromIndex(i)+"; Val: "+val.root.getFromIndex(i)+";");
	}
}

public class HashTable
{
	// Variables
	private HashEntry[]	table;
	private int	size;
	
	// Constructors
	
	public HashTable(int pmSize)
	{
		size=	pmSize;
		table=	new HashEntry[size];
	}
	public HashTable():this(256)	{}
	
	// Methods
	
	// Inserts the given key and value into the hashtable
	public void insert(int key, string val)
	{
		// Variables
		int	hash=	getHash(key);
		
		if(table[hash]== null) // Nothing is found
			table[hash]=	new HashEntry(key, val);
		else // Add to the end
			table[hash].addToBucket(key, val);
	}
	
	// Clears out the entire hashtable
	public void clear()
	{
		table=	new HashEntry[size];
	}
	
	// Gets the value of the given key
	public string get(int key)
	{
		// Variables
		int	hash=	getHash(key);
		
		if(table[hash]== null) // Nothing is found
			return null;
		else
			return table[hash].getFromBucket(key);
	}
	
	// Removes the value and key with the given key
	public bool remove(int key)
	{
		// Variables
		int	hash=	getHash(key);
		
		if(table[hash]== null) // Nothing is found
			return true;
		else
			return table[hash].removeFromBucket(key);
	}
	
	// Gets the size of the hash table
	public int getSize()
	{
		return size;
	}
	
	// Displays the hash table
	public void display()
	{
		for(int i= 0; i< size; i++)
		{
			if(table[i]== null)
			{
				Console.WriteLine("Entry "+i+": NULL");
			}
			else
			{
				Console.WriteLine("Entry "+i+":");
				table[i].display();
			}
		}
	}
	
	// Gets the hash of the given key
	private int getHash(int key)
	{
		return key%size;
	}
}

// End of File
