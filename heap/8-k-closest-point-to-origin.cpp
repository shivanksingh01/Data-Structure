#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void kclosestpointtoorigin( vector<vector<int>> &v, int k){
    priority_queue< pair< int, pair<int, int>>> maxh;
    // calculate distance from origin (0, 0) ---> (1, 3)    
    // sqrt(1^2 + 3^2)  = sqrt(10)   ....Neglecting the root for easier calulation, it does not affect our solution
    for (int i = 0; i < v.size(); i++){
        maxh.push({ (v[i][0]*v[i][0] + v[i][1]*v[i][1]), {v[i][0],v[i][1]} });
    }
    // do not exceed size of max-heap --> pop elemnts
    if (maxh.size() > k)
    {
        maxh.pop();
    }
    // displaying the elemnt from our final max-heap of k size, and popping out elemnts
    while (maxh.size() > 0)
    {
        pair<int, int> p = maxh.top().second;
        cout<< p.first <<", "<<p.second<<endl;
        maxh.pop();
    }
}


int main(){
    vector<vector<int>> v = {{1,3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    kclosestpointtoorigin(v, k); 
    return 0;
}