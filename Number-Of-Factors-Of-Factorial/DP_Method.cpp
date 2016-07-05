// A C program to calculate the number of divisors
// of a factorial of a number

#include<stdio.h>
#include<math.h>
#include<string.h>

// A function to calculate the number of divisors of 
// factorial of a number
int countDivisorsFactorial(int n)
{
	int i, j, count = 1, num, index;

	// A 2D DP table to store the counts of all the
	// primes 
	int table[n+1][n+1] ;
	memset (table, 0, sizeof(table));
 
 	// We want to calculate the total number
 	// of primes (not distinct) of n!. 
 	// We use the below recurrence relation-
 	// count_primes_divisors (n!) = count_primes_divisors(n) + count_primes_divisors((n-1)!)
 	for (j=2; j<=n; j++)
	{
		// This is just like copying the counts of all the primes
		// from (n-1)!
		for (i=1; i<=n; i++)
				table[i][j]=table[i][j-1];
			
		// Update the DP Table to add extra primes due to 'n'
		index = num = j;
		// Update the table with the number of 2s that divide n
    	while (num%2 == 0)
    	{
    		table[2][index]++;
        	num = num/2;
    	}
 
    	// n must be odd at this point.  So we can skip one element (Note i = i +2)
    	for (int i = 3; i*i <=num; i = i+2) 
    	{
        	// While i divides n, update the table with the
			// number of i's that divide n
        	while (num%i == 0)
       		{
        		table[i][index]++;
		   	 	num = num/i;
        	}
    	}
 
   		// This condition is to handle the case whien n is a prime number
    	// greater than 2
    	if (num > 2)
			table[num][index]++;
	}
			
	for (i=1; i<=n; i++)
		count = count * (table[i][n] + 1);
				
	return (count);
}

// Driver Program to test above functions
int main()
{
	int count = countDivisorsFactorial(10);
	printf ("%d", count);
	
	return (0);
}

