// 217. Contains Duplicate
// Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

#include<bits/stdc++.h>
using namespace std;

//     approqch-2  using sorting
//     sort the array ....check for adjacent elements
//     T(n)= O(n.logn)
//     S(n) = O(1)
bool containsDuplicate(vector<int>& nums) {
    int n= nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-1;i++){
        if(nums[i]== nums[i+1]){
            return true;
        }
    }
    return false;
}


// approach-2 using hashmaps (unordered maps)
// T(N) = O(n)

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> umap;
    // hash table
    // key=elemnts  freq=count
    // for(auto it : nums)  umap[it]++;
    for (int i = 0; i < nums.size(); i++)
    {
        umap[nums[i]]++; // creating a frequency map
    }
    for (auto it : umap)
    {
        // cout<<it.first<<" "<<it.second<<endl;
        if (it.second > 1) // for any key if the value is greater than 1 , than elemnt (key) is repeating elemnet
            return true;   // return true for repeating
    }
    return false; // return false if no value is greater than 1
}

int main(){
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    cout<<containsDuplicate(nums);
}