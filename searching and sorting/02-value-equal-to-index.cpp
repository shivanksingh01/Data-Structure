#include<iostream>
#include<vector>
using namespace std;

// Value equal to index value
// Given an array Arr of N positive integers.
// Your task is to find the elements whose value is equal to that of its index value.
// Input:   N = 5
//          Arr[] = {15, 2, 45, 12, 7}
// Output: 2     (one based indexing, nor zero)
// Explanation: Only Arr[2] = 2 exists here.

vector<int> valueEqualToIndex(int arr[], int n) {
	    // code here
	    vector<int> v;
	    for(int i = 0 ; i< n; i++){
	        if(arr[i] == i+1)
	            v.push_back(arr[i]);
	    }
	   return v;
	}

int main(){
    // index :   1   2   3   4  5
    int arr[] = {15, 2, 45, 12, 7};
    int n = sizeof(arr)/sizeof(int);

    valueEqualToIndex(arr, n);
    return 0;
}