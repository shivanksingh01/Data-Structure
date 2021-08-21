// top k most frequent elemnt in an array
//  input arr : 1  1  1  2  3  3  4  5
//          k : 2
//     output : 1  3
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void topkfrequentelements(vector<int> &v, int k)
{
    // creating an unordered map from array elemnts , that contains elemnt and there frequencies
    unordered_map<int, int> umap;
    for (int i = 0; i < v.size(); i++)
    {
        umap[v[i]]++;
    }
    // creating a max heap
    // copying the element from unordered-map to max-heap, sorting them based on their frequencies
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    for (auto i = umap.begin(); i != umap.end(); i++)
    {
        minh.push({i->second, i->first});
        if (minh.size() > k)
        {
            minh.pop();
        }
    }
    // displaying the elemnts from min-heap
    while (minh.size() > 0)
    {
        cout << minh.top().second << "    ";
        minh.pop();
    }
}

int main()
{
    vector<int> v = {1, 1, 1, 2, 3, 3, 4, 5, 5, 5, 5};
    int k = 3;
    topkfrequentelements(v, k); // output :  3  1  5

    return 0;
}