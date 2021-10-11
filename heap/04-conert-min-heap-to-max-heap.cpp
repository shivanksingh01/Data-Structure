#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x=*y;
    *y=temp;
}

void maxHeapify(int arr[], int n, int i){
    int left= 2*i+1;
    int right=2*i+2;
    
    int max = i;

    if(arr[left]>arr[i]  && left<n)
        max = left;
    if(arr[right]>arr[max] && right<n)
        max = right;
    if(max!=i){
        swap(&arr[i], &arr[max]);
        maxHeapify(arr, n, max);
    }
}

void convertToMaxHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--)   
        maxHeapify(arr, n, i);
}


void display(int arr[], int n){
    for(int i=0; i<n;i++)
        printf("%d\t", arr[i]);
    cout<<endl;
}

int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};  // min-heap
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"min-heap : "<<endl;
    display(arr, n);
    convertToMaxHeap(arr, n);
    cout<<"max-heap : "<<endl;
    display(arr,n);
}
