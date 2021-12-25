// 350. Intersection of Two Arrays II - leetcode
// Given two integer arrays nums1 and nums2, return an array of their intersection. 
// Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order

// Input: nums1 = [1,2,2,3,4], nums2 = [2,2,4]
// Output: [2,2,4]    -->  common elemnts
// note : [4,2,2] is also accepted

// using hash-map (map)
// Time complexity - O(N)

#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map1; // created a map to store array1(nums1) and frequency of its element
        vector<int> ans;  // stores the common element or intersecting 
        
        for(int i=0;i<nums1.size();i++){
            map1[nums1[i]]++;    // counting frequencies of elemnt of array1 (nums1)
        }
        
        for(int i=0 ; i<nums2.size() ; i++){
            auto it = map1.find(nums2[i]);  // find() -> returns a pair of a element and its fre
            if(it != map1.end() &&  it->second > 0){    // (*it).second > 0
                ans.push_back(nums2[i]);
                it->second--;   // decrement the frequency count of elemnt from array1 
            }
        }
        return ans;
}

int main(){
    vector<int> nums1 = {1,2,2,3,4};
    vector<int> nums2 = {2,2,4};

    vector<int> res = intersect(nums1, nums2);
    for(auto it : res){
        cout<<it<<"  ";
    }
}
