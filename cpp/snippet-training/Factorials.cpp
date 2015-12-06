// Created by Paul Gonzalez Becerra

#include<iostream>

using namespace std;

// Methods

// Gets a factorial of the given integer; n!
double factorial(int n)
{
	if(n< 0)
		return -1.0*factorial(-1*n);
	if(n> 170)
		throw "Factorial is too large to compute";
	if(n== 0)
		return 1.0;

	return (double)n*factorial(n-1);
}

// The start of the app for the factorial
void main()
{
	// Variables
	int	n=	0;

	while(true)
	{
		cout<< "Please type in a number to factorial\n> ";
		if(!(cin>> n))
			break;

		try
		{
			cout<< n<< "! = "<< factorial(n)<< "\n";
		}
		catch(...)
		{
			cout<< "Factorial is too large\n";
		}
	}
}

// End of File