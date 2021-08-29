// reverse a string using stack
// input string : "HELLO WOLRD!"
// Output String : "!DRLOW OLLEH"

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------
// using explicit stack
void reverseString(string str){
    stack<int> s;
    for(char ch : str ){
        s.push(ch);
    }
    for (int i = 0; i < str.length(); i++){
        str[i] = s.top();
        s.pop();
    }
    cout<<"string reversed : "<<str<<endl;
}

// -----------------------------------------

// using implicit stack
// void swap(char* x, char*y){
//     char ch = *x;
//     *x = *y;
//     *y = ch;
// }

// void reverseString(char* str){
//     int low = 0;
//     int high = strlen(str)-1;
//     if (low<high){
//         swap(&str[low], &str[high]);
//         low++;
//         high--;
//     }
// }
// -----------------------------------------------

int main(){
    char str[] = "shivank";

    reverseString(str);
    cout<<str<<endl;
    return 0;
}