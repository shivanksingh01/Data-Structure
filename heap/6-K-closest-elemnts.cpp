// `k` closest elements to a given value in an array
// Input:  [10, 12, 15, 17, 18, 20, 25]
// k = 4, x = 16
// Output: [12, 15, 17, 18]

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void kclosestNumbers(vector<int> &v, int x, int k){
    priority_queue< pair<int, int> > maxh;
    for (int i = 0; i < v.size(); i++){
        maxh.push({abs(v[i]-x), v[i]});
        if (maxh.size() > k){
            maxh.pop();
        }
    }
    while (maxh.size()>0){
        cout<<maxh.top().second<<"    ";
        maxh.pop();
    }
}

//  method --> 2

// void kclosestNumbers(vector<int> &v, int x, int k){
//     priority_queue< pair<int, int> > maxh;
//     for (int i = 0; i < k; i++)
//     {
//         maxh.push( { abs(v[i]-x) , i } );
//     }
//     for (int i = k; i < v.size(); i++)
//     {
//         int diff = abs(v[i] - x);
//         if (diff > maxh.top().first)
//         {
//             continue;
//         }
//         else{
//             maxh.pop();
//             maxh.push({diff, i});
//         }
//     }
// }
    
//     while (maxh.empty() == false)
//     {
//         cout<<v[maxh.top().second]<< "    ";
//         maxh.pop();
//     }
// }

int  main(){
    vector<int> v = {48, 50, 55, 30, 39, 35, 42, 45, 12, 16, 53, 22, 56}; 
    int x = 35;
    int k = 5;
    kclosestNumbers(v, x, k);

    return 0;
}