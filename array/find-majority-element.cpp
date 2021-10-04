// Find majority element
// Given an integer array containing duplicates, return the majority element if present. 
// A majority element appears more than n/2 times, where n is the array size.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Brute-Force
// Time complexity - T(n) = O(n^2)
// Space complexity - O(1)
int majorityElement(int arr[], int n){
    int count=1;
    for (int i = 0 ; i<n/2+1; i++)
    {
        for (int j = i+1 ; j < n; j++)
        {
            if(arr[i]==arr[j])
                count++;
        }
        if (count > n/2){
            cout<<count<<endl;
            return arr[i];
        }
    }
    return -1;
}

// -----------------------------------------------------------------------------------------------
// Linear time solution - using hashing
//      --  store each elemnt with freq in map, and return it if frequency becomes more than n/2
int majorityElement(int arr[], int n){
    unordered_map<int, int> umap;   //empty map
    for (int i = 0; i < n; i++)
        umap[arr[i]]++;     // store each elemnt freq in map
    for(auto pair:umap){
        if (pair.second > n/2)   // if freq. is more than n/2 return element
            return pair.first;
    }
    // we can merge above two steps
    // for (int i = 0; i < n; i++){
    //     if(++umap[arr[i]] > n/2)
    //         return arr[i];
    // }
    return -1;
}

// -------------------------------------------------------------------------------------------

// Boyer-Moore majority vote algoritm
// algorithm is divided in two steps 
//         step 1. finding candidiate key for majority elemnts   - O(n)
//         step 2. check wether given elemnt is majority         - O(n)
// time complexity  - O(n) + O(n) = O(2n) = O(n)
// sapce complexity - O(1)
// note -
//     - candidate elemnt is the only possible majority majorityElemnt  (if present)
//     - this technique always returns an elemnt

int getMajorityElemnt(int arr[], int n){
    int majorityIndex = 0, count = 1;
    for (int i = 1; i < n; i++){
        if(arr[majorityIndex] == arr[i])  //comparing elemnt with next elemnt in array
            count++;
        else
            count--;
        if(count==0){
            majorityIndex = i;
            count = 1;
        }
    }
    return arr[majorityIndex];   //  possible candidate for majority elemnt
}
int isMajorityElement(int arr[], int n, int majorityEle){
    int count =0;
    for (int i = 0; i < n; i++){
            if(arr[i] == majorityEle)
                count++;
    }
    return (count > n/2) ? 1 : 0 ;
}
void MajorityElement(int arr[], int n){
    int candidate = getMajorityElemnt(arr,n);
    if (isMajorityElement(arr, n, candidate))
        cout<<candidate<<endl;
    else    
        cout<<"no majority element"<<endl;    
}
// ------------------------------------------------------------------------------


int main(){
    int arr[] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 }; 
    int n= sizeof(arr)/sizeof(int);
    int result = majorityElement(arr, n);
    if (result != -1) 
        cout << "The majority element is " << result;
    else 
        cout << "The majority element doesn't exist";
 
    return 0;
}
