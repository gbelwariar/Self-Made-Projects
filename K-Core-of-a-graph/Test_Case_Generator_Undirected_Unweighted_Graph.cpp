// A C++ Program to generate test cases for
// an unweighted undirected graph
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 20

// Define the maximum number of vertices of the graph
#define MAX_VERTICES 20

// Define the maximum number of edges
#define MAX_EDGES 200

int main()
{
	set<pair<int, int>> container;
	set<pair<int, int>>::iterator it;
	
	freopen ("Test_Cases_Undirected_Unweighted_Graph.in", "w", stdout);
	
	//For random values every time
	srand(time(NULL));
	
	int NUM;	// Number of Vertices
	int NUMEDGE; // Number of Edges
	
	for (int i=1; i<=RUN; i++)
	{
		NUM = 1 + rand() % MAX_VERTICES;
	
		// Define the maximum number of edges of the graph
		// Since the most dense graph can have N*(N-1)/2 edges
		// where N =  nnumber of vertices in the graph
		NUMEDGE = 1 + rand() % MAX_EDGES;
		
		while (NUMEDGE > NUM*(NUM-1)/2)
				NUMEDGE = 1 + rand() % MAX_EDGES;		
		
		// First print the number of vertices and edges
		printf("%d %d\n", NUM, NUMEDGE);
		
		// Then print the edges of the form (a b)
		// where 'a' is connected to 'b'
		for (int j=1; j<=NUMEDGE; j++)
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

