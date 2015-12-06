// Created by Paul Gonzalez Becerra

using System;

public static class MathExt
{
	// Static Methods
	
	public static void Main(string[] args)
	{
		// Variables
		string	line=	"";
		int	n=	0;
		
		while(true)
		{
			Console.Write("Please enter a number to factorial; Type \"exit\" to exit\n> ");
			line=	Console.ReadLine();
			if(line.ToLower()== "exit")
				break;
			if(int.TryParse(line, out n))
			{
				Console.WriteLine(n+"! = "+factorial(n));
			}
		}
	}
	
	// Does a factorial on the given integer; n!
	public static double factorial(int n)
	{
		if(n< 0)
			return -1.0*factorial(-1*n);
		if(n== 0)
			return 1.0;
		if(n== 170)
			throw new Exception("Out of bounds, number becomes too large");
		
		return (double)n*factorial(n-1);
	}
}

// End of File