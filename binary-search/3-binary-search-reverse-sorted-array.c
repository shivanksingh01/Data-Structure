// binary search on reverse sorted array  (descending)
//        index :  0     1    2    3    4    5    6    7    8    9
//  input arr[] :  100   90   80   70   60   50   40   30   20   10
//          key :  70
//       output : 70 is present at position : 4

#include <stdio.h>
void binarySearchReverse(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int found = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (key == arr[mid])
        {
            found = 1;
            printf("%d found at position : %d\n", key, mid + 1);
            break;
        }
        //  only these conditions changes in compare with normal sorted array
        else if (key <= arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (low > high && found == 0)
        printf("%d not found \n ", key);
}


int main()
{
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(arr) / sizeof(int);
    int key = 70;

    printf("\nsearching : %d   ...............\n", key);
    binarySearchReverse(arr, n, key);
}