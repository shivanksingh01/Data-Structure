int search(int arr[],int n, int key){
//     int low=0;
//     int high=n-1;
//     while (low<=high){
//         int mid = low +(high-low)/2;
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if(arr[mid-1]==key &&  mid-1>low){
//             return mid-1;
//         }
//         else if(arr[mid+1]==key  && mid+1<high)
//             return mid+1;
//         else if(key<arr[mid]){
//             high = mid-2;
//         }
//         else if(key> arr[mid]){
//             low = mid+2;
//         }
//     }
//     return -1;
// }