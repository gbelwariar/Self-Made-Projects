// A C Program to implement Odd-Even / Brick Sort

#include<stdio.h>
#include<stdbool.h>

// A function to swap the array elements
// at the index - 'i' and 'j'
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return;
}

// A utility function ot print an array of size n
void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}
  
// A function to sort the algorithm using Odd Even sort
void OddEvenSort(int arr[], int n)
{
	bool isSorted = false; // Initially array is unsorted
	int i;
	
	while (!isSorted)
	{
		isSorted = true;
	
		// Perform Bubble sort on odd indexed element
		for (i=1; i<=n-2; i=i+2)
		{
			if (arr[i] > arr[i+1])
     		{
        		swap(arr, i, i+1);
        		isSorted = false;
      		}
		}
	
		// Perform Bubble sort on even indexed element
		for (i=0; i<=n-2; i=i+2)
		{
			if (arr[i] > arr[i+1])
     		{
        		swap(arr, i, i+1);
        		isSorted = false;
      		}
		}
	}

	return;
}

// Driver program to test above functions.
int main()
{
	int arr[] = {34, 2, 10, -9};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	OddEvenSort(arr, n);
	printArray(arr, n);
	
	return (0);
}





