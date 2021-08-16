//  find k smallest elemnts in an array
//  input arr[] : 7, 3, 9, 11, 5, 4, 8, 12
//            k : 3
// output arr[] : 5, 4, 3


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void ksmallest(vector<int> &v, int k)
{   // creating a min heap using priority queue
    priority_queue<int> maxh;
    for (int i = 0; i < k; i++)
    {
        maxh.push(v[i]);
    }
    for (int i = k; i < v.size(); i++)
    {
        if (v[i] < maxh.top())
        {
            maxh.pop();
            maxh.push(v[i]);
        }
    }
    // storing k smallest elemnts in another vector 
    vector<int> opv;
    for (int i = 0; i < k; i++)
    {
        opv.push_back(maxh.top());
        maxh.pop();
    }
    // displaying the vector
    for (int i = 0; i < opv.size(); i++)
    {
        cout<<opv.at(i)<<"    ";
    }
}

int main()
{
    vector<int> v = {7, 3, 9, 11, 5, 4, 8, 12};
    int k = 3;
    cout << k<<" smallest element : " << endl;
    ksmallest(v, k);
    return 0;
}
