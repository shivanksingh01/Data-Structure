// 53. max-sum-subarray  - Kadanes algorithm
// input - -2, -3, 4, -1, -2, 1, 5, -3
// output - max sum : 7  (4, -1, -2, 1, 5)

// Given an integer array nums, find the contiguous subarray
// (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach-1 (brute-force)
// time complexity = O(n^2)
// space complexity = O(1)
int maxSubArray(vector<int> &nums){
    int n = nums.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; i++){
        int currSum = 0;
        for (int j = i; j < n; j++){
            currSum += nums[j];
            ans = max(ans, currSum);
        }
    }
    return ans;
}

// kadane's agorithm
// time complexity = O(n)
// space complexity = O(1)
int maxSumSubarray(int arr[], int n)
{
    int csum = arr[0]; // current sum --> max_ending_here
    int osum = arr[0]; // overall sum  --> max_sum_so_far
    for (int i = 1; i < n; i++)
    {
        if (csum > 0)       // if current-sum is negative replace with current elemnt (arr[i])
            csum += arr[i]; // else add current-sum to curr-elemnt (csum + arr[i])
        else
            csum = arr[i];

        if (csum > osum)
            osum = csum;
    }
    return osum;
}

// or 
int maxSumSubarray(int arr[], int n){
    int sum = 0;
    int maxSum = arr[0];
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > maxSum)   // if currentSum is greater than maxSum
            maxSum= sum;   // replace maxSum with currentSum
        if(sum < 0)        // if currentSum is negative, we will not take it forward ::
            sum =0;         //  as it will decrease the resutant value when added with positive number
    }                       // so make currentSum equal to zero
    return maxSum;
}

// or  (tricky-to-understand)
// int maxSumSubarray(int arr[], int n){
//     int osum = INT_MIN;  // overall sum  --> max sum of sub array found so far
//     int csum = arr[0];       // current sum --> stores max sum of subarray ending at prev index i-1
//     for (int i = 1; i < n; i++)
//     {
//         csum += arr[i];  // update max sum of subarray by adding current elemnt
//         csum = max(csum, arr[i]);   // max. sum should be more than the current element
//         osum = max(osum, csum);     // update the rersult if current subarray is found to be greater
//     }
//     return osum;
// }

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << maxSumSubarray(arr, n) << endl;
    return 0;
}
