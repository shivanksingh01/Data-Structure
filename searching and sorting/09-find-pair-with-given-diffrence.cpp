// Find Pair Given Difference 
// Given an array --> Arr[] of size --> L and a number --> N, 
// find if there exists a pair of elements in the array whose difference is N.

// Input: L = 6, N = 78
//        arr[] = {5, 20, 3, 2, 5, 80}
// Output: 1
// Explanation: (2, 80) have difference of 78.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// bool findPairWithDiffrence(int arr[], int n, int key){
//     int i=0, j=1;
//     while(i< n && j<n){
//         if (i!=j && arr[j]-arr[i] ==key )
//         {
//             return true;
//         }
//         else if( arr[j]-arr[i] < n)
//             j++;
//         else    
//             i++;
//     }
//     return false;
// }



//    T(n)  = O(n^2)
//    S(n)  = O(n)
int findPairWithDiffrence(int arr[], int n, int key){
    int res = -1;
    //diffrence is 60 (given)
    for (int i = 0; i < n; i++)
    {
        int y  = arr[i] + key;
        for (int j = 1 ; j < n; j++)
        {
            if (arr[j] == y)
            {
                res = 1;  // if preesent = 1 (pair exists)
                break;
            }
        }
    }
    return res;  // if not present =  -1  (pair do not exists)
}

// T(n) = O(n)
// S(n) = O(n)
int findPairWithDiffrence(int arr[], int n, int x){
    unordered_map<int, int> umap;
    
    for (int i = 0; i < n; i++)
        umap[arr[i]] = 1;
    for (int i = 0; i < n; i++)
    {   
        int y = arr[i] + x;
        if (umap[y])  // if y present in umap
            return 1; 
    }
    return -1;
}

// T(n) = O(nlogn)
// S(n) = O(1)
int findPairWithDiffrence(int arr[], int n, int x){
    int f = -1;
    sort(arr, arr+n);
    for (int i = 0; i < n; i++)
    {
        int idx = upper_bound(arr+i+1, arr+n, x+arr[i]) - arr - 1;
        if(arr[idx]- arr[i]== x ){
            f=1;
            break;
        }
    }
    cout<<f<<endl;
}

int main(){
    int arr[] = { 1, 8, 30, 40, 100};
    int n = sizeof(arr)/sizeof(n);
    int key = 60; // if there exist a pair in array whose diffrence is 60 = ex. (40, 100)
    cout<<findPairWithDiffrence(arr, n, key)<<endl;
    return 0;
}