// Find the missing number and duplicate (repeating) elements in an array
// Given an integer array of size n, with all its elements between 1 and n
//  and one element occurring twice and one element missing
// Input:  arr[] = [4, 3, 6, 5, 2, 4]
// Output: repeating : 4
//         missing :  1 

#include<bits/stdc++.h>
using namespace std;

void findRepeating(int arr[], int n){
    // finding the repeating number     (creating a visited array)
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1] > 0){
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }   
        else{
            cout<<"Repeating number : "<< abs(arr[i]);
        }
    }

    // finding the missing number -->  idx+1 of that positive number in that array
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            cout<<"Missing number : "<<i+1<<endl;  
        }
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main(){
    int arr[] = { 1, 2, 4, 8, 9, 7, 6, 8};
    int n = sizeof(arr)/sizeof(int);
    display(arr, n);
    findRepeating(arr, n);
    display(arr,n);

    return 0;

    return 0;
}