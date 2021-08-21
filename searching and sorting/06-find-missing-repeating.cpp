// Find Missing And Repeating
// Given an unsorted array Arr of size N of positive integers.
// One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// input : N = 3
//         Arr[] = {1, 3, 3}
// Output: 3 2
// Explanation: Repeating number is 3 and smallest positive missing number is 2.

// input :  n  =  5
//          arr[] = { 2, 4, 1, 2, 5}
//  output : 2  3   (2 --> repeating , 3--> missing )
// using hash make a frequency table   ( freq 0 --> missing , freq. 2 --> repeating twice)
// 1 --> 1
// 2 --> 2
// 3 --> 0
// 4 --> 1
// 5 --> 1

#include <bits/stdc++.h>
using namespace std;

int *repeatingAndMissing(int arr[], int n)
{
    int a, b;

    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] < 0)
            a = abs(arr[i]);   // repeating 
        else
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            b = i + 1;   // missing
            break;
        }
    }

    int *v = new int[2];
    v[0] = a;
    v[1] = b;

    return v;
}

int main()
{
    int arr[] = {2, 4, 1, 2, 5};
    int n = sizeof(arr)/ sizeof(int);
    auto res = repeatingAndMissing(arr, n);
    cout<<"repeating : "<<res[0]<<endl;
    cout<<"missing : "<<res[1]<<endl;
    return 0;
}