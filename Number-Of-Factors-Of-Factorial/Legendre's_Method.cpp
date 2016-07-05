#include <bits/stdc++.h>
using namespace std;
 
// A recursive funtion to find the exponent of the highest
// power of 'p' which is divisible by n!
int findHighestPower(int n, int p)
{
	// Base Case
	if(n==0)
		return 0;
	// Do floor operation and recurse
	return (n/p + findHighestPower(n/p, p));
} 
 
int countDivisorsFactorial(int n)
{
	// We are going to perform a Sieve of Eratosthenes

    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 	
 	int count = 1;
 	
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          	count = count * (findHighestPower(n, p) + 1);
        
	return (count);
}


// Driver Program to test above functions
int main()
{
	int count = countDivisorsFactorial(10);
	printf ("%d", count);
	
	return (0);
}


