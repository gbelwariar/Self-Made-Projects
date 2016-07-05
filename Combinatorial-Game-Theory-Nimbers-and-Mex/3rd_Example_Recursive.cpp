/* 
 Game Description-
 The game starts with a number- 'n' and the player to move
 divides the number- 'n' with the primes- 2, 3, 6 and then 
 takes the floor. If the integer becomes 0, it is removed. 
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
	
	unordered_set<int> Set; // A Hash Table
	
	Set.insert (calculateGrundy (n/2));
	Set.insert (calculateGrundy (n/3));
	Set.insert (calculateGrundy (n/6));
	
	return (calculateMex (Set));
}

// Driver program to test above functions
int main()
{
	int n = 25;	
	
	printf ("%d", calculateGrundy (n));
	
	return (0);
}

