// get odd occurences
// find the number occureniung odd number of times in an array given that exactly one number occours odd no. of times 
// (only elemnt occuring odd number of times)
// Input : arr = {1, 2, 3, 2, 3, 1, 3}
// Output : 3   (3 is occuing 3 times)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Approach 1 : Brute-force 
// time complexity :  T(n) = O(n^2)
int oddOccurence(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i+1 ; j < n; j++)
        {
            if (arr[i]== arr[j])
                count ++;
        }
        if (count%2 != 0)
            return arr[i];
    }
    return -1;
}

// Approach-2   Using hashing 
// Time complexity :  T(n) = O(n)
//  insert into HashMap : O(1) + iterate through HashMap : O(n)   ==> total time complexity : O(n)
// Space complexity : O(n)    uses extra space

int oddOccurence(int arr[], int n){
    unordered_map<int,int> umap;  // define hashMap (empty)
    for (int i = 0; i < n; i++) 
        umap[arr[i]]++;    // put elements in HashMap  -->  T(n) = O(1)
    // Iterate through hash to check an elemnt is occuring odd no. of times
    for(auto pair : umap){     // time complexity : (n)
        if ((pair.second%2) != 0)
            return pair.first;
    }
    return -1;
}


// Approach 3 : Using bitwise XOR [Exclusive OR] (best approach)    [XOR -> sum modulo 2]
// XOR of all elemnts gives odd occuring elemnts 
//  note: XOR of two elemnts is 0 , XOR of x with 0 is x
// A^A = 0  , A^A^A = A  , XOR has commutative property ->  A^B = B^A 
// Traverse input arr using for loop and XOR all elemnts of array.
// At the end traversal XOR will host odd count elemnt in array
// // Time complexity :  T(n) = O(n)
int oddOccurence(int arr[], int n){
    int res = 0;
    for (int i = 0; i < n; i++)
        res = res ^ arr[i];    // XOR of all elemnts
    
    return res;
}

int main(){
    int arr[] = {1, 2, 5, 3, 3, 1, 2};
    int n = sizeof(arr)/sizeof(int);

    cout<<oddOccurence(arr, n)<<endl;
    return 0;
}


