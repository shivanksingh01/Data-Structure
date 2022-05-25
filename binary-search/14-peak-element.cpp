// Find the peak element in an unsorted array
// The peak element in an array is an array element which is not smaller than it's neighbours.
// For example, 1. arr[] = {6,7,10,12,9}    peak elemnt = 12
//              2. {8,15,9,2,23,5}   two peak elements: 15 and 23.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// traverse array and check for consecutive elements in array
// Time Complexity = O(n)
// int peakElement(int arr[], int n){
//     if(n==1){
//         return arr[0]; // if there is only one elemnent in array, return that element
//     }
//     if (arr[0] >= arr[1]){
//         return arr[0];
//     }
//     if(arr[n-1]>=arr[n-2]){
//         return arr[n-1];
//     }
//     // finding the remianing peak elemnts
//     // compare current elemenet with its neighbour
//     for(int i=1; i<n-1; i++){
//         if(arr[i]>= arr[i-1] and arr[i]>=arr[i+1]){
//             return arr[i];
//         }
//     }
//     return arr[0];
// }

// Apporach-2 (Uisng Binary Search)
// Time complexity =O(logn)
int peakElement(int arr[], int n){
    int low=0;
    int high=n-1;
    if(low==high){
        return arr[low]; // if array has only one elemnt, i.e. low and high points to same index
    }
    // else if(low+1 == high){
    //     if(arr[low]<arr[high])
    //         return arr[high];
    //     else
    //         return arr[low];
    // }

    //  check for extreme conditions , (extreme low and extreme high), we have only one element to check with
    else if(arr[0]> arr[1]){
        return arr[0];
    }
    else if(arr[n-1]>arr[n-2]){
        return arr[n-1];
    }
    // using binary search concept
    // arr[mid] should be greater than both of its neigbour i.e. arr[mid-1], arr[mid+1]
    // if so , return arr[mid]
    // else, reduce the search space -> continue the search toward the greater element
    // it can be the candidate
    else{
        while (low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]>arr[mid-1] and arr[mid]> arr[mid+1]){
               return arr[mid];
            }
            else if (arr[mid - 1] < arr[mid])
                low = mid+1;
            else if(arr[mid+1] < arr[mid])
                high=mid-1;
            }
        }
}


// Approach-2 (Using STL)

// int peakElement(vector<int> &arr){
//     if(arr.size()==0){
//         exit(-1);
//     }
//     auto peak = adjacent_find(arr.begin(), arr.end(), greater<int>());
//     if(peak==arr.end()){
//         --peak;
//     }
//     return *peak;
// }

int main(){
    // int arr[] = {4, 5};  // 12 is peak element
    int arr[] = {18,15,9,2,23,5};
    int n = sizeof(arr) / sizeof(int);
    cout<<peakElement(arr, n);

    // vector<int> arr = {6, 8, 9, 14, 10, 12};
    // cout<<peakElement(arr);
    return 0;
}