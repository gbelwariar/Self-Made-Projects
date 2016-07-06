// A C++ Program to generate test cases for
// an unweighted tree
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 10000

// Define the maximum number of nodes of the tree
#define MAXNODE 100

int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;
	
	freopen ("Test_Cases_Unweighted_Tree.in", "w", stdout);
	
	//For random values every time
	srand(time(NULL));
	
	int NUM;	// Number of Vertices/Nodes
		
	for (int i=1; i<=RUN; i++)
	{
		NUM = 1 + rand() % MAXNODE;
		
		// First print the number of vertices/nodes
		printf("%d\n", NUM);
		
		// Then print the edges of the form (a b)
		// where 'a' is connected to 'b'
		for (int j=1; j<=NUM-1; j++)
		{
			int a = 1 + rand() % NUM;
			int b = 1 + rand() % NUM;
			pair<int, int> p = make_pair(a, b);
			pair<int, int> reverse_p = make_pair(b, a);
			
			// Search for a random "new" edge everytime
			// Note - In a tree the edge (a, b) is same 
			// as the edge (b, a)
			while (container.find(p) != container.end() ||
				container.find(reverse_p) != container.end())
			{
				a = 1 + rand() % NUM;
				b = 1 + rand() % NUM;
				p = make_pair(a, b);
				reverse_p = make_pair(b, a);
			}
			container.insert(p);
		}
			
		for (it=container.begin(); it!=container.end(); ++it)
			printf("%d %d\n", it->first, it->second);
			
		container.clear();
		printf("\n");			
	}
		
	fclose(stdout);
	return(0);
}

