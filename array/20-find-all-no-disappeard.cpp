// 448. Find All Numbers Disappeared in an Array
// Given an array nums of n integers where nums[i] is in the range [1, n],
// return an array of all the integers in the range [1, n] that do not appear in nums.

// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]

// Example 2:
// Input: nums = [1,1]
// Output: [2]

#include <bits/stdc++.h>
using namespace std;

//     Approach-1 (creating a visited array :: mark them as negative)
//     Time complexity - O(N)
//     Space complexity - O(1)
// index :         0    1    2    3    4    5    6    7
// array :         4    3    2    7    8    2    3    1
// visited arr :  -4   -3   -2   -7    8    2   -3   -1
// output :  5 , 6

vector<int> findDisappearedNumbers(vector<int> &nums){
    int n = nums.size();
    vector<int> res;

    for (int i = 0; i < n; i++){
        int curr = abs(nums[i]);
        nums[curr - 1] = -abs(nums[curr - 1]);
        // arr[abs(arr[i])-1] = -arr[abs(arr[i])-1]
    }
    // or 
    // for(int i=0;i<nums.size();i++){
    //       int num = abs(nums[i])-1;
    //         if(nums[num] > 0)
    //             nums[num] *= -1;
    // }
    for (int i = 0; i < n; i++){
        if (nums[i] > 0)
            res.emplace_back(i + 1);   // faster than push_back()
    }
    return res;
}

// Approach-2  (Unordered set)
// Time complexity - O(N)
// Space complexity - O(N)
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    vector<int> res;
    unordered_set<int> uset(nums.begin(), nums.end());
    for(int i=1;i<n;i++){
        if(uset.find(i)==uset.end()){
            res.emplace_back(i);  // faster than push_back()
        }
    }
    return res;
}

int main(){
    // vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> nums = {1,1};
    vector<int> ans = findDisappearedNumbers(nums);
    for(auto it : ans){
        cout<<it<<"  ";
    }
    cout<<endl;
    return 1;
}