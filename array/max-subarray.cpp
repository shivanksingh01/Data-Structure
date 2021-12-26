#include <bits/stdc++.h>
using namespace std;

// brute-force
int maxSubArray(vector<int> &nums){
    int n = nums.size();
    int ans = INT_MIN;

    for (int i = 0; i < n; i++){
        int currSum = 0;
        for (int j = i; j < n; j++){
            currSum += nums[j];
            ans = max(ans, currSum);
        }
    }
    return ans;
}

int main(){
    // vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = {5,4,-1,7,8};
    cout<<maxSubArray(nums);
}


