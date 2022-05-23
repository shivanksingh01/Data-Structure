// Find first occurence of 1 in infinite binary array

#include <iostream>
using namespace std;

int infiniteBinaryArraySearch(int arr[], int key){
    int low = 0;
    int high = low + 1;
    while (arr[high] < key){
        low = high;
        high = high * 2;
    }
    // find first occurence of 1 using binary search
    int res = -1;
    while (low<=high){
        // int res=-1;
        int mid = low + (high-low)/2;
        if(arr[mid]==key){
            res=mid;     // make it a candidate , and search in left sub array also for the possible candidates
            high=mid-1;  // bcz, searching for first occurence, it will be always in the left subarray
        }
        else if(arr[mid]<key){
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;
}

int main()
{
    // infinite array ..... we don't know the end ...so find index for high
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int key = 1; // output : 12
    cout << infiniteBinaryArraySearch(arr, key);
    cout<<"hello"<<endl;
    return 0;
}