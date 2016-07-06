// A C++ Program to generate test cases for
// array filled with random numbers
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 10000

// Define the range of the test data generated
#define MAX 10000000

// Define the maximum number of array elements
#define MAXNUM 100

int main()
{
	freopen ("Test_Cases_Random_Array.in", "w", stdout);
	
	//For random values every time
	srand(time(NULL));
	
	int NUM;	// Number of array elements
		
	for (int i=1; i<=RUN; i++)
	{
		NUM = 1 + rand() % MAXNUM;
		
		// First print the number of array elements
		printf("%d\n", NUM);
		
		// Then print the array elements separated by
		// space
		for (int j=1; j<=NUM; j++)
			printf("%d ", rand() % MAX);
		
		printf("\n");			
	}
		
	fclose(stdout);
	return(0);
}
