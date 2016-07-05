// A C program to calculate the number of divisors
// of a factorial of a number

#include<stdio.h>
#include<math.h>

// A Utility function to calculate the factorial of 
// any number
int fact (int n)
{
	if (n==0 || n==1)
		return (1);
	return (n*fact(n-1));
}

// A function to calculate the number of divisors of 
// factorial of a number
int countDivisorsFactorial(int n)
{
	int i, count = 0;
	int num = fact(n);
	
	for (i=1; i<=num; i++)
	{
		if (num%i == 0)
			count++;
	}
			
	return (count);
}

// Driver Program to test above functions
int main()
{
	int count = countDivisorsFactorial(10);
	printf ("%d", count);
	
	return (0);
}


