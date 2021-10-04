// N-meeting in one room   (activity selection problem)
// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) 
// where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room 
// when only one meeting can be held in the meeting room at a particular time?
// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Input: N = 6
//     start[] = {1,3,0,5,8,5}
//     end[] =  {2,4,6,7,9,9}
// Output: 4



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// comprator function
static bool comp(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}


int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {start[i], end[i]};
    sort(v.begin(), v.end(), comp);
    int i = 0; // i from zero index
    int j = 1; // j from 1 index (1 index ahead of i)
    //compare (i.second , j.first )
    int count = 1;
    while (j < n)
    {
        if (v[i].second < v[j].first)
        {
            count++;
            i = j;
            j++;
        }
        else
            j++;
    }
    return count;
}


// driver code
int main(){
    int n;
    cout<<"Enter the total number of meetings : ";
    cin>>n;
    int start[n], end[n];
    cout<<"Enter their start and finish time : "<<endl;
    for (int i = 0; i < n; i++){
        cout<<"["<<i+1<<"] : ";
        cin>>start[i]>>end[i];
    }
    cout<<"Max no. of meeting that can held : "<<maxMeetings(start, end, n)<<endl;
    

    return 0;
}