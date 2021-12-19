// segregate positive and negative elemnts in an array
// Move all negative elemnts to one side of array
// Input  :  12  11  -13  -5  6  -7  5  -3  -6
// Output : -13  -5  -7  -3  -6  12  11  6  5  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void segregatePosNeg(int arr[], int n){
    int j = -1;
    int pivot = 0;
    for(int i=0;i<n;i++){
        if(arr[i]< pivot){
            j++;  
            // j will keep track of last negative elemnt in segregated array
            // swap(arr[i], arr[j])
            int temp=arr[i];
            arr[i]= arr[j];
            arr[j]=temp;
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
    int arr[] = {2, -1, 4, 5, -8, 6, -11, 10};
    int n = sizeof(arr)/sizeof(n);   
    display(arr, n);
    segregatePosNeg(arr, n);
    display(arr,n);

    return 0;
}