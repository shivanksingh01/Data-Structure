// Majority Element 
// Given an array A of N elements. Find the majority element in the array. 
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.
//  

// Input:    N = 3 
//         A[] = {1,2,3} 
// Output:   -1
// Explanation:   Since, each element in  {1,2,3} appears only once so there is no majority element.


// Input:    N = 5 
//         A[] = {3,1,3,3,2} 
// Output:   3 
// Explanation:  Since, 3 is present more than N/2 times, so it is  the majority element.

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int majorityElement(int arr[], int n){
    // your code here
        int val = n/2;
        unordered_map<int, int> umap;
        for(int i=0; i< n; i++){
            umap[arr[i]]++;
        }
        for(auto x : umap){
            if (x.second > val)
                return x.first;
            // cout<<x.first<<"   "<<x.second<<endl;
        }
    return -1;
}

// ------- Moore’s Voting Algorithm  ------------
int majorityElemnt(int arr[], int n){
    int ele = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == ele)
            count++;
        else
            count--;
        
        if(count == 0){
            ele = arr[i];
            count = 1;
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == ele){
            c++;
        }
    }
    if(c > (n/2))
        return ele;
    else 
        return -1;
}

// another method (easy)
int majorityElement(int arr[], int n){
    int maxCount = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                count++ ;
        }
        if(count > maxCount){
            maxCount = count;
            index = i;
        }
    }

    if (maxCount > (n/2))
        return arr[index];
    else    
        return -1;
    
}

int main(){
    int arr[] = {1, 2, 3, 1, 2, 3, 3, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    cout<<"majority element : "<<majorityElement(arr, n)<<endl;
    return 0;
}
