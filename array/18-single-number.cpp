// 136. Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
// Input: nums = [4,1,2,1,2]
// Output: 4

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach-2 using stl
// std::count()  - returns number of occurrences of an element in a given range. 
// Returns the number of elements in the range [first,last) that compare equal to val.
// T(n) = O(n)
// Algorithm:
//         For every element in the nums, check whose count is not 2 and return it.
int singleNumber(vector <int> & nums) {
    for (const auto & e: nums){
        if (std::count(nums.begin(), nums.end(), e) != 2){
            return e;
        }
    }
        return 0;
}


// using XOR operator
//  x ^ x = 0  :: xor of same number will return 0 and only unique (single) element will be left out
// time complexity = O(n)
// space complexity = O(1)
int singleNumber(vector<int> &nums){
    int n = nums.size();
    int XOR = 0;
    for (int i = 0; i < n; i++){
        XOR = XOR ^ nums[i];
    }
    return XOR;
}


int main(){
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums);
    return 0;
}

 