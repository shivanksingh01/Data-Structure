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
    for (int i = 0; i < s2.length()-temp.length(); i++){
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

int main(){
    string a = "HELLO";
    string b = "LOHEL";

    if (checkRotation(a, b)){
        cout<<"String is rotated........."<<endl;
    }
    else
        cout<<"String not rotated........"<<endl;

    return 0;
}