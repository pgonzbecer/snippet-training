// Created by Paul Gonzalez Becerra

import	java.lang.Exception;
import	java.util.Scanner;

public class Factorials
{
	// Static Methods
	
	// Gets the factorial of the given number; n!
	public static double factorial(int n) throws Exception
	{
		if(n> 170)
			throw new Exception("Factorials too large");
		if(n< 0)
			return -1.0*factorial(-1*n);
		if(n== 0)
			return 1.0;
		
		return (double)n*factorial(n-1);
	}
	
	// Starts up the app
	public static void main(String[] args)
	{
		// Variables
		Scanner	reader=	new Scanner(System.in);
		String	line=	"";
		int	n=	0;
		
		try
		{
			while(true)
			{
				System.out.print("Please type in an integer to factorial; Type \"exit\" to exit.\n> ");
				line=	reader.nextLine();
				if(line.toLowerCase()== "exit")
					break;
				n=	Integer.parseInt(line);
				System.out.println(n+"! = "+factorial(n));
			}
		}catch(Exception e){System.out.println("Factorial too large");}
	}
}

// End of File