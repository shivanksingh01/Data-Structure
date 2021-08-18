// floor and ceil of an elent

//    index     0  1  2  3    4   5   6   7   8
// int arr[] = {1, 2, 3, 4,   8, 10, 11, 12, 19};
// key = 5
// floor(5) = greatest elemnt [smaller than or qual to 5]  == 4
// ceil(5) = smaller elemnt [greater than or equal to 5]  == 8
// floor(2) == 2
// ceil(2) == 2
#include <stdio.h>
int findFloor(int arr[], int n, int key)
{
    int low = 0,  high = n - 1;
    int floor = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return arr[mid];
        else if (key > arr[mid])
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else if (key < arr[mid])
            high = mid - 1;
    }
    return floor;
}

int findCeil(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int ceil = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return arr[mid];
        else if (key < arr[mid] )
        {
            ceil = arr[mid];
            high = mid - 1;
        }
        else if (key > arr[mid])
            low = mid + 1;
    }
    return ceil;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(int);
    int key = 8;

    printf("\nsearching :   ...............\n");
    printf("floor of %d : %d\n", key, findFloor(arr, n, key));
    printf("Ceil of %d : %d\n", key, findCeil(arr, n, key));
    return 0;
}