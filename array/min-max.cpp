// maximium and minimum elemnt in array
#include<bits/stdc++.h>
using namespace std;

void minMax(int arr[], int n){
    int min  = arr[0];
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    cout<<"minimum elemnt in array : "<<min<<endl;
    cout<<"maximum elemnt in array : "<<max<<endl;
}



// using divide and conquer
// void MinAndMax(int arr[], int low, int high, int &min, int &max)
// {
//     if (low == high)   // if array has only one elemnt             
//     {
//         if (max < arr[low]) {          
//             max = arr[low];
//         }
 
//         if (min > arr[high]) {    
//             min = arr[high];
//         }
//         return;
//     }
//     if (high - low == 1)   // if array has only two elwmnts
//     {
//         if (arr[low] < arr[high]){
//             if (min > arr[low]) {       
//                 min = arr[low];
//             }
 
//             if (max < arr[high]) {      
//                 max = arr[high];
//             }
//         }
//         else {
//             if (min > arr[high]) {      
//                 min = arr[high];
//             }
 
//             if (max < arr[low]) {     
//                 max = arr[low];
//             }
//         }
//         return;
//     }
//     int mid = (low + high) / 2;
//     MinAndMax(arr, low, mid, min, max);
//     MinAndMax(arr, mid + 1, high, min, max);
// }

// display array
void display(int arr[], int n){
    for (int i = 0; i < n; i++)    {
        cout<<arr[i]<<"    ";
    }
    cout<<endl;  
}



int main(){
    int arr[] = {8, 5, 60, 15, 290, 400, 1,  9, 2, 11, 14, 23, 30, 18, 5};
    int n = sizeof(arr)/sizeof(n);
    int low = 0 , high = n-1;
    int min = INT_MAX, max = INT_MIN;

    display(arr, n);
    // MinAndMax(arr, low, high, min, max);
    minMax(arr, n);

    return 0;
}