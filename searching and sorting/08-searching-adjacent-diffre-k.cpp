// Searching in an array where adjacent differ by at most k
// A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, 
// we need to find the index value of x if multiple-element exist to return the first occurrence of the key.

// Input : arr[] = {20, 40, 50, 70, 70, 60}  
//           k = 20
//           x = 60  //elemnt to search
// Output : 5 -->   The index of 60 is 5

// start from left most --> 20 , do not traverse one by one , make solution optimal 
// next index  to jum = (arr[i] - x)/k   =>  (60-20)/20 = 2
//  elemnt may be present after 2 index 

#include<bits/stdc++.h>
using namespace std;

int searchAdjacentDiffreK(int arr[], int n, int x, int k){
    int i = 0;  // starting from first elemnnt (leftmost)
    while(i<n){
        // if elemnt found at index i
        if (arr[i] == x)
            return i;
    //  jump the diffrence between current array elemnt and x divided by k
        i = i + max(1, abs(arr[i] - x)/k);
    }        // max is used to make sure that i moves atleast one step ahead
    return -1;
}

int main(){
    int arr[] = {2, 4, 5, 7, 7 , 6};
    int x = 6;   // elemnt to search
    int k = 2;   //max adjacemt diffrence
    int n = sizeof(arr)/ sizeof(int);

    cout<<"Element is present at index : "<<searchAdjacentDiffreK(arr, n, x, k)<<endl;
    return 0;
}