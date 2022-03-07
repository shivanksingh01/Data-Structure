
// answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// answer[i] == "Fizz" if i is divisible by 3.
// answer[i] == "Buzz" if i is divisible by 5.
// answer[i] == i (as a string) if none of the above conditions are true.

// Exampkle
// Input: n = 5
// Output: ["1","2","Fizz","4","Buzz"]
// Input: n = 15
// Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> fizbuzz(int n){
    vector<string> res(n, ""); // output vector of size n initialized with 
    for(int i=1; i< n+1;i++){
        if( i%3==0 && i%5==0){
            res[i-1] = "FizzBuzz";
        }
        else if( i%5 == 0){
            res[i-1] = "Buzz";
        }
        else if(i%3==0){
            res[i-1] = "Fizz";
        }
        else{
            res[i-1] = to_string(i);
        }
    }
    return res;
}

// vector<string> fizzBuzz(int n) {
//         vector<string> v;
//         for(int i=1;i<=n;i++){
//             if(i%3==0 && i%5==0){
//                 v.push_back("FizzBuzz");}
//             else if(i%3==0){
//                 v.push_back("Fizz");
//             }
//             else if(i%5==0){
//                 v.push_back("Buzz");
//             }
//             else{
//                 v.push_back(to_string(i));
//             } 
//         }
//        return v; 
// }

int main(){
    int num=15;
    vector<string> ans = fizbuzz(num);
    for (auto it : ans){
        cout<<it<<" , ";
    }
    return 0;
}