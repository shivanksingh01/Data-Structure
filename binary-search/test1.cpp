#include <bits/stdc++.h>
using namespace std;

void duplicates(vector<int> &arr)
{
    int n = arr.size();
    int newarr[n] = {0}; // creating newarray initializing with zero
    for (int i = 0; i < n; i++)
    {
        if (newarr[arr[i]] == 0)
        {
            newarr[arr[i]] = 1;
            cout<<arr[i]<<"  "<<newarr[i]<<"  " << newarr[arr[i]]<<endl;
        }
        else
        {
            cout<<newarr[6]<<endl;
            cout << "repeating : " << arr[i] << endl;
        }
    }
}

int main()
{
    vector<int> arr = {4, 3, 6, 5, 2, 4};
    // int n = sizeof(arr)/ sizeof(int);
    duplicates(arr);
}
