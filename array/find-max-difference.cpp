// FIND MAX DIFFRENCE
// find max diffrence between two elemnts such that larger appears after the smaller
// Input:  { 2, 7, 9, 5, 1, 3, 5 }
// Output: maximum difference : 7  --> (2,9)


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// brute-force approach
// time complexity - T(n) = O(n^2)
// space complexity  - O(1)
int maxDiff(int arr[], int n){
    int maxdiff = arr[1] - arr[0];
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[j] - arr[i] > maxdiff)
                maxdiff = arr[j] - arr[i];
        }
    }
    return maxdiff;
}

// approach-2
// step1 - construct the diffrence array first
//         diff[i] = arr[i+1] - arr[i]
// step 2 - find max sum subarray in diffrence array


int maxDiffrence(int arr[], int n){
    int diffArr[n-1];   // will bw one size smaller
    for (int i = 0; i < n-1; i++)
    {
        diffArr[i] = arr[i+1]-arr[i];
    }
    int maxDiff = diffArr[0];
    for (int i = 1; i < n-1; i++)
    {
        if (diffArr[i-1] > 0)
            diffArr[i] = diffArr[i] + diffArr[i-1];
        maxDiff = diffArr[i] > maxDiff ? diffArr[i] : maxDiff;
    }
    return maxDiff;
}
 




// approach-3
// increment i from 1 to n
// if arr[i] elemnt is less than minimum , update minimum
// else , if greater , subtract greater from minimum to get the diffrence
//             then compare current diffrence with max , if greater, update the max diffrence
int maxDiffrence(int arr[], int n){
    int min = arr[0];
    int currdiff = arr[1]- arr[0];
    int maxdiff = currdiff;

    for (int i = 1; i < n; i++){
        if (arr[i] < min)
            min = arr[i];
        else{
            currdiff = arr[i] - min;
            if (currdiff > maxdiff)
                maxdiff = currdiff;
        }
    }
    return maxdiff;
}

int main(){
    int arr[] = {4, 3, 10, 2, 9, 1, 6};
    int n = sizeof(arr)/sizeof(int);
    cout<<"Max diffrence : "<<maxDiffrence(arr, n)<<endl;

    return 0;
}