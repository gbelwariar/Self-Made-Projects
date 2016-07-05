// A C++ Program to find the length of longest common
// extension using Naive Method

#include<bits/stdc++.h>
using namespace std;

// Structure to represent a query of form (L,R) 
struct Query
{
    int L, R;
};

// A utility function to find longest common extension
// from index - L and index - R
int LCE(string str, int n, int L, int R)
{
	int length = 0;
	
	while (str[L+length] == str[R+length] && 
			R+length < n)
		length++;
	
	return(length);
}

// A function to answer queries of longest common extension
void LCEQueries(string str, int n, Query q[],
							 int m)
{
	for (int i=0; i<m; i++)
	{
		int L = q[i].L;
		int R = q[i].R;
		
		printf("LCE (%d, %d) = %d\n", L, R, LCE(str, n, L, R));				
	}	

	return;
}

// Driver Program to test above functions
int main()
{
	string str = "abbababba";
	int n = str.length();
	
	// LCA Queries to answer
	Query q[] = {{1, 2}, {1, 6}, {0, 5}};
	int m = sizeof(q)/sizeof(q[0]);
	
	LCEQueries(str, n, q, m);
	
	return (0);	
}


