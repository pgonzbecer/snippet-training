// Created by Paul Gonzalez Becerra

#include<iostream>
#include<time.h>

using namespace std;

// Variables
const int TABLE_SIZE=	128;

// Classes

class HashEntry
{
	private:
		// Variables
		int	key;
		int	value;
	public:
		// Constructors
		HashEntry(int pmKey, int pmValue)
		{
			key=	pmKey;
			value=	pmValue;
		}

		// Methods

		// Gets the key of the hash entry
		int	getKey()
		{
			return key;
		}

		// Gets the value of the hash entry
		int getValue()
		{
			return value;
		}
};

class HashTable
{
	private:
		// Variables
		HashEntry	**table;
		int	size;
	public:
		// Constructors
		HashTable()
		{
			table=	new HashEntry*[TABLE_SIZE];
			size=	TABLE_SIZE;
		}
		HashTable(int pmSize)
		{
			table=	new HashEntry*[pmSize];
			size=	pmSize;
		}
		~HashTable()
		{
			for(int i= 0; i< size; i++)
			{
				if(table[i]!= nullptr)
					delete table[i];

				delete[] table;
			}
		}

		// Methods

		// Gets the value of the given key
		int get(int key)
		{
			// Variables
			int	hash=	key%size;

			while(table[hash]!= nullptr && (*table[hash]).getKey()!=key)
			{
				hash=	(hash+1)%size;
			}
			if(table[hash]== nullptr)
				return -1;
			else
				return (*table[hash]).getValue();
		}

		// Adds the given key and value pair into the hash table
		void add(int key, int value)
		{
			// Variables
			int	hash=	key%size;
			
			if(table[hash]== nullptr)
				cout<< "YES";
			while(table[hash]!= nullptr && (*table[hash]).getKey()!= key)
			{
				hash=	(hash+1)%size;
			}
			if(table[hash]!= nullptr)
				delete table[hash];
			table[hash]=	new HashEntry(key, value);
		}
};

/*
// Main for the HashTable
void main()
{
	// Variables
	int	tsize=	200;
	int	items[2];
	bool	bValMatch;
	HashTable	table=	HashTable(tsize);

	srand(time(0));

	for(int i= 0; i< tsize; i++)
	{
		items[0]=	(i+rand())%tsize;
		items[1]=	(rand())%tsize;
		cout<< "Key: "<< items[0]<< "; Val: "<< items[1]<< "\n";
		table.add(items[0], items[1]);
	}

	do
	{
		cout<< "Locate value given the key; type any letters to escape\n> ";
		bValMatch=	(cin>> items[0]);

		if(bValMatch)
			cout<< "Key: "<< items[0]<< ", Val: "<< table.get(items[0])<< "\n";
	}while(bValMatch);
}*/

// End of File