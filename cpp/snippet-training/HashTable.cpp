// Created by Paul Gonzalez Becerra

#include<iostream>
#include<stdio.h>
#include<ctime>

using namespace std;

// Variables
const int TABLE_SIZE=	128;

// Classes

template<class T>
class LinkedNode
{
	private:
		// Gets the index of the given value within the linked nodes
		int getIndexOf(T value, int id)
		{
			if(value== val)
				return id;
			if(nextNode== (LinkedNode<T>*)0);
				return -1;

			return nextNode->getIndexOf(value, id+1);
		}

		// Gets the last index of the linked nodes
		int getLastIndex(int id)
		{
			if(nextNode== (LinkedNode<T>*)0)
				return id;

			return nextNode->getLastIndex(id+1);
		}
	public:
		// Variables
		T	val;
		LinkedNode<T>*	nextNode;

		// Constructors

		LinkedNode(T value)
		{
			val=	value;
			nextNode=	(LinkedNode<T>*)0;
		}

		// Methods
		
		// Inserts the given value to the very back of the linked list
		void insertToBack(T value)
		{
			if(value== val)
				return;
			if(nextNode== (LinkedNode<T>*)0)
				nextNode=	new LinkedNode<T>(value);
			else
				nextNode->insertToBack(value);
		}

		// Gets the index of the given value
		int getIndexOf(T value)	{	return getIndexOf(value, 0);	}

		// Gets the last index of the linked list
		int getLastIndex()	{	return getLastIndex(1);	}

		// Gets the value from the given index within the linked nodes
		T getFromIndex(int index)
		{
			if(index== 0)
				return val;
			if(nextNode== (LinkedNode<T>*)0)
				return (T)0;

			return nextNode->getFromIndex(index-1);
		}

		// Removes the value from the given index within the linked nodes
		bool removeFromIndex(int index)
		{
			if(index-1== 0 && nextNode!= (LinkedNode<T>*)0)
			{
				nextNode=	nextNode->nextNode;

				return true;
			}
			if(nextNode== (LinkedNode<T>*)0)
				return false;

			return nextNode->removeFromIndex(index-1);
		}
};

template<class T>
class LinkedList
{
	public:
		// Variables
		LinkedNode<T>*	root;

		// Constructors

		LinkedList(T value)
		{
			root=	new LinkedNode<T>(value);
		}
};

class HashEntry
{
	public:
		// Variables
		LinkedList<int>*	key;
		LinkedList<char>*	val;

		// Constructors

		HashEntry(int pmKey, char pmVal)
		{
			key=	new LinkedList<int>(pmKey);
			val=	new LinkedList<char>(pmVal);
		}

		// Methods

		// Adds the given key and value to the bucket list
		void addToBucket(int pmKey, char pmVal)
		{
			key->root->insertToBack(pmKey);
			val->root->insertToBack(pmVal);
		}

		// Gets the value from the bucket using the given key
		char getFromBucket(int pmKey)
		{
			// Variables
			int	index=	key->root->getIndexOf(pmKey);

			if(index== -1)
				return (char)0;

			return val->root->getFromIndex(index);
		}

		// Removes the value and key from the given key out of the bucket
		bool removeFromBucket(int pmKey)
		{
			// Variables
			int	index=	key->root->getFromIndex(pmKey);

			if(index== -1)
				return false;
			
			key->root->removeFromIndex(index);
			val->root->removeFromIndex(index);

			return true;
		}

		// Displays the bucket from the entry
		void display()
		{
			// Variables
			int	full=	key->root->getLastIndex();

			for(int i= 0; i< full; i++)
				cout<< "Key: "<< key->root->getFromIndex(i)<< "; Val: "<< val->root->getFromIndex(i)<< ";\n";
		}
};

class HashTable
{
	private:
		int getHash(int key)
		{
			return key%size;
		}
	public:
		// Variables
		HashEntry	**table;
		int	size;

		// Constructors

		HashTable(int pmSize)
		{
			table=	new HashEntry*[pmSize];
			size=	pmSize;
			for(int i= 0; i< size; i++)
				table[i]=	new HashEntry((size+rand())%size, (rand()%27)+65);
		}
		HashTable()	{	HashTable(256);	}

		// Methods

		// Inserts the given key and value into the hashtable
		void insert(int key, char val)
		{
			// Variables
			int	hash=	getHash(key);

			if(table[hash]== (HashEntry*)0)
				table[hash]=	new HashEntry(key, val);
			else
				table[hash]->addToBucket(key, val);
		}

		// Clears out the entire hashtable
		void clear()
		{
			table=	new HashEntry*[size];
		}

		// Gets the value of the given key
		char get(int key)
		{
			//  Variables
			int	hash=	getHash(key);

			if(table[hash]== (HashEntry*)0)
				return (char)0;
			else
				return table[hash]->getFromBucket(key);
		}

		// Removes the value and key with the given key
		bool remove(int key)
		{
			// Variables
			int	hash=	getHash(key);

			if(table[hash]== (HashEntry*)0)
				return false;
			else
				return table[hash]->removeFromBucket(key);
		}

		// Displays the hash table
		void display()
		{
			for(int i= 0; i< size; i++)
			{
				if(table[i]== (HashEntry*)0)
					cout<< "Entry "<< i<< ": NULL\n";
				else
				{
					cout<< "Entry "<< i<< ":\n";
					table[i]->display();
				}
			}
		}
};

/*
// Starts the app
void main()
{
	// Variables
	int	tsize=	50;
	int	items[2];
	bool	bValMatch;
	HashTable	table;

	srand(time(0));

	table=	HashTable(tsize);

	for(int i= 0; i< tsize*3; i++)
	{
		items[0]=	(tsize+i+rand())%tsize;
		items[1]=	(rand()%27)+65;
		table.insert(items[0], (char)(items[1]));
	}
	
	table.display();

	do
	{
		cout<< "Locate value given the key; type any letters to escape\n> ";
		bValMatch=	(cin>> items[0]);

		if(bValMatch)
			cout<< "Key: "<< items[0]<< ", Val: "<< table.get(items[0])<< ";\n";
	}while(bValMatch);
}*/

// End of File