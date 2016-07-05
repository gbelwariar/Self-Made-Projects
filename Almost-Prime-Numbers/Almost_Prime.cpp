// Program to print first 10 k-primes for 1<=k<=5

#include<stdio.h>
#include<math.h>

// A function to count all prime factors of a given number
int countPrimeFactors(int n)
{
	int count = 0;
    // Count the number of 2s that divide n
    while (n%2 == 0)
    {
        n = n/2;
        count++;
    }

    // n must be odd at this point. So we can skip one
	// element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    { 
        // While i divides n, count i and divide n
        while (n%i == 0)
        {
            n = n/i;
            count++;
        }
    }

    // This condition is to handle the case whien n is a
	// prime number greater than 2
    if (n > 2)
        count++;
   
   return(count);     
}

// A function to print the first 10 k-almost primes
// for a given k
void printKAlmostPrimes(int k)
{
	int i, num;
	printf("First ten %d-almost prime numbers- ", k);
	
	for (i=1, num=2; i<=10; num++)
	{
		if (countPrimeFactors(num) == k)
		{
			printf("%d ", num);
			i++;
		}
	}
	printf("\n");
	
	return;
}


/* Driver program to test above function */
int main()
{
	for (int k=1; k<=5; k++)
		printKAlmostPrimes(k);
   
    return 0;
}
