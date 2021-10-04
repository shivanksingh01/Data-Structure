#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

#define max 100

// using Brure-Force
// time complexity   T(n) = O(n^2)
//  dosent require extra space
void findPairs(int *arr, int n, int sum)   
{
    for (int i = 0; i < n - 1; i++)    // consider each elemnt except last elemnt
        for (int j = i+1 ; j < n; j++)   // start from ith until last elemnt6
            if (arr[i] + arr[j] == sum)
            {
                printf("pairs are :  (  %d , %d )", arr[i], arr[j]);
                break;
            }
}

// Using sorting 
// Time complexity   T(n) = O(n.log(n))
// dosent require extra space 
void findPairs(int *arr, int n, int sum){
    sort(arr, arr+n);
    int low = 0;
    int high=n-1;
    while (low<high)
    {
        if(arr[low] + arr[high] == sum){
                printf("pairs are  : ( %d , %d ) ", arr[low], arr[high]);  
                return;
        }
        // increment `low` index if the total is less than the desired sum;
        // decrement `high` index if the total is more than the desired sum
        (arr[low]+arr[high]< sum) ? low++ : high--;
    }
     // we reach here if the pair is not found
    cout << "Pair not found";
}


// using hashing
// Time complexity   T(n) = O(n)
// space complexity - O(n)   [requires extra space ]
void findPair(int *arr, int n, int sum){
    int temp;
    int hash[max] = {0};
    for (int i = 0; i < n; i++)
    {
        temp = sum - arr[i];
        if(temp >= 0 && hash[temp]==1)
            printf("pairs are :  ( %d , %d ) : ", arr[i], temp);
        hash[arr[i]] = 1;
    }
}

//  using unordered map (stl)
void findPairs(int *arr, int n, int sum){
    unordered_map<int, int> umap;
    for(int i=0; i<n;i++){
        // if diffrence is found before , print pairs
        if(umap.find(sum-arr[i]) != umap.end()){
            printf("Pair found : ( %d , %d )", arr[umap[sum-arr[i]]], arr[i]);
            return;
        }
        umap[arr[i]] = i;   // strore index of current elemnt in map
    }
    cout<<"pair not found"<<endl;
}



int main()
{
    int n;
    printf("Enter the number of elemnts in an array : \n");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter array elements : \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int sum;
    printf("Enter sum : ");
    scanf("%d", &sum);
    findPair(arr, n, sum);
    return 0;
}