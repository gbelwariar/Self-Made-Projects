// A C++ Program to generate test cases for
// matrix filled with random numbers
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 100

// Define the range of the test data generated
#define MAX 10000000

// Define the maximum rows in matrix
#define MAXROW 100

// Define the maximum columns in matrix
#define MAXCOL 100

int main()
{
	freopen ("Test_Cases_Random_Matrix.in", "w", stdout);
	
	//For random values every time
	srand(time(NULL));
	int row;	// Number of rows
	int col; 	// Number of columns
	
	for (int i=1; i<=RUN; i++)
	{
		row = 1 + rand() % MAXROW;
		col = 1 + rand() % MAXCOL;
		
		// First print the number of rows and columns
		printf("%d %d\n", row, col);
		
		// Then print the matrix
		for (int j=1; j<=row; j++)
		{
			for (int k=1; k<=col; k++)
				printf("%d ", rand() % MAX);			
			printf("\n");
		}
		printf("\n");			
	}
	fclose(stdout);
	return(0);
}

