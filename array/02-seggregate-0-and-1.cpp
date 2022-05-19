/* 
Segregate 0 and 1 in an array
Input  Arr : 0 1 1 1 0 0 0 1 0 1
Output Arr : 0 0 0 0 0 1 1 1 1 1
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------------
// Approach-1 (naive approach)
// step1 - count the number of 0 and 1
// step2 - populate the array with 0 and 1
// Time Complexity : T(n) = O(n)

// void segregate0and1(int arr[], int n){
//     int count0 = 0;  // store the count of 0
//     for (int i = 0; i<n; i++){
//         if (arr[i]== 0)
//             count0++;
//     }
//    //  fill the array with 0 then with 1
//     for (int i = 0; i < count0; i++)
//         arr[i] = 0;
//     for (int i = count0; i < n; i++)
//         arr[i] = 1;
// }

// ---------------------------------------------------------------------
// Approach-2   Duthch Flag algorithm
// initialize two variable low = 0 and high = n-1
// find first 1 by moving low from left to right
// find first 0 by moving high from right to left
// swap(arr[low], arr[high])
// repeat till low < high
//  Time Complexity : T(n) = O(n)

void segregate0and1(int arr[], int n){
    int low = 0;
    int high =n-1;
    while (low<high)
    {
        while(arr[low] != 1 && low<high)  // traverse from left to right till we find 1
            low++;
        while(arr[high] != 0 && low<high) // traverse from right to left till we find 0
            high--;

        //  if low < high that means 1 is at left and 0 at right, swap them
        if(low < high){
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
        // since there are only 0 and 1, we can also set the value to 0 and 1
        // if(low<high){
        //     arr[low] = 0;     or   arr[low++] = 0;
        //     arr[high] = 1;         arr[high--] = 1;
        //     low++;  high--;
        // }
    }
}



void display(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<"    ";
}

int main(){
    int arr[] = {0, 1, 1, 0, 0, 1, 0, 1, 0, 0};   // array contain only 0 and 1
    int n = sizeof(arr)/sizeof(int);
    cout<<"input array  : ";
    display(arr, n);
    segregate0and1(arr, n);

    cout<<"\nOutput array : ";
    display(arr,n);
    return 0;
}
