// find first occurence and last occurence of a given elemnt in array
// count the number of occurences
//     index      0  1  2  3  4  5  6  7  8  9  10  11
// input  arr[] : 1, 2, 3, 3, 3, 3, 3, 3, 4, 5 ,7 , 9
//          key : 3
//       output : first occurence : 2
//                last ocurrence  : 7  
//     total number of occuremces : 6
#include<stdio.h>

int firstOccurence(int arr[], int n, int key){
    int low = 0;
    int high = n-1;
    int res = -1;
    while (low<=high){
        int mid = low + (high-low)/2;
        if (key==arr[mid]){
            res =mid;     
            high = mid - 1;       // first occurence will always be on the left side of mid
        }
        else if (key<arr[mid])
            high = mid-1;
        else
            low = mid +1;
    }
    return res;  
    // res = index of first occurence of element if found , else ->  = -1
}
    
int lastOccurence(int arr[], int n, int key){
    int low = 0;
    int high= n-1;
    int res = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if (key==arr[mid])
        {
            res = mid; 
            low = mid+1;
        }
        else if (key<arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return res;
     // res = index of last occurence of element if found , else -> res = -1
}
    
int countOccurence(arr, n, key){
    // total occurences = last - first + 1
    int totalOcurrences = lastOccurence(arr, n, key) - firstOccurence(arr, n, key) + 1;
    return totalOcurrences;
}

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {20, 30, 40, 40, 40, 40, 40, 40, 50, 80,  100};
    int n = sizeof(arr)/sizeof(int);
    int key = 40;
    display(arr, n);
    printf("\nsearching : %d   ...............\n", key);
    printf("first occurence of %d at index : %d\n", key, firstOccurence(arr, n, key));
    printf("last occurence  %d  at index  :  %d\n", key, lastOccurence(arr, n, key));
    printf("search ended ..................\n");
    printf("counting total number of occurences .....\n");
    printf("count : %d\n", countOccurence(arr, n, key));
    return 0;
}