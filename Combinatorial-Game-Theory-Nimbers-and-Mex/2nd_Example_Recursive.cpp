/* 
 Game Description-
 A one-pile version of Nim, the game starts with
 a pile of n stones, and the player to move may take any 
 positive number of stones upto 3 only.
 The last player to move wins. Which player wins the game?
 
 A recursive based approach to calculate Grundy Number and 
 Mex
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
int calculateGrundy (int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	if (n == 2)
		return (2);
	if (n == 3)
		return (3);
	
	unordered_set<int> Set; // A Hash Table
	
	for (int i=1; i<=3; i++)
			Set.insert (calculateGrundy (n - i));
	
	return (calculateMex (Set));
}

// Driver program to test above functions
int main()
{
	int n = 5;	
	
	printf ("%d", calculateGrundy (n));
	
	
	
	return (0);
}




