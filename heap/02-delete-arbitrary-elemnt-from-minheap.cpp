

#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void minHeapify(int arr[], int n, int i){    // code to min heapify
    int min = i;
    int left = 2*i+1, right=2*i+2;   
    if(left<n && arr[left] < arr[min]){  // if left chils is less than parent node
        min = left;
    }
    if(right < n && arr[right]<arr[min]){  // if right child is less than parent node
        min = right;
    }
    if(min!=i){   // if left or right is found smallest  
        swap(&arr[i], &arr[min]);   // swap 
        minHeapify(arr, n, min);    // min heapify
    }
}

void buildMinHeap(int arr[], int n)   // funrion to build min heap
{
    for(int i=n/2-1; i>=0;i--)     // start from second non leaf node to root node  i.e. 2-->1-->0
        minHeapify(arr, n, i);     // min heapify
}
void deleteArbitraryElement(int arr[], int *n, int ele){
    int i;
    for(i=0;i< *n ; i++){   // search for element in min heap
        if(arr[i]==ele)
            break;
    }
    // i will have the index value of that elemnt 
    if(i< *n){
            arr[i] = arr[*n-1]; // replace that elemnt will the last node 
            *n = *n-1; // decrease the size of heap
            minHeapify(arr, *n, i);  // min heapify
    }
}

void display(int arr[], int n){  // function to display heap
    for(int i=0; i<n;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] ={12, 11, 13, 5, 6, 7, 15, 10};
    int n=sizeof(arr)/sizeof(int);
    buildMinHeap(arr, n);   // build min heap from arr
    int ele = 13;
    deleteArbitraryElement(arr, &n, ele); // delete element from min heap
    display(arr, n);   // dispalying array
}
