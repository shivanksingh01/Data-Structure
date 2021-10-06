// Equilibrium index of an array
// equlibrium index :  sum of elemnt at lower index = sum of elemnt at higher indexes
// input arr : -7, 1, 5, 2, -4, 3, 0
// output : 3(index)    [-7+1+5 = -4+3+0]

// Approach-1  (Brute-force)   using two loops
// oter iterartes through all elemnts and inner checks current index
// picked by oter is equilibrium or not
// Time-complexity : T(n) = O(n^2)
// space complexity: T(n) = O(1)
int equilibriumIndex(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        int leftSum=0;
        int rightSum = 0;

        for (int j = 0; j < i; j++)
            leftSum += arr[j];
        for(int j = i+1;j<n;j++)
            rightSum += arr[j];

        if (leftSum==rightSum)
            return i;
    }
    return -1;
}

// Approach-2 (optimized)
// step1. get total sum of array first
// step2. iterate array and keep updating left sum initialized to 0
// step3. In loop we can get right sum by subtarcting the elemnt one by one
// step4. compare leftsum and right sum
// Time Complexity: T(n) = O(n)
int equilibriumIndex(int arr[], int n){
    int sum = 0;
    int leftSum=0;
    for (int i = 0; i < n; i++)
        sum+= arr[i];  // sum of all elemnts of array

    for (int i = 0; i < n; i++){
        sum = sum - arr[i]; // rightSum
        if(leftSum==sum)    // if leftSum==RightSum
            return i;       // return index
        leftSum += arr[i];  //calculating leftSum
    }
    return -1;   // no equilibrium index found
}

// Approach-3
// Time Complexity: T(n) = O(n)
// space complexity : O(n)
int equilibriumIndex(int arr[], int n){
    int fwd[n], rev[n];
    // fwd[] = stores forward sum/ left Sum
    // rev[] = stores reverse sum/ rightsum 
    for (int i = 0; i < n; i++){
        if(i)
            fwd[i] = fwd[i-1]+arr[i];
        else
            fwd[i] = arr[i];  // for the first element (to store as it is)
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (i<=n-2)
            rev[i] = rev[i+1] + arr[i];
        else    
            rev[i] = arr[i];  // for last element (to store as it is)
    }

    for (int i = 0; i < n; i++){
        if (fwd[i]==rev[i])
            return i;
    }
    return -1;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr)/sizeof(int);
    cout<<equilibriumIndex(arr, n);
    return 0;
}