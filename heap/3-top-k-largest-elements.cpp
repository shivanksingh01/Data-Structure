// find top k largest elemnts in an array
//  input arr[] : 7, 3, 9, 11, 5, 4, 8, 12
//            k : 3
// output arr[] : 8 11 12 


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void klargest(vector<int> &v, int k)
{   // creating a min heap using priority queue
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < k; i++)
    {
        minh.push(v[i]);
    }
    for (int i = k; i < v.size(); i++)
    {
        if (v[i] > minh.top())
        {
            minh.pop();
            minh.push(v[i]);
        }
    }
    vector<int> opv;
    for (int i = 0; i < k; i++)
    {
        opv.push_back(minh.top());
        minh.pop();
    }
    /*  displaying the content of output vector (opv) --> which is containing k largest element 
        for (auto i = opv.begin(); i != opv.end(); ++i)
        cout << *i << "    ";    */
    // or

    for (int i = 0; i < opv.size(); i++)
        cout << opv.at(i) << "    ";
}

// for (int i = 0; i < n; i++)
// {
//     minh.push(arr[i]);
//     if (minh.size() > k){
//         minh.pop();
//     }
// }
// while (minh.size() > 0){
//         cout<<minh.top()<<"    ";
//         minh.pop();
// }


int main()
{
    vector<int> v = {7, 3, 9, 11, 5, 4, 8, 12};
    int k = 3;
    cout << "k largest elemnt : " << endl;
    klargest(v, k);
    // cout<<klargest(arr, n, k);
    return 0;
}
