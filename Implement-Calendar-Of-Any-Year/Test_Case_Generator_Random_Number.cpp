// A C++ Program to generate test cases for
// random number
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 100000

// Define the range of the test data generated
#define MAX 10000000

int main()
{
	freopen ("Test_Cases.in", "w", stdout);
	
	//For random values every time
	srand(time(NULL));
	
	for (int i=1; i<=RUN; i++)
		printf("%d\n", rand() % MAX);	
	
	fclose(stdout);
	return(0);
}
