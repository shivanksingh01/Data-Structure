// move zeros 
// Given an integer array nums, move all 0's to the end of it while maintaining 
// the relative order of the non-zero elements.

// Note :  that you must do this in-place without making a copy of the array.

// Input  : nums = [0,1,0,3,12]
// Output :        [1,3,12,0,0]

#include<bits/stdc++.h>
using namespace std;
// approach -1  (using while loop)  - two pointer
void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    if(n==0 || n==1){  // if size of array is 0 or 1  return 
        return; 
    }
    // take two pointer left and right
    int left=0; 
    int right=0;
    while(right < n ){  
        if(nums[right] != 0){    // if array elemnt is non zero
        // swap( nums[left], nums[right])
            int temp= nums[left];
            nums[left]= nums[right];
            nums[right]=temp;
                
            ++left;
            ++right;
        }
        else          // if nums[right]==0
            ++right;  // right++   (increment j)
        }
}
    
    
//     approach-2 (using for loop) - two pointer
// void moveZeroes(vector<int>& nums) {
//     int j=0;
//     for(int i=0; i<nums.size();i++){
//         if(nums[i]!=0){
//             nums[j++;] = nums[i];    
//         }
//     }
//         // j will be pointing to first index from where zero should start upto end of array
//         // fill the left array from j to n with zero   
//     while(j<nums.size()){
//           nums[j++]=0;
//     }
// }

void display(vector<int> &nums){
    for(auto i : nums){
        cout<< i<<"  ";
    }
}
    
int main(){
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    display(nums);
    
    return 0;
}
