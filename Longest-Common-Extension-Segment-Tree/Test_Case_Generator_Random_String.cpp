// A C++ Program to generate test cases for
// random strings
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 100000

// Define the range of the test data generated
// Here it is 'a' to 'z'
#define MAX 25

// Define the maximum length of string
#define MAXLEN 100

int main()
{
	freopen ("Test_Cases_Random_String.in", "w", stdout);
	
	//For random values every time
	srand(time(NULL));
	
	int LEN;	// Length of string
		
	for (int i=1; i<=RUN; i++)
	{
		LEN = 1 + rand() % MAXLEN;
		
		// First print the length of string
		printf("%d\n", LEN);
		
		// Then print the characters of the string
		for (int j=1; j<=LEN; j++)
			printf("%c", 'a' + rand() % MAX);
		
		printf("\n");			
	}
	
	fclose(stdout);
	return(0);
}


