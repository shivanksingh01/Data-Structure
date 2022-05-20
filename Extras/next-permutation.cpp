//  Next Permutation  - Leetcode (Medium)
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// arr[1, 2, 3] = premutation => [1,3,2] , [2,3,1], [2,1,3], [3,1,2], [3,2,1]
// next greater permutation of [1,2,3] => [1,3,2]
// if array is sorted in descending order :: reverse the array

#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void nextPermutation(vector<int> &arr){
    int idx = -1;
    for (int i = arr.size()-1; i > 0; i--){ // iterate from last
    // check for element smaller than prev (note:iterating from right)
        if (arr[i] > arr[i - 1]){
            idx = i;
            break; // if found break
        }
    }
    // if not found i.e. array is sorted in descending :: reverse the array
    if (idx == -1){
        reverse(arr.begin(), arr.end());
    }
    //         idx = updated => indx upto sorted in descending]
    //         swap(idx-1, next greater)
    else{
        int prev = idx;
        for (int i = idx + 1; i<arr.size(); i++)
        {
            if (arr[i] > arr[idx - 1] and arr[i] <= arr[prev]){
                prev = i;
            }
        }
        swap(arr[idx - 1], arr[prev]);   // swap that smaller elemnt with its nextgreater elemnt in right to end
        reverse(arr.begin() + idx, arr.end());  // revese the right to end after swapping
    }
}

int main(){
    vector<int> arr = {1,5,8,4,7,6,5,3,1};
    nextPermutation(arr);
    display(arr);
    return 0;
}