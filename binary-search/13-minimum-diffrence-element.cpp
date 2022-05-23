// Find minimum diffrence elemnt in an sorted array
// Given an array of integers sorted in ascending order, and a target value
// find the element in the array that has minimum difference with the target value.

// Input :       [ 2,   5,   10,   12,   15 ], target = 8 , output = 10
// explanation : [8-2, 8-5, 10-8, 12-8, 15-8]
//               [ 6,   3,   2,    4,    7]
//  output  : 10  , 10 has min diffrence with the given target

#include<bits/stdc++.h>
using namespace std;

// Approach-1 (optimal)
// if element/target is present in array it will itself give min diffrence
// if element not present in array , one of its two neighbours will give min diffrence

// note : in binary search if key is not present, low and high will point to neighbours of key and high<low
//  at the end of loop we only have to return =  min( abs(arr[low]-key) , abs(arr[high]-key))

int minDiffrence(int arr[], int n, int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==target){
            return arr[mid];
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else if(arr[mid]> target)
            high = mid-1;
    }
    return abs(arr[low]-target)<abs(arr[high]-target)?arr[low]: arr[high];
}

int main(){
    int arr[] = {2,5,10, 12, 15 };
    int n = sizeof(arr)/sizeof(int);
    int target = 13;
    cout<<minDiffrence(arr, n, target)<<endl;
    return 0;
}