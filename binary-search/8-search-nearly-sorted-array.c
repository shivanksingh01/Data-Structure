// search an elemnt in nearly sorted array
// nearly sorted array : ith index --> i-1th index , ith index , i+1th index
//        index : 0  1  2  3  4  5  6  7  8
//  input arr[] : 2, 1, 3, 5, 4, 7, 6, 8, 9
// sorted arr[] : 1, 2, 3, 4, 5, 6, 7, 8, 9
//          key : 7
//       output : elemnt found at index : 5
#include<stdio.h>

int searchNearlySortedArr(int arr[], int n, int key){
    int low = 0, high = n-1;
    while (low<=high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if (arr[mid-1] == key  &&  mid-1>=low)
            return mid-1;
        else if (arr[mid+1] == key && mid+1<=high)
            return mid+1;

        else if(key > arr[mid])  // reduce search space to right sub array
            low = mid+2;
        else     // else if(key < arr[mid])
            high = mid-2;    // reduce search space to left sub array
    }
        return -1; // invalid input
}

int main(){
    int arr[] = {2, 1, 3, 5, 4, 7, 6, 8, 9};
            //  {1, 2, 3, 4, 5, 6, 7, 8, 9}
    int n = sizeof(arr)/sizeof(int);
    int key = 7;

    int index = searchNearlySortedArr(arr, n, key);

    if (index != -1) {
        printf("Element %d found at index : %d",key, index);
    }
    else {
        printf("Element not found in the array");
    }
}
