// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

#include<bits/stdc++.h>
using namespace std;
// approach-1 (using aort function)
// sort both string and compare 
// if equal :: anagram
// else :: not an anagaram

bool isAnagram(string s1, string s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1==s2){
        return true;
    }
    return false;
}

// Approach-2 (using map)
// create two map
// insert element in map
// using loop check for elemnt in map 
// if each elemnt is equal : anagram 
bool isAnagram(string s1, string s2){
    if(s1.length() != s2.length()){
        return false;
    }

    map<char, int> m1;
    map<char, int> m2;

    for(auto i: s1)
        m1[i++];
    
    for(auto i: s2)
        m2[i++];
    
    for(auto i : s1){
        if(m1[i]==m2[i])
            return true;
    }
    return false;
}


// Approach 3 : using vector

bool isAnagram(string s1, string s2){
    vector<int> vec1(26,0);
    vector<int> vec2(26,0);

    for (int i = 0; i < s1.length(); i++)
            vec1[(int)s1[i] - 'a']++;

    for (int i = 0; i < s2.length(); i++)
            vec2[(int)s2[i] - 'a']++;

        if (vec1 == vec2)
            return true;
        return false;  
}

int main(){
    string s1= "rat";
    string s2= "art";
    int res = isAnagram(s1, s2);
    res==1?cout<<"True":cout<<"False";
    return 0;
}