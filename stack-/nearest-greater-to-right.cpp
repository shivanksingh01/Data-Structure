// Find the next greater element for every array element
// Given an integer array, find the next greater element for every array element. 
// The next greater element of a number x is the first greater number to the right of x in the array.
// Input:  [2, 7, 3, 5, 4, 6, 8]
// Output: [7, 8, 5, 6, 6, 8, -1]


#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*
using bruteforce approach (simple)
void nearestGreaterRight(int arr[], int n){
    int next;
    for (int i = 0; i < n; i++)
    {   
        next = -1;
        for (int j = i+1 ; j < n; j++)
        {
            if(arr[i] < arr[j]){
                next = arr[j];
                break;
            }
        }
        cout<<next<<"    ";
    }
}
*/



/*
// uisng stack based implementation
void nearestGreaterRight(int arr[], int n){
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        while (s.empty()==false and s.top() < arr[i]) 
            s.pop();
        s.push(arr[i]);
    }
    
    while (s.empty() == false)
    {
        cout<<"-1";
        s.pop();
    }
}
*/





vector<int> nearestGreaterRight(int arr[], int n){
    vector<int> v(n, -1);   //create vector of size n and initialize with -1
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and arr[s.top()] < arr[i]) // check if stack is empty -- push(i)
        {
            v[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return v;
}





// vector<int> nearestGreaterRight(int arr[], int n){
//     vector<int> v;
//     stack<int> s;
//     for (int i = n-1 ; i >= 0; i-- ){
//         if (s.size() == 0)
//             v.push_back(-1);
//         else if (s.size() > 0 and s.top() > arr[i])
//             v.push_back(s.top());
        
//         else if (s.size() > 0 and s.top() <= arr[i])    
//         {
//             while (s.size() > 0 and s.top() <= arr[i])
//                 s.pop();
//             if(s.size() == 0)
//                 v.push_back(-1);
//             else
//                 v.push_back(s.top());
//         }
//         s.push(arr[i]);
//     }
//     return v;
// }





vector<int> nearestGreaterRight(int arr[], int n)
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





void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"    ";
    }
    cout<<endl;
}

int main(){
    int arr[] = { 4, 5, 2, 25, 7, 8};
    int n = sizeof(arr)/sizeof(int);
    display(arr, n);

    vector<int> result = nearestGreaterRight(arr, n);
    for(int i: result)
        cout<<i<<"    ";
    cout<<endl;
    return 0;
}