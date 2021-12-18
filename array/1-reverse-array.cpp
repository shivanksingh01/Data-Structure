// program to reverse an array or string
// Input :  arr[] = {4, 5, 1, 2}
// Output : arr[] = {2, 1, 5, 4}

// explanantion : low = 0, high = n-1
//                swap(low, high)
//                low++, high--

#include<bits/stdc++.h>
using namespace std;

// void swap(int *x, int *y){
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

void reverseArray(int arr[], int n){
    int low = 0;
    int high = n-1;
    while (low<high)
    {
        // swap(&arr[low], &arr[high]);
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

void display(int arr[], int n){
    for (int i = 0; i < n; i++)    {
        cout<<arr[i]<<"    ";
    }
    cout<<endl;  
}

int main(){
    int arr[] =  {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(n);
    display(arr, n);
    reverseArray(arr, n);
    display(arr, n);

    return 0;
}