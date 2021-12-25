// Sort an array of 0’s, 1’s, and 2’s  (segregate 0 , 1 and 2)

// Input:  { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 }
// Output: { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2 }
#include <iostream>
#include<bits/stdc++.h>
using namespace std;



// We can rearrange the array in a single traversal using an alternative linear-time partition routine that separates the values into three groups:
// The values less than the pivot,   //
// The values equal to the pivot, and
// The values greater than the pivot.
void threeWayPartition(int arr[], int n){
    int high=n-1;
    int low = 0, mid = 0;
    int pivot = 1;
    while (mid <= high){
        if (arr[mid] < pivot){         // current element is 0
            swap(low, mid);
            ++low, ++mid;
        }
        else if (arr[mid] > pivot){    // current element is 2
            swap(mid, high);
            --high;
        }
        else {                      // current element is 1
            ++mid;
        }
    }
}

// Dutch national flag algorithm  / Three way partition
// take 3 pointers low = 0, mid =0, high = n-1
// traverse through mid ...if (arr[mid]==0) -> swap with low  {mid++, low++}
//                         if (arr[mid]==1) -> mid++        // (do nothing )
//                         if (arr[mid]==2) -> swap with high  { high--}
void segregate(int arr[], int n){
    int low = 0, mid = 0;
    int high = n-1;
    while(mid<=high){
        switch(arr[mid]){   // can use if statement
            case 0: swap(arr[low++], arr[mid++]);
            break;
            case 1: mid++;
            break;
            case 2: swap(arr[mid], arr[high--]);
            break;
        }
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};    
    int n = sizeof(arr)/sizeof(int);
    display(arr, n);
    segregate(arr, n);
    display(arr,n);

    return 0;
}
// https://www.youtube.com/watch?v=sEQk8xgjx64
// https://www.youtube.com/watch?v=oaVa-9wmpns&t=105s
