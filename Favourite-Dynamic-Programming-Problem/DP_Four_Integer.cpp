/*
 A C Program to find maximum value 
 of arr[j]–arr[i]+arr[l]–arr[k] is maximum 
 and i < j < k < l, given that
 the array has atleast 4 elements
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// A Function to find maximum of 'x' and 'y'
int maxVal(int x, int y) { return (x > y)? x: y; }

// A Dynamic Programming based function
int findMaxValue(int arr[], int n)
{
	// If the array has less than 4 elements
	if (n < 4)
	{
		printf("The array should have atlest 4 elements\n");
		return(INT_MIN);
	}
	
	// We create 4 DP tables
	int *table1, *table2, *table3, *table4;
	
	table1 = (int *) malloc ((n + 1) * sizeof(int));
	table2 = (int *) malloc ((n + 1) * sizeof(int));
	table3 = (int *) malloc ((n + 1) * sizeof(int));
	table4 = (int *) malloc ((n + 1) * sizeof(int));	
	
	// Initialsing all the tables to INT_MIN
	int i;
	for (i=0; i<=n-1; i++)
		table1[i] = table2[i] = table3[i] = 
		table4[i] =	 INT_MIN;

	for (i=n-1; i>=0; i--) 
		table1[i] = maxVal(table1[i+1], arr[i]);
    
   	for (i=n-1; i>=0; i--)
		 table2[i] = maxVal(table2[i+1],
		 			 table1[i+1] - arr[i]);
    
	for (i=n-1; i>=0; i--) 
		table3[i] = maxVal(table3[i+1],
					 table2[i+1] + arr[i]);
    
	for (i=n-1; i>=0; i--) 
		table4[i] = maxVal(table4[i+1],
					 table3[i+1] - arr[i]);
	
	int max = INT_MIN;
	
	for (i=0; i<=n-1; i++)
		 max = maxVal(max, table4[i]);
	
	// To avoid Memory Leak
	free(table1);	free(table2);
	free(table3);	free(table4);
	
	return (max);
}

// Driver Program to test above functions
int main()
{
	int arr[] = {4, 8, 9, 2, 20};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	printf("%d\n",findMaxValue(arr, n));
	
	return (0);
}

