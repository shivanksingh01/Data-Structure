//  binary search --> on sorted array   takes log(n) operations
// ex - telephone dircetory
//      index  :  0, 1, 2, 3, 4, 5, 6, 7, 8
// input arr[] : 2, 3, 4, 8, 12, 15, 19, 20
//          k  : 8
//      output : 8 is present at position : 4    (index : 3)


#include<stdio.h>

void  binarySearch(int arr[], int n , int key ){
    int low = 0;
    int high = n-1;
    int found = 0;
    while(low <= high){
        int mid = low+(high-low)/2;
        if (key==arr[mid]){
            found = 1;
            printf("%d is present at position :  %d\n ", key, mid+1);
            break;
        }
        else if (key< arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    if (low>high && found ==0)
        printf("\nElemnt does not exist\n");
}


void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    display(arr, n);
    int key = 12;
    printf("\nsearching : %d   ...............\n", key);
    binarySearch(arr, n, key);
}
