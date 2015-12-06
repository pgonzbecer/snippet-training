// Created by Paul Gonzalez Becerra

#include<iostream>

using namespace std;

// Variables
int	size;
char **items;

// Methods

// Gets the index of the given value
int getIndexOf(char * value)
{
	for(int i= 0; i< size; i++)
	{
		if(value== items[i])
			return i;
	}

	return -1;
}

// Removes all the duplicates of the given value
void removeDuplicatesOf(char * value, int index)
{
	for(int i= size-1; i>= 0; i--)
	{
		if(i== index)
			continue;
		if(value== items[i])
			items[i]=	(char*)0;
	}
}
void removeDuplicatesOf(char * value)	{	removeDuplicatesOf(value, getIndexOf(value));	}

// Removes any and all duplicates
void removeAllDuplicates()
{
	// Variables
	int	i=	0;

	while(i< size)
	{
		if(items[i]!= (char*)0)
			removeDuplicatesOf(items[i], i);
		i++;
	}
}

// Starts the app
void main(int argc, char * args[])
{
	size=	argc;
	items=	args;

	cout<< "Original array: ";
	for(int i= 0; i< size; i++)
	{
		if(i== size-1)
			cout<< items[i]<< endl;
		else
			cout<< items[i]<< ", ";
	}
	cout<< "Non-duplicate array: ";
	removeAllDuplicates();
	for(int i= 0; i< size; i++)
	{
		if(i== size-1)
			cout<< items[i]<< endl;
		else
			cout<< items[i]<< ", ";
	}
}

// End of File