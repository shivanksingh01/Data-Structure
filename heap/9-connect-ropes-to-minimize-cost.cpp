//  n ropes of different lengths, connect them into a single rope with minimum cost. 
// Assume that the cost to connect two ropes is the same as the sum of their lengths
// Input:  [5, 4, 2, 8]
// Output: The minimum cost is 36

// [5, 4, 2, 8] –> First, connect ropes of lengths 4 and 2 that will cost 6.
// [5, 6, 8]    –> Next, connect ropes of lengths 5 and 6 that will cost 11.
// [11, 8]      –> Finally, connect the remaining two ropes that will cost 19.
// Therefore, the total cost for connecting all ropes is 6 + 11 + 19 = 36.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void mincost(vector<int> &v){
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < v.size(); i++)
    {
        minh.push(v[i]);
    }
    int totalCost = 0;    // cost = 1 for 1 unit length of ropes
    
    while (minh.size() > 1)   // repeat till heap size become 1 
    {
        int first = minh.top();
        minh.pop();
        int second  = minh.top();
        minh.pop();
        int totalLength = first + second;
        minh.push(totalLength);   // insert the total length of rope back to min-heap
        // calculate the cost of extracted value from min-heap
        int cost = first + second;
        totalCost += cost ;
        
    }
    printf("total minimum cost : %d\n",totalCost );
}

int main(){
    vector<int> v = { 5, 4, 2, 8 };   // array elemnts are length of ropes 
    mincost(v);   // output : 36
    return 0;
}