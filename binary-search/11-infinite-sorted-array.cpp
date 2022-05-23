// Find position(index) of element in infinite sorted array
//


#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int key){
    while(low<=high){
        int mid = low+(high-low)/2;
        if (arr[mid]==key){
            return mid;
        }
        else if(arr[mid]<key){
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int infiniteBinarySearch(int arr[], int key){
    int low=0;
    int high = low+1;
    // we have to make our key in between of our search space i.e. (in between low and high)
    while (arr[high]< key){
        low = high;
        high = high*2;
        // cout << "low : " << low << "    high : " << high << endl;
    }
    // perform normal binary search using the updated low and high
    return binarySearch(arr, low, high, key);
}

int main(){
    // infinite array ..... we don't know the end ...so find index for high
    int arr[] = {2,3,4,5,6,7,8,9,11,13,15,16,18,19,20,21,22,23,26,29,35,37,38,42,48,51,78,89,543};
    int key = 18;  // output : 12
    cout<<infiniteBinarySearch(arr, key);
    return 0;
}