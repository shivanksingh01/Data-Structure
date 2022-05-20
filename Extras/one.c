// Find a pair with a given sumin a an array
// Given an unsorted integer array, find a pair with the given sum in it.

// Input  : nums = [8, 7, 2, 5, 3, 1]     ,    target = 10
// Output : Pair found (8, 2) , (7, 3)
#include <iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


// brute-force
void findPairsum(int arr, int n, int target){
    for(int i=0; i<n-1;i++){
        for(int j=0;j<n;j++){
            if(arr[i] + arr[j] == target){
                printf("(%d, %d) ", i, j);
            }
        }
    }
}

int main() {
    int nums[] =  { 8, 7, 2, 5, 3, 1 };
    int target = 10;
    int n= sizeof(nums)/sizeof(int);
    findPairsum(nums,n,target);
    return 0;
}