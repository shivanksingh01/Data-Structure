//  order agnostic search (order not known ---->  ascending / descending)
//        index :  0     1    2    3    4    5    6    7    8    9
//  input arr[] :  100   90   80   70   60   50   40   30   20   10
//          key :  70
//       output : 70 is present at position : 4

#include<stdio.h>

void binarySearch(int arr[], int n , int key ){
    int low = 0;
    int high = n-1;
    int found = 0;
    while(low <= high){
        int mid = (low+high)/2;
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


void binarySearchReverse(int arr[], int n, int key){
    int low = 0;
    int high = n-1;
    int found = 0;
    while (low<=high)
    {
        int mid = low+ (high-low)/2;
        if(key==arr[mid]){
            found=1;
            printf("Elemnt found at position : %d\n", mid+1);
            break;
        }
        else if (key<=arr[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    if (low>high && found ==0)
        printf("%d not found \n", key);
}

int main(){
    // int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = sizeof(arr)/sizeof(int);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    
    int key = 30;

    printf("\nsearching : %d   ...............\n", key);
    if (arr[0]<arr[1])
        binarySearch(arr, n, key);
    else
        binarySearchReverse(arr, n, key);
    printf("search ended ............ \n");

    return 0;
}