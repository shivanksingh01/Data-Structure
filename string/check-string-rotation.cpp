// A Program to check if strings are rotations of each other or not
#include<bits/stdc++.h>
using namespace std;

bool checkRotation(string s1, string s2){
    // check string length
    if (s1.length() != s2.length()){
        return false;
    }
    string temp = s1+ s1;
    // check if s2 is present in temp
    for (int i = 0; i < temp.length()-s2.length(); i++){
        int flag = 1;
        for (int j = 0; j < s2.length()-1; j++)
        {
            if (s2[j] != temp[i+j])
            {
                flag = 0;
                break;
            }
        }
        if (flag==1)
            return true;
    }
    return false;
}

// using stl
bool checkRotation(string s1, string s2){
    if (s1.length() != s2.length()){
        return false;
    }
    else
    {
        string temp = s1+ s1;
        if (temp.find(s2) != string::npos){    //  static const size_t npos = -1;
            return true;
        }
        else
            return false;
    }
}

// using queue
bool checkRotation(string s1, string s2){
    if (s1.length() != s2.length()){
        return false;
    }
    else{
        queue<char> q1;
        for (int i = 0; i < s1.size(); i++){
            q1.push(s1[i]);
        }
        queue<char> q2;
        for (int i = 0; i < s2.size(); i++){
            q1.push(s2[i]);
        }

        int k= s2.size();   // or k = s1.size()
        while (k--){
        //  remove elemnt from front and push it from back (rotate the queue)
            char ch= q2.front();
            q2.pop();   // pop from front
            q2.push(ch); // push to back
        //  chechk if both queue becomes equal string is rotated
            if (q2==q1){
                return true;
            }
        }
        return false;
    }
}


int main(){
    string s1 = "HELLO";
    string s2 = "LOHEL";

    if (checkRotation(s1, s2)){
        cout<<"String is rotated........."<<endl;
    }
    else
        cout<<"String not rotated........"<<endl;

    return 0;
}