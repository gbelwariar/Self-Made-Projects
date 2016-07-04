/* A C program to implement Sparse Set and its operations */
#include<bits/stdc++.h>
using namespace std;
 
// A structure to hold the three parameters required to
// represent a sparse set.
class SSet
{
    int *sparse;   // To store indexes of actual elements
    int *dense;    // To store actual set elements
    int n;         // Current number of elements
    int capacity;  // Capacity of set or size of dense[]
    int maxValue;  /* Maximum value in set or size of
                     sparse[] */
 
public:
    // Constructor
    SSet(int maxV, int cap)
    {
        sparse = new int[maxV+1];
        dense  = new int[cap];
        capacity = cap;
        maxValue = maxV;
        n = 0;  // No elements initially
    }
 
    // Destructor
    ~SSet()
    {
        delete[] sparse;
        delete[] dense;
    }
 
    // If element is present, returns index of
    // element in dense[]. Else returns -1.
    int search(int x);
 
    // Inserts a new element into set
    void insert(int x);
 
    // Deletes an element
    void deletion(int x);
 
    // Prints contents of set
    void print();
 
    // Removes all elements from set
    void clear() { n = 0; }
 
    // Finds intersection of this set with s
    // and returns pointer to result.
    SSet* intersection(SSet &s);
 
    // A function to find union of two sets
    // Time Complexity-O(n1+n2)
    SSet *setUnion(SSet &s);
};
 
// If x is present in set, then returns index
// of it in dense[], else returns -1.
int SSet::search(int x)
{
    // Searched element must be in range
    if (x > maxValue)
        return -1;
 
    // The first condition verifies that 'x' is
    // within 'n' in this set and the second
    // condition tells us that it is present in
    // the data structure.
    if (sparse[x] < n && dense[sparse[x]] == x)
        return (sparse[x]);
 
    // Not found
    return -1;
}
 
// Inserts a new element into set
void SSet::insert(int x)
{
    //  Corner cases, x must not be out of
    // range, dense[] should not be full and
    // x should not already be present
    if (x > maxValue)
        return;
    if (n >= capacity)
        return;
    if (search(x) != -1)
        return;
 
    // Inserting into array-dense[] at index 'n'.
    dense[n] = x;
 
    // Mapping it to sparse[] array.
    sparse[x] = n;
 
    // Increment count of elements in set
    n++;
}
 
// A function that deletes 'x' if present in this data
// structure, else it does nothing (just returns).
// By deleting 'x', we unset 'x' from this set.
void SSet::deletion(int x)
{
    // If x is not present
    if (search(x) == -1)
        return;
 
    int temp = dense[n-1];  // Take an element from end
    dense[sparse[x]] = temp;  // Overwrite.
    sparse[temp] = sparse[x]; // Overwrite.
 
    // Since one element has been deleted, we
    // decrement 'n' by 1.
    n--;
}
 
// prints contents of set which are also content
// of dense[]
void SSet::print()
{
    for (int i=0; i<n; i++)
        printf("%d ", dense[i]);
    printf("\n");
}
 
// A function to find intersection of two sets
SSet* SSet::intersection(SSet &s)
{
    // Capacity and max value of result set
    int iCap    = min(n, s.n);
    int iMaxVal = max(s.maxValue, maxValue);
 
    // Create result set
    SSet *result = new SSet(iMaxVal, iCap);
 
    // Find the smaller of two sets
    // If this set is smaller
    if (n < s.n)
    {
        // Search every element of this set in 's'.
        // If found, add it to result
        for (int i = 0; i < n; i++)
            if (s.search(dense[i]) != -1)
                result->insert(dense[i]);
    }
    else
    {
        // Search every element of 's' in this set.
        // If found, add it to result
        for (int i = 0; i < s.n; i++)
            if (search(s.dense[i]) != -1)
                result->insert(s.dense[i]);
    }
 
    return result;
}
 
// A function to find union of two sets
// Time Complexity-O(n1+n2)
SSet* SSet::setUnion(SSet &s)
{
    // Find capacity and maximum value for result
    // set.
    int uCap    = s.n + n;
    int uMaxVal = max(s.maxValue, maxValue);
 
    // Create result set
    SSet *result =  new SSet(uMaxVal, uCap);
 
    // Traverse the first set and insert all
    // elements of it in result.
    for (int i = 0; i < n; i++)
        result->insert(dense[i]);
 
    // Traverse the second set and insert all
    // elements of it in result (Note that sparse
    // set doesn't insert an entry if it is already
    // present)
    for (int i = 0; i < s.n; i++)
        result->insert(s.dense[i]);
 
    return result;
}
 
 
// Driver program
int main()
{
    // Create a set set1 with capacity 5 and max
    // value 100
    SSet s1(100, 5);
 
    // Insert elements into the set set1
    s1.insert(5);
    s1.insert(3);
    s1.insert(9);
    s1.insert(10);
 
    // Printing the elements in the data structure.
    printf("The elements in set1 are\n");
    s1.print();
 
    int index = s1.search(3);
 
    //  'index' variable stores the index of the number to
    //  be searched.
    if (index != -1)  // 3 exists
        printf("\n3 is found at index %d in set1\n",index);
    else            // 3 doesn't exist
        printf("\n3 doesn't exists in set1\n");
 
    // Delete 9 and print set1
    s1.deletion(9);
    s1.print();
 
    // Create a set with capacity 6 and max value
    // 1000
    SSet s2(1000, 6);
 
    // Insert elements into the set
    s2.insert(4);
    s2.insert(3);
    s2.insert(7);
    s2.insert(200);
 
    // Printing set 2.
    printf("\nThe elements in set2 are\n");
    s2.print();
 
    // Printing the intersection of the two sets
    SSet *intersect = s2.intersection(s1);
    printf("\nIntersection of set1 and set2\n");
    intersect->print();
 
    // Printing the union of the two sets
    SSet *unionset = s1.setUnion(s2);
    printf("\nUnion of set1 and set2\n");
    unionset->print();
 
    return 0;
}
