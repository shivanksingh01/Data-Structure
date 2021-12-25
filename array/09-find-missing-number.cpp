// Find the missing number in an array
// Given an array of n-1 distinct integers in the range of 1 to n, 
// find the missing number in it in linear time.
// Input  : {1, 2, 4, 6, 3, 7, 8}
// Output : 5 

#include<bits/stdc++.h>
using namespace std;

// Approach-1  (Using formula - sum of first n natural number ) 
// 1+2+3+.....+n = n*(n+1)/2
// Time Complexity - O(n)
// void findMissing(int arr[],int n){
//     int m = n+1; // since 1 number is missing : in actual array there will be n+1 numbers 
//     int total = m*(m+1) / 2;   // total sum of actual array
    
//     int sum=0; // finding sum of given array 
//     for(int i=0;i<n;i++){
//         sum += arr[i];
//     } 
//     cout<<"Mising number : "<<total - sum<<endl;
// }


// Approach-2 (USing XOR opeartor )
// binary -  b^b = ~b
//           b^0 = b
// decimal - x^x = 0
//           x^0 = x

void findMissing(int arr[], int n){
    // compute xor of all elemnts in an array
    int XOR = 0; 
    for(int i=0;i<n;i++){
        XOR = XOR ^ arr[i];
    }
    // compute XOR of all elemnt from [1 ... n+1 ] in an array
    for(int i=1; i<=n+1; i++){
        XOR = XOR ^ i;
    }

    // (1^2^4^8^9^7^6^3) ^ (1^2^3^4^5^6^7^8^9) = 5 (unique/ missing number)
    //  first for loop       second for loop 
    // 1^1 = 0   , so  all pair will be cancelled only 5 will be left out
    cout<<"Missing number : "<<XOR<<endl;
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int arr[] = { 1, 2, 4, 8, 9, 7, 6, 3};
    int n = sizeof(arr)/sizeof(int);
    display(arr, n);
    findMissing(arr, n);

    return 0;
}