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

	// Note that this loop runs till square root
    for (int i=1; i<=sqrt(num)+1; i++)
    {
        if (num%i==0)
        {
            // If divisors are equal, count only one
            if (num/i == i)
               count++;
 
            else // Otherwise count both
               count = count + 2;
        }
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




