/* C++ program to count number of sub-arrays
with even sum using an efficient algorithm
Time Complexity - O(N)
Space Complexity - O(1)*/
#include<iostream>
using namespace std;

int countEvenSum(int arr[], int n)
{
    // A temporary array of size 2. temp[0] is
    // going to store count of even subarrays
    // and temp[1] count of odd.
    // temp[0] is initialized as 1 because there
    // a single even element is also counted as
    // a subarray
    int temp[2] = {1, 0};

    // Initialize count.  sum is sum of elements
    // under modulo 2 and ending with arr[i].
    int result = 0, sum = 0;

    // i'th iteration computes sum of arr[0..i]
    // under modulo 2 and increments even/odd count
    // according to sum's value
    for (int i=0; i<=n-1; i++)
    {
        // 2 is added to handle negative numbers
        sum = ( (sum + arr[i]) % 2 + 2) % 2;

        // Increment even/odd count
        temp[sum]++;
    }

    // Use handshake lemma to count even subarrays
    // (Note that an even cam be formed by two even
    // or two odd)
    result = result + (temp[0]*(temp[0]-1)/2);
    result = result + (temp[1]*(temp[1]-1)/2);

    return (result);
}

// Driver code
int main()
{
    int arr[] = {1, 2, 2, 3, 4, 1};
    int n = sizeof (arr) / sizeof (arr[0]);

    cout << "The Number of Subarrays with even"
            " sum is " << countEvenSum (arr, n);

    return (0);
}
