// heap-sort

#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i which is an index in arr[].
//  n is the size of heap /(arr)
void heapify(int arr[], int n, int i)  {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max])  // if left child is larger than root
        max = left;
    if (right < n && arr[right] > arr[max]) // if right child is larger than max
        max = right;

//     left < n --> index of left child is in bounds of array (i.e. not exceeding the array )
//     right < n --> index of right child is in bounds of array (i.e. not exceeding the array )  : within the rannge
    
    if (max != i){   // if largest is not root
        swap(&arr[i], &arr[max]);   
        //recurrsively heapify the affected sub-tree
        heapify(arr, n, max);
    }
}


void heapsort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)  // build heap
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--){     //extract elemnt from heap one-by-one
        swap(&arr[0], &arr[i]);           // move rpot to end
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// display the array of size n
void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

// driver-code
int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7, 15, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapsort(arr, n);

    printf("sorted array : \n");
    display(arr,n);
}
