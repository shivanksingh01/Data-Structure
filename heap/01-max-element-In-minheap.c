

#include <stdio.h>
#include<limits.h>

int maxElementInMinHeap(int arr[], int n){
    int max = INT_MIN;
    for(int i=(n+1)/2;i<n;i++){   // searching in leaf-nodes
        if(arr[i] > max)
            max= arr[i];
    }
    return max;
}

int main() {
    int arr[] ={12, 11, 13, 5, 6, 7, 15, 10};
    int n=sizeof(arr)/sizeof(int);
    int x = maxElementInMinHeap(arr, n);
    printf("%d", x);
}
