// Created by Paul Gonzalez Becerra

#include<iostream>
#include<stdio.h>
#include<ctime>

using namespace std;

// Methods

// Copies the gvien arrays over given the domain [a, c]
void copy(int* items[], int* temp[], int a, int c)
{
	for(int i= a; i< c; i++)
		items[i]=	temp[i];
}

// Merges together the split up pieces
void merge(int* items[], int* temp[], int a, int b, int c)
{
	// Variables
	int	h=	a;
	int	k=	b;

	for(int i= a; i< c; i++)
	{
		if(h< b && (k>= c || *items[h]<= *items[k]))
			*temp[i]=	*items[h++];
		else
			*temp[i]=	*items[k++];
	}
}

// Splits apart the array
void splitMerge(int* items[], int* temp[], int a, int c)
{
	if(c-a< 2)
		return;

	// Variables
	int	b=	(a, c)/2;

	splitMerge(items, temp, a, b); // Left half
	splitMerge(items, temp, b, c); // Right half
	merge(items, temp, a, b, c);
	copy(items, temp, a, c);
}

// Starts the merge sort
void mergeSort(int* items[], int* temp[], int size)
{
	splitMerge(items, temp, 0, size);
}

void main()
{
	// Variables
	int	**items=	new int*[20];
	int	**temp=	new int*[20];

	srand(time(0));

	cout<< "Original array: ";
	for(int i= 0; i< 20; i++)
	{
		items[i]=	(int*)(rand()%200);
		if(i== 19)
			cout<< &items[i]<< "\n";
		else
			cout<< items[i]<< ", ";
	}

	cout<< "Sorted array: ";
	mergeSort(items, temp, 20);
	for(int i= 0; i< 20; i++)
	{
		if(i== 19)
			cout<< items[i]<< "\n";
		else
			cout<< items[i]<< ", ";
	}
}

// End of File