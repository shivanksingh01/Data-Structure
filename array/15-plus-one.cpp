// 66. Plus One
// You are given a large integer represented as an integer array digits, 
// where each digits[i] is the ith digit of the integer. The digits are ordered 
// from most significant to least significant in left-to-right order. 
// The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.

// example - 
// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].

// Start from the LSB and then process each digit till MSB.
// If the current digit is smaller than 9 then add one to the current digit and return the array else assign zero to the current digit.
// If the last element is processed and it was also equal to 9, it means that all the digits were 9. So, we will increase the size of the array by one and assign 1 to the MSB.
// Return the array

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits){
    int n = digits.size();
    for (int i = n - 1; i >= 0; i--){
        if (digits[i] < 9){ // if last digit is not 9 , increment by 1 , and return
            digits[i]++;
            return digits; // input = [5, 6, 7, 8] --> [5, 6, 7, 9]
        }
        else
            digits[i] = 0; // if digit is 9 , make it 0 , decrement the index and check for digit again
    }
    // if all digits become zero
    // create a new array of size one more than previous array and make first index = 1
    // if input =  [ 9,9,9,9,9]  ->  [0, 0, 0, 0, 0 ]  , n=5
    // correct output = [1, 0, 0, 0, 0, 0] , n=6
    vector<int> res(n + 1, 0);
    res[0] = 1;
    return res;
}

    //aproch-2    (using indexes)
    // vector<int> plusOne(vector<int>& digits) {
    //     int idx = digits.size()-1;
    //     while(idx >= 0){
    //         if(digits[idx] == 9)
    //             digits[idx] = 0;
    //         else{
    //             digits[idx] += 1;
    //             return digits;
    //         }
    //         idx--;
    //     }
    //     digits.insert(digits.begin(), 1);
    //     return digits;
    // }

int main(){
    vector<int> nums = {3, 4, 5, 6};
    vector<int> res = plusOne(nums);
    
    // displaying the output
    for(auto it: res){
        cout<<it<<" ";
    }
    cout<<endl;
}