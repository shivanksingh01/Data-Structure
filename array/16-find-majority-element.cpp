// Find majority element
// Given an integer array containing duplicates, return the majority element if present. 
// A majority element appears more than n/2 times, where n is the array size.
// element's count  > n/2 = majority element
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Brute-Force
// 1. Create a variable to store the max count, count = 0
// 2. Traverse through the array from start to end.
// 3. For every element in the array run another loop to find the count of similar elements in the given array.
// 4. If the count is greater than the max count update the max count and store the index in another variable.
// 5. If the maximum count is greater than the half the size of the array, print the element. Else print there is no majority element.
// Time complexity - T(n) = O(n^2)
// Space complexity - O(1)
int majorityElement(int arr[], int n){
    // int maxcount=0;
    // int index=-1;
    // for (int i = 0 ; i<n/2+1; i++){   
    //     int count =0;
    //     for (int j = i+1 ; j < n; j++){
    //         if(arr[i]==arr[j])
    //             count++;
    //     }
    //     // update max count if count of current elemnt is greater than max count
    //     if(count > maxcount){
    //         maxcount=count;
    //         index = i;
    //     }
    //     if (maxcount > n/2)
    //         return arr[i];
    // }
    // or
    for (int i = 0; n && i <= n/2; i++){
        int count = 1;
        for (int j = i + 1; j < n; j++){
            if (arr[j] == arr[i]) {
                count++;
            }
        }
 
        if (count > n/2) 
            return arr[i];
    }
    return -1;
}

// -----------------------------------------------------------------------------------------------
// Linear time solution - using hashing (unordered map)
//      --  store each elemnt with freq in map, and return it if frequency becomes more than n/2
// time complexity = O(n)
// space complexity = O(n)
// int majorityElement(int arr[], int n){
//     // 
//     unordered_map<int, int> umap;   //empty map to store key value pair 
//     for (int i = 0; i < n; i++)
//         umap[arr[i]]++;     // store each elemnt freq in map
//     for(auto pair:umap){
//         if (pair.second > n/2)   // if freq. is more than n/2 return element
//             return pair.first;
//     }
//     // we can merge above two steps
//     // for (int i = 0; i < n; i++){
//     //     if(++umap[arr[i]] > n/2)
//     //         return arr[i];
//     // }
//     return -1;
// }

// -------------------------------------------------------------------------------------------

// Boyer-Moore majority vote algoritm
// algorithm is divided in two steps 
//         step 1. finding candidiate key for majority elemnts   - O(n)
//         step 2. check wether given elemnt is majority         - O(n)
// time complexity  - O(n) + O(n) = O(2n) = O(n)
// sapce complexity - O(1)
// note -
//     - candidate elemnt is the only possible majority majorityElemnt  (if present)
//     - this technique always returns an elemnt

//  let first elemnt be our majority elemnt and count =1
// traverse array :: 
// if next element is same as current , increment count by 1 , else decrement count by 1
// if count become zero :: update the majority elemnt and make count = 1
// after traversing majorityidx will be pointing to majority elemnt 
// int getMajorityElemnt(int arr[], int n){
//     int majorityIdx = 0, count = 1; // assume first elemnt as majority and count of it =1 
//     for (int i = 1; i < n; i++){
//         if(arr[majorityIdx] == arr[i])  //comparing elemnt with next elemnt in array
//             count++;
//         else
//             count--;
//         if(count==0){ 
//             majorityIdx = i;
//             count = 1;
//         }
//     }
//     return arr[majorityIdx];   //  possible candidate for majority elemnt
// }
// int isMajorityElement(int arr[], int n, int majorityEle){
//     int count =0;
//     for (int i = 0; i < n; i++){
//             if(arr[i] == majorityEle)
//                 count++;
//     }
//     return (count > n/2) ? 1 : 0 ;
// }
// void MajorityElement(int arr[], int n){
//     int candidate = getMajorityElemnt(arr,n);
//     if (isMajorityElement(arr, n, candidate))
//         cout<<candidate<<endl;
//     else    
//         cout<<"no majority element"<<endl;    
// }
// ------------------------------------------------------------------------------


int main(){
    // int arr[] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 }; 
    int arr[] = {8,8,7,7,7};
    int n= sizeof(arr)/sizeof(int);
    int result = majorityElement(arr, n);
    if (result != -1) 
        cout << "The majority element is " << result;
    else 
        cout << "The majority element doesn't exist";
 
    return 0;
}
