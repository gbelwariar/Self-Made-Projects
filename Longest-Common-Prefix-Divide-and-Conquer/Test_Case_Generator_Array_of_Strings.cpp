// A C++ Program to generate test cases for
// random strings
#include<bits/stdc++.h>
using namespace std;

// Define the number of runs for the test data
// generated
#define RUN 1000

// Define the range of the test data generated
// Here it is 'a' to 'z'
#define MAX 25

// Define the range of number of strings in the array
#define MAXNUM 20

// Define the maximum length of string
#define MAXLEN 20

int main()
{
	freopen ("Test_Cases_Array_of_Strings.in", "w", stdout);
	
	//For random values every time
	srand(time(NULL));
	
	int NUM; // Number of strings in array
	
	int LEN;	// Length of string
		
	for (int i=1; i<=RUN; i++)
	{
		NUM = 1 + rand() % MAXNUM;
		printf("%d\n", NUM);
		
		for (int k=1; k<=NUM; k++)
		{
			LEN = 1 + rand() % MAXLEN;
			
			// Then print the characters of the string
			for (int j=1; j<=LEN; j++)
				printf("%c", 'a' + rand() % MAX);
				
			printf(" ");	
		}	
		printf("\n");			
	}
	
	fclose(stdout);
	return(0);
}

