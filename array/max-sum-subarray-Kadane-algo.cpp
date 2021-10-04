// Kadanes algorithm
// max-sum-subarray
// input - -2, -3, 4, -1, -2, 1, 5, -3
// output - max sum : 7  (4, -1, -2, 1, 5)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSumSubarray(int arr[], int n){
    int csum = arr[0];  // current sum --> max_ending_here
    int osum = arr[0];  // overall sum  --> max_sum_so_far
    for (int i = 1; i < n; i++)
    {
        if (csum>0)      // if current-sum is negative replace with current elemnt (arr[i])
            csum += arr[i];     // else add current-sum to curr-elemnt (csum + arr[i])
        else
            csum = arr[i];
        
        if(csum>osum)
            osum = csum;
    }
    return osum;
}



// or  (tricky-to-understand)
int maxSumSubarray(int arr[], int n){
    int osum = INT_MIN;  // overall sum  --> max sum of sub array found so far
    int csum = arr[0];       // current sum --> stores max sum of subarray ending at prev index i-1
    for (int i = 1; i < n; i++)
    {
        csum += arr[i];  // update max sum of subarray by adding current elemnt
        csum = max(csum, arr[i]);   // max. sum should be more than the current element
        osum = max(osum, csum);     // update the rersult if current subarray is found to be greater
    }
    return osum;
}


int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(int);
    cout<<maxSumSubarray(arr, n)<<endl;
    return 0;
}
