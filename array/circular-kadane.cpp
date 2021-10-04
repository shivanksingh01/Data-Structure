// Maximum circular subarray sum
// Given n numbers (both +ve and -ve), arranged in a circle, find the maximum sum of consecutive numbers. 
// Input  : a[] = {10, -3, -4, 7, 6, 5, -4, -1} 
// Output:  23    (7 + 6 + 5 - 4 -1 + 10) 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int kadane(int arr[], int n){
    int max_sofar = 0;  // overall sum (osum)
    int max_ending_here = 0;   // current sum (csum)

    for (int i = 0; i < n; i++)
    {
        max_ending_here += arr[i];
        if (max_sofar < max_ending_here)
            max_sofar = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here =0;
    }
    return max_sofar;
}

int circularKadane(int arr[], int n){
    int maxSum_kadane = kadane(arr, n);  // get maxSum using standard kadane (without corner ele)
    if (maxSum_kadane <0)
        return maxSum_kadane;
    
    int maxSum_wrap = 0;
    for (int i = 0; i < n; i++)
    {
        maxSum_wrap += arr[i];    // get total sum of array
        arr[i] = - arr[i];   // invert array elemnt  (min sum becomes max sum)
    }
    // total arr sum  -  min subarray sum = max subarray sum  (with corners)
    // total arr sum  -  (- max subarry sum)  =  max subarray sum  (with corners)
    maxSum_wrap = maxSum_wrap + kadane(arr, n);  // get maxsum subarray of inverted array using kadane 

    // compare both subarray sum (with corners and without corners)  -->  return greater one
    return maxSum_wrap> maxSum_kadane ? maxSum_wrap:maxSum_kadane;
}

int main(){
    int arr[] = {2, 1, -5, 4, -3, 1, -3, 4, -1 };
    int n = sizeof(arr)/sizeof(int);
    cout<<"sum of subarray with largest sum : "<<circularKadane(arr, n)<<endl;
    return 0;
}