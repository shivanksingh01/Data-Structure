// 287. Find the Duplicate number
// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Input: nums = [3,1,3,4,2]
// Output: 3

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

// approach-1 (brute-force)
// time complexity  = O(NlogN)
// space complexity = O(1)
// but it is distorting our original array
void duplicates(int arr[],int n){
    sort(arr, arr+n);  // sort the array
    for(int i=0;i<n;i++){   // traverse the sorted array
        if(arr[i]==arr[i+1]){
            cout<<arr[i]<<endl;
            break;
        }
    }
}

// Approach-2  (creating a visited array)
// time complexity  = O(N)
// space complexity = O(1)
void duplicates(int arr[], int n){
    for(int i=0; i<n;i++){
        if(arr[abs(arr[i])-1] > 0 ){
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        else{
            cout<<"duplicate number : "<< abs(arr[i])<<endl;
        }
    }
    //                       0   1   2  3   4   5   6   7   8
    // display(arr, n); //  -2  -5  -9  6  -9  -3  -8  -7  -1
    // we can also find missing number
    // for(int i=0;i<n;i++){
    //     if(arr[i] > 0){
    //         cout<<" missing number : "<< i+1 <<endl;
    //     }
    // }
}


//  approach-3 ( creating a frequency array using extra space)
// time complexity  = O(N)
// space complexity = O(N)
void duplicates(int arr[], int n){
    int newarr[n] = {0}; // creating newarray initializing with zero
    for(int i=0;i<n;i++){
        if(newarr[arr[i]] == 0){
            newarr[arr[i]]= 1;
        }
        else{
            cout<<"repeating : "<< arr[i]<<endl;
        }
    }
}


// approach-4 (slow-fast-pointer)
// floyd cycle detection algorithm
// T(N) = O(N)
// S(n) = O(1)
int duplicates(vector<int>& arr) {
        if (arr.empty()) {
            return 0;
        }
        int slow = arr[0];
        int fast = arr[0];
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        }while (slow != fast);

        fast = arr[0];
        while (fast != slow) {
            fast = arr[fast];
            slow = arr[slow];
        }
        return fast;
    }

// Approach - (Using STL)
// 
int duplicates(vector<int> &arr){
    int n = arr.size();
    auto it = adjacent_find(arr, arr+n);
    return *it;

}


int main() {
    vector<int> arr = {4, 3, 6, 5, 2, 4};
    // int n = sizeof(arr)/ sizeof(int);
    cout<<duplicates(arr)<<endl;
}
