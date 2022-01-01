// 35. Search Insert Position
// Given a sorted array of distinct integers and a target value,
// return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// write an algorithm with O(log n) runtime complexity
// Example 1
// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2
// Input: nums = [1,3,5,6], target = 2
// Output: 1

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// binary search approach
// time complexity - O(n.logn)
// space complexity - O(1)
int searchInsert(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high){
        mid = low + (high - low) / 2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] < target){
            low = mid + 1;
        }
        else if (nums[mid] > target)
            high = mid - 1;
    }
    return high + 1;     // if elemnt is not found inside the array low > high
                    // we break out of loop and high will be pointing one index prior to its correct position
}

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 4;   // output = 2
    cout<<searchInsert(nums, target)<<endl;
    return 0;
}