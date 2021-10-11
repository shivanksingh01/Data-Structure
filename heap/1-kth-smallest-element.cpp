// Find k’th smallest element in an array
// Input:  arr = [7, 4, 6, 3, 9, 1]
//           k = 3
// Output:   k’th smallest array element :  4

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthsmallest(vector<int> v, int k){
    // creating max-heap using priority queue
    priority_queue<int> maxh;
    for (int i = 0; i <v.size()  ; i++)
    {
        maxh.push(v[i]);
        if(maxh.size() > k){
            maxh.pop();
        }
    }
    return maxh.top();
}

// or
int kthsmallest(vector<int> v, int k){
    priority_queue<int> maxh(v.begin(), v.begin() + k);  // insert firsk k array elemnt in heap
    for (int i = k ; i<v.size() ; i++ )   
    {
        if (v[i] < maxh.top())    // if current elemnt is less than the root of heap , replace the root with current arr ele        {
            maxh.pop();
            maxh.push(v[i]);
        }
    }
    return maxh.top();  // return root of max-heap
}

// driver code
int main(){
    vector<int> v = {7, 11, 6, 3, 9, 1, 15,  2, 5};
    int k = 4;
    cout<<k<<" th"<<"smallest elemnt in array : "<<kthsmallest(v, k)<<endl;
    return 0;
}
