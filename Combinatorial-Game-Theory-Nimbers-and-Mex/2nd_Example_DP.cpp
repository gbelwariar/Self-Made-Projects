/* 
 Game Description-
 Just like a one-pile version of Nim, the game starts with
 a pile of n stones, and the player to move may take any 
 positive number of stones.
 The last player to move wins. Which player wins the game?
 
 A Dynamic Programming (Memoization-based) approach to 
 calculate Grundy Number and Mex
*/
#include<bits/stdc++.h>
using namespace std;

// A Function to calculate Mex of all the values in that set
// This function remains same 
int calculateMex (unordered_set<int> Set)
{
	int Mex = 0;
	
	while (Set.find (Mex) != Set.end())
		Mex++;
	
	return (Mex);
}

// A function to Compute Grundy Number of 'n'
// Only this function varies according to the game
int calculateGrundy (int n, int Grundy[])
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (3);

	
	if (Grundy[n] != -1)
		return (Grundy[n]);
	
	unordered_set<int> Set; // A Hash Table
	
	for (int i=1; i<=3; i++)
			Set.insert (calculateGrundy (n-i, Grundy));
	
	// Store the result
	Grundy[n] = calculateMex (Set);
	
	return (Grundy[n]);
}

// Driver program to test above functions
int main()
{
	int n = 3;	
	
	// An array to cache the sub-problems so that
	// re-computation of same sub-problems is avoided
	int Grundy [n+1];
	memset (Grundy, -1, sizeof (Grundy));
	
	printf ("%d", calculateGrundy (n, Grundy));
	
	return (0);
}

