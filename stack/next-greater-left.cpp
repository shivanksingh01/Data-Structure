#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using bruteforce
// void nearestGreaterLeft(int arr[], int n)
// {   
//     int next;
//     for (int i = 0; i < n; i++)
//     {
//         next = -1;
//         for (int j = i - 1; j >= 0; j--)
//         {
//             if (arr[i] < arr[j])
//             {
//                 next = arr[j];
//                 break;
//             }
//         }
//         cout<<next<<"    ";
//     }
//     cout<<endl;
// }

// using stack
// void nearestGreaterLeft(int arr[], int n){
//     stack<int> s;
//     s.push(arr[0]);
//     for (int i = 0 ; i < n ; i++)
//     {
//         if (s.empty())
//         {
//             s.push(arr[i]);
//             continue;
//         }
//         while (s.empty()==false and s.top() < arr[i]) 
//             s.pop();
//         s.push(arr[i]);
//     }
    
//     while (s.empty() == false)
//     {
//         cout<<"-1";
//         s.pop();
//     }
// }



// using s5tack
vector<int> nearestGreaterLeft(int arr[], int n)
{
    vector<int> v(n, -1);
    // create an empty stack
    stack<int> s;
    // process each element from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // loop till we have a greater element on top or stack becomes empty.
        while (!s.empty())
        {
            // pop elements that aren't greater than the current element
            if (s.top() <= arr[i]) {
                s.pop();
            }
            // the next greater element is now on the top of the stack
            else {
                v[i] = s.top();
                break;
            }
        }
        // push current element into the stack
        s.push(arr[i]);
    }
    return v;
}


void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "    ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 2, 25, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    display(arr, n);
    nearestGreaterLeft(arr, n);
    // vector<int> result = nearestGreaterLeft(arr, n);
    // for (int i : result)
    //     cout << i << "    ";
    // cout << endl;
    return 0;
}
