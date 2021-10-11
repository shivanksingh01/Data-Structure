// Sort a nearly sorted (or K sorted) array
// Input  : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
//              k = 4
// Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
void sortksortedarray(vector<int> &v, int k)
{ 
    int n = v.size();
    priority_queue<int, vector<int>, greater<int>> minh;   // create a min-heap
    for (int i = 0; i <= k; i++)   // insert first k+1 element in heap
    {
        minh.push(v[i]);
    }
    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        // note :  array[i++] increments the value of i. 
        // The expression evaluates to array[i], before i has been incremented
        
        v[index++] = minh.top();   
        minh.pop();
        minh.push(v[i]);
    }
//  pop all remaining elements from the min-heap and assign them to the next available array index
    while (!minh.empty())
    {
        v[index++] = minh.top();        // v[index] = minh.top();   index++;
        minh.pop();
    }
}

int main()
{
    // sorted arr :   1   2   3   4   5   6   7   8   9   10
    vector<int> v = { 1 , 4 , 5 , 6 , 2 , 3 , 8 , 10 , 7 , 9};
    int k = 3;

    sortksortedarray(v, k);
//     display the sorted array
    for (int &i : v)      // for(auto i: v ){  cout<<i<<"\t";  }
        cout << i << "    ";
}
