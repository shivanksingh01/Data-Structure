//  function that reverses a string. The input string is given as an array of characters s
// Input : s = ["h","e","l","l","o"]
// Output:    ["o","l","l","e","h"]

#include<bits/stdc++.h>
using namespace std;

// using reverse function
// void reverseString(vector<char>& s){
//     reverse(s.begin(), s.end());
//     // displaying reverse array
//     for(char ch : s){
//             cout<<ch<<"  ";
//         }    
// }


void reverseString(vector<char>& s) {
        int n = s.size()-1;
        for(int i=0;i<=n/2;i++){
            // swap(s[i], s[n-i])
            int temp = s[n-i];
            s[n-i] = s[i];
            s[i] = temp;
        }
        // displaying arrayj
        for(char ch : s){
            cout<<ch<<"  ";
        }   
        // for (auto it = s.begin(); it != s.end(); it++)
        // cout << *it << " ";
}

int  main(){
    vector<char> s({'s', 'h', 'i', 'v', 'a', 'n', 'k'});
    reverseString(s);
}