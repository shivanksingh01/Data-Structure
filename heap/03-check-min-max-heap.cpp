// Check if an array represents a min-heap or not

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Check if an array represents a min-heap or not
// If the current node is a leaf node, return true as every leaf node is a heap.
// If the current node is internal node : 
//     Recursively check if the left child is min-heap or not.
//     Recursively check if the right child is min-heap or not (if it exists).
//     Return true if both left and right child are min-heap; otherwise, return false.

bool checkMinHeap(vector<int> const arr, int i){
    int n = arr.size();
    
    if(2*i+2 <= n)  // internal-node (recusion base-case)
        return true;
    bool left  = (arr[i]<=arr[2*i+1]) && checkMinHeap(arr, 2*i+1);
    bool right = (arr[i]<=arr[2*i+2]) && checkMinHeap(arr, 2*i+2);

    return left && right;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    int idx=0;
    if(checkMinHeap(v, idx)){
        cout<<"min-heap"<<endl;
    }
    else
        cout<<"max-heap"<<endl;

    return 0;
}
