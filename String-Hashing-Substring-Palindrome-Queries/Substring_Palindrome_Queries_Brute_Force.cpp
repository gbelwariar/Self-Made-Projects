/*
 A C++ program to answer queries to
 check whether the substrings are palindrome
 or not using brute force
*/

#include<bits/stdc++.h>
using namespace std;

// Structure to represent a query
// A query consists of (L,R) and we have
// to answer whether the substring from
// index-L to R is a palindrome or not
struct Query
{
	int L, R;
};

// A Function to answer the Queries
void queryResults(string str, Query q[], int m, int n)
{
	bool isPalindrome;
	int i, j, k;
	
	for (i=0; i<=m-1; i++)
	{
		int L = q[i].L;
		int R = q[i].R;
		
		isPalindrome = true;
		for (j=L, k=R; j<k; j++,k--)
		{
			if (str[j]!=str[k])
				{
					isPalindrome = false;
					break;
				}				
		}
		
		if (isPalindrome)
			printf("The Substring [%d %d] is a "
					"palindrome\n", L, R); 
		else
			printf("The Substring [%d %d] is not a "
					"palindrome\n", L, R);
		
	}
	return;
}

/* Driver program to test above function */
int main()
{
	string str = "abaaabaaaba";
	int n = str.length();
	
	Query q[] = {{0, 10}, {5, 8}, {2, 5}, {5, 9}};
	int m = sizeof(q)/sizeof(q[0]);
	
	queryResults(str, q, m, n);
	return (0);
}


