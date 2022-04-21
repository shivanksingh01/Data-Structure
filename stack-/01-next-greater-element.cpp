// Find the next greater element for every array element

// example  -  
// Input:  [18,  7,  6, 12, 15]
// Output: [-1  12  12  15  -1]

// note : if no elemnt is greater return -1 

// Approach 1  - Brute Force
// Two nested loops  -  
//     outer to keep track of elemnt 
//     inner to consider all elemnts to right and terminate as soon as it finds larger element

// Time complexity O(n^2)
// worst case : arrr = [5,4,3,2,1] - for all the elemnt we have traverse whole array every time

#include<bits/stdc++.h>
using namespace std;

// void NextGreaterElement(int arr[], int n){
//     for(int i=0; i<n; i++){
//         int ele = -1;
//         for(int j=i+1; j<n;j++){
//             if (arr[i]<arr[j])
//             {
//                 ele = arr[j]; 
//                 break; 
//             }
//         }
//         cout<<ele<<"  ";
// }

// --------------------------------------------------------------------
// Approach 2 - Using Stack
// Time Complexity - O(N)
// Space Complexity - O(N)
// For each element x in the array, pop all elements from the stack smaller than x, and set their next greater element to x.
// Loop till we have a greater element on top of the stack or stack becomes empty. Then push the current element x on top of the stack.
// Repeat the process for every array element.



vector<int> NextGreaterElement(vector<int> arr){
    int n = arr.size();
    // initialize vector res of size n with value -1
    vector<int> res(n, -1); 
    stack<int> s;
    for (int i = 0; i < n; i++){
        while (!s.empty() && arr[s.top()]<arr[i]){
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    // if not initialized res array earlier with -1 
    // while(!s.empty()){
    //     res[s.top()] = -1;
    //     s.pop();
    // }
    return res;
}






int main(){
    // int arr[] = {18, 7, 6, 12, 15};
    // int n = sizeof(arr)/sizeof(n);
    // NextGreaterElement(arr, n);
    
    vector<int> arr = {18, 7, 6, 12, 15};
    vector<int> result = NextGreaterElement(arr);
    for (auto ele : result){
        cout<<ele<<"  ";
    }
    return 0;
}