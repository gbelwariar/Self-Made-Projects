/*	A C++ Program to find the maximum area sub-matrix
	that has only 1's. This sub-matrix can be a square
	as well as a rectangle

	For example-	0, 1, 1, 0, 1 
                   	1, 1, 0, 1, 0 
                   	0, 1, 1, 1, 0
                   	1, 1, 1, 1, 1
                   	1, 1, 1, 1, 1
                   	0, 0, 0, 0, 0
                   	
    In the above matrix, the maximum area square-matrix 
	with all 1's is-
					1, 1, 1
                   	1, 1, 1
                   	1, 1, 1
	which has an area of 9 sq.unit
	
	whereas the maximum sub-matrix with all 1's is-  
					1, 1, 1, 1, 1
                   	1, 1, 1, 1, 1
	which is indeed a rectangle and has an area of 10 sq
	unit 
*/

#define R 6
#define C 5

#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

// Function to find the maximum rectangular area under given
// histogram with n bars
// For more details go to the below link-
// http://www.geeksforgeeks.org/largest-rectangle-under-histogram/
int getMaxArea(int hist[], int n)
{
    // Create an empty stack. The stack holds indexes of hist[] array
    // The bars stored in stack are always in increasing order of their
    // heights.
    stack<int> s;
 
    int max_area = 0; // Initalize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        // If this bar is lower than top of stack, then calculate area of rectangle 
        // with stack top as the smallest (or minimum height) bar. 'i' is 
        // 'right index' for the top and element before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate area with every
    // popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}
 
 
int printMaxSubMatrix(bool M[R][C])  
{  
    int i, j;  
    int Aux[R][C];
    
//	Create Auxilary matrix
//	This involves Dynamic Programming having 
//	recurrence relation-
//	Aux[i][j] = Aux[i-1][j] + 1; if(Aux[i][j] == 1)  
//	Firstly initialise the auxiliary matrix equal to
//	the input matrix
 	for (i=0; i<R; i++)  
        for(j=0; j<C; j++)  
    		Aux[i][j]=M[i][j];
    		
	 for (i=1; i<R; i++)  
        for(j=0; j<C; j++)  
         {  
             if(Aux[i][j] == 1)  
                 Aux[i][j] = Aux[i-1][j] + 1;  
         }  

/*	For example the auxiliary matrix of the input matrix
	will be->
	
	M[R][C]->		0, 1, 1, 0, 1 
                   	1, 1, 0, 1, 0 
                   	0, 1, 1, 1, 0
                   	1, 1, 1, 1, 1
                   	1, 1, 1, 1, 1
                   	0, 0, 0, 0, 0
                   	
	Aux[R][C]->		0, 1, 1, 0, 1 
                   	1, 2, 0, 1, 0 
                   	0, 3, 1, 2, 0
                   	1, 4, 2, 3, 1
                   	2, 5, 3, 4, 2
                   	0, 0, 0, 0, 0
*/
  
  	  int current_area, max_area;  
  	  max_area = 0;  
  
     //	Calculate maximum histogram area in the auxiliary
	 // matrix for each row and find the maximum of them
     for (i=0; i<R; i++)  
     {       
         current_area = getMaxArea(Aux[i], C);  
         if (current_area > max_area)  
             max_area = current_area;  
     }  

     return max_area;  
}  


/* Driver function to test above functions */
int main()
{
	
  bool M[R][C] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
                
  cout<< printMaxSubMatrix(M);
  
  return(0); 
}  
 
 


