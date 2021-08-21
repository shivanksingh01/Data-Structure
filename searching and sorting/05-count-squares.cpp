// Count Squares
// Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. 
// You are given a number N, you have to output the number of integers less than N in the sample space S.

// Input :  N = 9
// Output:   2
// Explanation:   1 and 4 are the only Perfect Squares less than 9. So, the Output is 2.

// input : 30
// output : 5
//  1, 4, 9, 16, 25..., 30
// only perfect sqaure less than 30 is 25 , so output 5

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countSquare(int n){
    int a = sqrt(n);
    if(a*a == n)
        return a-1;
    else    
        return a;
}


int main(){
    int n;
    cout<<"Enter a number : ";
    cin>>n;

    cout<<countSquare(n)<<endl;
}