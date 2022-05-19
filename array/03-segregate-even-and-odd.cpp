// segregate even and odd numbers
// Input  = {12, 34, 45, 9, 8, 90, 3}
// Output = {12, 34, 90, 8, 9, 45, 3}

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// approach-1 (Dutch-flag-algorithm)
// 1)Initialize two index variables left and right:
//             low = 0,  high = size -1
// 2) Keep incrementing left index (i.e. low) until we see an odd number.
// 3) Keep decrementing right index until we see an even number.
// 4) If left < right then swap arr[left] and arr[right]
// TIme complexity :   T(n) = O(n)

// void segregateEvenOdd(int arr[], int n){
//     int low=0, high=n-1;
//     while(low<high){
//         while(arr[low]%2 != 1 && low<high)   // search for odd from left
//             low++;
//         while(arr[high]%2 != 0 && low<high)  // search for even from right
//             high--;
//         // swap both variables
//         if(low<high){
//             int temp=arr[low];
//             arr[low]= arr[high];
//             arr[high]= temp;
//         }
//     }
// }

// approach-2 (Lomuto-partition based scheme)  -> Quick sort based
// Time complexity :   T(n) = O(n)
//      if found odd do nothing
//      if even :: increment j
//                 swap(i,j)

void segregateEvenOdd (int arr[], int n){
    int j = -1;  // keep track of last even no. in partially segregated array
    for(int i=0;i<n;i++){
        if(arr[i]%2 == 0){
            j++;
            // swap(arr[i], arr[j]);
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]= temp;
        }
    }

}


void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int n = sizeof(arr)/sizeof(int);
    display(arr, n);
    segregateEvenOdd(arr, n);
    display(arr,n);

    return 0;
}
