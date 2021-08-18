// how many times is a sorted array rotated
//  index  - 0   1   2   3   4   5   6   7
// org arr - 2   5   6   8   11  12  15  18   --> rotation = 0
// rot arr - 11  12  15  18  2   5   6   8  --> rotation = 4

// [no. of rotation = index of min. elemnt]
//  [4 rotation = index of 2 (i.e. 4)]
// min. elemnt  is the only elemnt that will always be samller than both of its neighbour(left and right)
//  ex - 2 is smaller than 18 and 5 (in rot arr)
// min. Elemnt  always  found in unsorted part of arr
#include<stdio.h>
int countArrayRotation(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        if (arr[low]<=arr[high]){   // array is already sorted
            return low;
        }
        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;        // left neighbour
        int prev = (mid + n - 1) % n;    // right neighbour

        if (arr[mid] <= arr[next] & arr[mid]<= arr[prev])     // if mid is less than both of its neighbour it is the min elemnt
            return mid;
        else if (arr[low] <= arr[mid])
            low = mid + 1;
        else if (arr[mid] <= arr[high])
            high = mid - 1;
    }
    return -1;    //invalid input 
}

int main()
{   // no. of rotations = index of smallest element = 5 (index of 1)
    // index :   0  1  2  3  4  5  6  7  8
    int arr[] = {5, 6, 7, 8, 9, 1, 2, 3, 4};   
 // org arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    printf("finding number of rotations..............\n");
    printf("number of rotation : %d\n", countArrayRotation(arr, n));
}