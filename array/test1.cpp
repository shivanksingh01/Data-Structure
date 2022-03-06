#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t != 0){
        int n;
        string s;
        cin >> n;
        cin >> s;
        queue<char> q;
        int i = 0;
        while (i < n){
            q.push(s[i]);
            i++;
        }
        bool a = true;
        int k = q.size();
        i = 0;
        while (q.size() >= 2 && i < k){
            char x = q.front();
            q.pop();
            char y = q.front();
            q.pop();
            if ((x == '0' && y == '0') || (x == '1' && y == '1')){
                q.push(x);
                q.push(y);
                i++;
            }
            else{
                i = 0;
                k = q.size();
                a = !a;
            }
        }
        if (a == true)
            cout << "Joe" << endl;
        else
            cout << "John" << endl;    
        
        t--;
    }

    return 0;
}