

// remove duplicate from sorted array
#include<bits.stdc++.h>
using namespace std;


int removeDuplicates(vector<int> &nums){
    int n = nums.size();

    if (n == 0 || n == 1){ 
        return n;   // if array size is 0 or 1
    }

    // int j=0;
    // for(int i=1; i<n; i++){
    //     if(nums[i]!=nums[j]){
    //         j++;
    //         nums[j] = nums[i];
    //     }
    // }
    // return j+1;

    // index will move only when we modify th array inplace
    // to include a new non duplicate elemnt
    int j = 0; // to keep track of number of unique elemnts
    for (int i = 0; i < n; i++){ // to iterate over array
        // if current elemnt is equal to next elemnt , then it is duplicate
        // do nothing (continue)
        if (nums[i] == nums[i + 1] &&  i<n-1){
            continue;
        }
        nums[j] = nums[i]; // insert (modify original array)
        j++;
    }
    return j;
}

//     uisng hashmap (unordered map)
//     time complexity = O(n)
//     space complexity = O(n)
int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();

    if (n == 0 || n == 1)
    { // if array size is 0 or 1
        return n;
    }

    int j = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        if (umap.find(nums[i]) == umap.end())
        {
            nums[j++] = nums[i];
        }
        umap[nums[i]]++;
    }
    return j;
}



int main(){
    vector<int> nums= {};
    display(nums);
    x = removeDuplicates(nums);
    display(arr,x);

    return 0;
}