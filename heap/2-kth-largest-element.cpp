// Find k’th largest element in an array
// Input:  arr = [7, 4, 6, 3, 9, 1]
//           k = 3

// Output:   k’th largest array element :  4

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthlargest(vector<int> &v, int k)
{   // creating min-heap using priority queue
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < v.size(); i++)  // insert elemnts into min-heap
    {
        minh.push(v[i]);
        // if size of exceeds than k --> pop the root elemnt
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    return minh.top();    // return the root of min-heap
}


int kthlargest(vector<int> &v, int k){
    // creating min-heap using priority queue
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < k; i++)  // inserting first k elemnts in heap
    {
        minh.push(v[i]);
    }
    for (int i = k; i < v.size(); i++)  // do for remaining elemnts
    {
        if(v[i] >  minh.top()){    //// if the current element is more than the root of the heap
            // replace root with the current element
            minh.pop();
            minh.push(v[i]);
        }
    }
    return minh.top();  // return the root of min-heap
}

// driver code
int main()
{
    vector<int> v = {7, 11, 6, 3, 9, 1, 15, 2, 10, 5 , 14};
    int k = 4;
    cout << k << " th "
         << "largest elemnt in array : " << kthlargest(v, k) << endl;
    return 0;
}
