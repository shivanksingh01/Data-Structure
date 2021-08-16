#include<iostream>
#include<queue>
#include<vector>

using namespace std;
void sortksortedarray(vector<int> &v, int k){
    priority_queue<int , vector<int>, greater<int>> minh;
    for (int i = 0; i <= k; i++)
    {
        minh.push(v[i]);
    }
    int index =0;
    for (int i = k+1; i < v.size(); i++)
    {   v[index++] = minh.top();
        minh.pop();

        minh.push(v[i]);
    }
    
    while (!minh.empty())
    {   
        v[index++] = minh.top();
        // v[index] = minh.top();
        // index++;
        minh.pop();
    }
}

int main(){
                  //   1   2   3   4   5   6   7   8   9   10   11   
    vector<int> v = {  1 , 4 , 5 , 6 , 2 , 3 , 8 , 10 , 7 , 9};
    int k = 3;

    sortksortedarray(v, k);
    for(int &i: v){
        cout<<i<<"    ";
    }

}