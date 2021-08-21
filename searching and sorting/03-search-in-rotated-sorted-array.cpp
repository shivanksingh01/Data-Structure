//  Search in Rotated Sorted Array
// Input: nums = [4,5,6,7,0,1,2], key = 0
// Output: 4

#include<iostream>
#include<vector>
using namespace std;


int searchRotatedArray(vector<int>& v, int key) {
        int low = 0, high = v.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(v[mid]==key)
                return mid;
//               check if the left sub array is sorted 
            else if(v[mid] >= v[low]){
//               check for key , if key lies in this half or other half
                if(v[mid] >= key and v[low]<= key)
                    high = mid-1;
                else
                    low = mid+1;
            }
//             check if right sub array is sorted
            else if(v[mid]<=v[high])
//                 then search for key, if key lies ij this half or other half
                if(v[mid]<=key and v[high] >= key)
                    low = mid+1;
                else
                    high = mid - 1 ;
            }
        return -1;
    }

    int main(){
        vector<int> v={ 4, 5, 6, 7, 0, 1, 2 };
        int key = 6;
        cout<<"index : "<<searchRotatedArray(v, key)<<endl;;
        return 0;
    }