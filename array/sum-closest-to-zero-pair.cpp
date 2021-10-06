// Two elements whose sum is closest to zero
// An Array of integers is given, both +ve and -ve. 
// We need to find the two elements such that their sum is closest to zero.
// input arr : 1, 60, -10, 70, -80, 85
// output pair : (-80, 85)   --> -80+85=5 , closest to zero
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// code -  quickSort
// void swap(int* x, int* y){
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
// int partition(int arr[], int low, int high){
//     int pivot = arr[high];
//     int i = low-1;

//     for(int j = low; j<=high-1;j++){
//         if (arr[j]<=pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i+1], &arr[high]);
//     return i+1;
// }

// void quickSort(int arr[], int low, int high){
//     if (low<high)
//     {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi-1);
//         quickSort(arr, pi+1, high);
//     }
// }

// Time complexity : T(n) =  O(n.logn)(insertion sort) + O(n)(traversing) = O(n.logn) 
// Algorithm 
// 1) Sort all the elements of the input array. 
// 2) Use two index variables low = 0 and high = n-1 to traverse from left and right ends respectively.
// 3) sum = a[low] + a[high] 
// 4) If sum is -ve, then low++ 
// 5) If sum is +ve, then high-– 
// 6) Keep track of abs min sum.  , update minSum if(sum<minSum)
// 7) Repeat steps 3, 4, 5 and 6 while l < r

void minAbsSumPair(int arr[],int n){
    int sum , minSum = INT_MAX;
    int low = 0, high = n-1;
    int min_lidx = low, min_hidx = n-1;

    if (n<2){      // arr shouldhave atleast two elemnts
        cout<<"invalid input"<<endl;
        return;
    }
    sort(arr, arr+n);   // sort  array elemnts 
    
    while (low<high)
    {
        sum = arr[low]+arr[high];

        if(abs(sum) < abs(minSum)){
            minSum=sum;
            min_lidx=low;
            min_hidx=high;
        }
        if (sum<0)
            low++;
        else
            high--;     
    }
    printf("sum closest to zero pair : ( %d , %d )", arr[min_lidx], arr[min_hidx]);
}

int main(){
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr)/sizeof(arr[0]);

    minAbsSumPair(arr, n);
    return 0;
}