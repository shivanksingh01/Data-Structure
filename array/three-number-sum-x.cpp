// Find a triplet that sum to a given value
// Given an array , find if tgere is an triplet in an array whose sum is equal to given value
// Input array : 12, 3, 4, 1, 6, 9
// Sum = 24
// Output : 12, 3, 9 

#include<bits/stdc++.h>
using namespace std;
// Brute-Force 
// Time complexity : T(n) = O(n^3)   ,  three nested loop
// space complexity : O(1)      , no extra space required
int threeNumberSum(int arr[], int n, int sum){
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1 ; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum){
                    printf("triplet is : %d , %d , %d  \n",arr[i], arr[j], arr[k]);
                    return 1;
                }   
            }
        }
    }
    return 0;
}

// using sortng , then applying binarySearch
// step-1 : Sort the array elemnts 
// step-2 : start from 0th index --> first elemnt
// other two pointer low =  1  , high = n-1
// sum of all these pointers is equal to required sum --> triplet is found
// if(sum is less than the required sum ) --> we need to increase the sum , increase low (low++)
// if(sum is more than the required sum ) --> we need to decrease the sum , decrease high (high--)
// Time complexity : O(N^2)  , only two nested loop
int threeNumberSum(int arr[], int n, int sum){
    sort(arr, arr+n);    // for sorting use insertion sort - T(n)=O(n.logn)

    for (int i = 0; i < n-2; i++)
    {
        int low=i+1;
        int high = n-1;
        while (low<high)
        {   
            int tripletSum = arr[i]+arr[low]+arr[high];
            if(tripletSum==sum){
                printf("triplet found : ( %d , %d , %d )\n", arr[i], arr[low], arr[high]);
                return 1;
            }
            if (tripletSum<sum)
                low++;
            else    
                high--;
        }
    }
    return 0;
}


int main(){
    int arr[] = {12, 3, 4, 1, 6, 9};
    int n = sizeof(arr)/sizeof(n);
    int sum = 24;
    cout<<threeNumberSum(arr, n, sum);
    return 0;
}