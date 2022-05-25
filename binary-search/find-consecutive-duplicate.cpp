// Find Consecutive Duplicate using stl

// find_adjacent(start, end)
// Searches the range [first, last) for the first occurrence of two consecutive elements that match,
// and returns an iterator to the first of these two elements, or last if no such pair is found.
// Elements are compared using the given binary predicate p or using ==.
//  Time Complexity : Linear between start and end


// 1. without binary predicate
// Given a sorted array of n elements containing all unique elements but one,
// the task is to find the repeating element in the array.
// inoput : { 6, 8, 9, 14, 14, 12 }
// output :  14

#include <bits/stdc++.h>
using namespace std;

int consecutiveDuplicate(vector<int> &arr){
    if (arr.size() == 0){
        exit(-1);
    }

    auto it = adjacent_find(arr.begin(), arr.end());
    return *it;
}

int main(){
    vector<int> arr = {6, 8, 9, 14, 14, 12};
    cout << consecutiveDuplicate(arr); // output - 14
    return 0;
}

//  2. with using Binary predicate
// ForwardIt adjacent_find( ForwardIt first, ForwardIt last, BinaryPredicate p );
// Given a container of size n, and a range between [0 … n],
// write a program to check if it is sorted in ascending order or not.
// Equal values are allowed in array and two consecutive equal values are considered sorted.

// Input : 2 5 9 4 // Range = 3
// Output : Sorted in given range.

// Input : 3 5 1 9 // Range = 3
// Output : Not sorted in given range.

int main(){
    vector<int> vec{0, 1, 2, 5, 40, 40, 41, 41, 5};
    int range1 = 5; // Index 0 to 4
    int range2 = 9; // Index 0 to 8
    vector<int>::iterator it;
    // Iterating from 0 to range1,
    // till we get a decreasing element
    it = std::adjacent_find(vec.begin(), vec.begin() + range1, greater<int>());

    if (it == vec.begin() + range1)
        cout << "Sorted in the range : " << range1 << std::endl;
    else
        cout << "Not sorted in the range : " << range1 << std::endl;

    // Iterating from 0 to range2,
    // till we get a decreasing element
    it = std::adjacent_find(vec.begin(), vec.begin() + range2, std::greater<int>());
    if (it == vec.begin() + range2)
        std::cout << "Sorted in the range : " << range2 << std::endl;
    else
        std::cout << "Not sorted in the range : " << range2 << std::endl;
}
