// 88. Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order



#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void swap(int *arr1, int *arr2){
    int temp = *arr1;
    *arr1= *arr2;
    *arr2= temp; 
}
void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

// approach-1  :: In-place alogithm  (merging two sorted arrays)
// time complexity = O( m.n) 
//  O(m) = to traverse arr1[]
//  O(n) = to sort arr2[]
void mergeSorted(int arr1[], int arr2[], int m, int n){
    // m = size of arr1[]
    // n = size of arr2[]
    for(int i=0;i<m;i++){
        // consider each elemnt of arr1 with first elemnt of arr2 
        // ignore if already in correct order otherwise swap
        if(arr1[i] > arr2[0]){
            swap(&arr1[i], &arr2[0]);
            // after swapaing , the order of arr2 will get changed
            // arr2 will not be sorted 
            // place arr2[0] (i.e. first elemnt to correct place ) to make arr2[] sorted
            int ele = arr2[0];
            int k;
            // sorting arr2[] :: which is already sorted except the first elemnt is not in order
            //    index : 0   1  2  3  4  5
            //      arr : 5 , 2, 3, 4, 8, 11
            // shift all elements to left and put 5 at its correct position
            //            2, 3, 4, 4, 8, 11      
            // insert 5 : 2, 3, 4, 5, 8, 11 
            for(k=1; k<n && arr2[k]<ele; k++){
                arr2[k-1]= arr2[k];
            }
            arr2[k-1]= ele;
        }
    }
}

// leetcode  Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//          Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// approach-2  (using two pointer :: inplace )
// time complexity = O(k) = O(m+n)
// space complexity = O(1)
void mergeSorted(int arr1[], int arr2[], int m, int n){
    int p1 = m-1;
    int p2 = n-1;
    int i = m+n-1;
    while(p2 >= 0){
        if(p1>=0 && arr1[p1]>arr2[p2]){
            arr1[i] = arr1[p1];
            i--; p1--;
        }
        else{
            arr1[i] = arr2[p2];
            i--; p2--;
        }
    }
}


int main() {
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    int m = sizeof(arr1)/sizeof(int);  // size of arr1[]
    int n = sizeof(arr2)/sizeof(int);   // sizeof arr2[]
    display(arr1,m);
    display(arr2,n);
    cout<<"After merger sort : "<<endl;
    mergeSorted(arr1, arr2, m, n);
    display(arr1,m);
    display(arr2,n);
    
    return 0;
}

