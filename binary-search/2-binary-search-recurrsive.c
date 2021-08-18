//  binary search --> on sorted array   takes log(n) operations
// ex - telephone dircetory
// index  :  0, 1, 2, 3, 4, 5, 6, 7, 8
// input arr[] : 2, 3, 4, 8, 12, 15, 19, 20
//          k  : 8
//      output : 8 is present at position : 4    (index : 3)

#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            return mid + 1;
        }
        else if (key < arr[mid])
            return binarySearchRecursive(arr, low, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, high, key);
    }
    return -1;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 2, 5, 6, 8, 9, 10, 15, 19, 25};
    int n = sizeof(arr) / sizeof(int);
    display(arr, n);
    int key = 12;
    printf("\nsearching : %d   ...............\n", key);
    int result = binarySearchRecursive(arr, 0, n - 1, key);
    (result == -1) ? printf("%d is not present in array \n", key)
                   : printf("%d is present at index :  %d\n",key, result);
}
