// 26. Remove duplicate from sorted array
// Given an integer array nums sorted in non-decreasing order, 
// remove the duplicates in-place such that each unique element appears only once. 
// The relative order of the elements should be kept the same.

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include<bits/stdc++.h>
using namespace std;

void display(vector<int> &nums, int n){
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

// approach-1 optimal - using two pointer
int removeDuplicates(vector<int> &nums, int n){
    if (n == 0 || n == 1){ 
        return n;   // if array size is 0 or 1
    }
    // int j=0;
    // for(int i=1; i<n; i++){
    //     if(nums[i]!=nums[j]){
    //         j++;
    //         nums[j] = nums[i];
    //     }
    // }
    // return j+1;

    // index will move only when we modify th array inplace
    // to include a new non duplicate elemnt
    int j = 0; // to keep track of number of unique elemnts
    for (int i = 0; i < n; i++){ // to iterate over array
        // if current elemnt is equal to next elemnt , then it is duplicate
        if (nums[i] == nums[i + 1] &&  i<n-1){
            continue; // do nothing
        }
        nums[j] = nums[i]; // insert (modify original array)
        j++;
    }
    return j;
}

//   approach-2  using hashmap (unordered map)
//     time complexity = O(n)
//     space complexity = O(n)
int removeDuplicates(vector<int> &nums, int n){   
    if (n == 0 || n == 1){ // if array size is 0 or 1
        return n;
    }
    int j = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++){
        if (umap.find(nums[i]) == umap.end()){
            nums[j++] = nums[i];
        }
        umap[nums[i]]++;
    }
    return j;
}



int main(){
    vector<int> nums= {0,0,1,1,1,2,2,3,3,4};
    int n = nums.size();
    display(nums,n);
    int k = removeDuplicates(nums, n);
    display(nums,k);

    return 0;
}