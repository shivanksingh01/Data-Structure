// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// Input1: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

// note : 

// four is written as IV. 
// Because the one is before the five we subtract it making four. 
// The same principle applies to the number nine, which is written as IX. 
// There are six instances where subtraction is used
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.

// logic : 
// start from end characrter:
//          if next is less than current :: subtract
//          if next is greater than current :: add
//      M       C       M       X       I       V
//      1000   100     1000    10      1        5
//      5 - 1 + 10 + 1000 - 100 + 1000 =  1994

#include<bits/stdc++.h>

using namespace std;
int romanToInt(string str) {
        unordered_map<char, int> umap = {{'I', 1},
                                         {'V', 5},
                                         {'X', 10},
                                         {'L', 50},
                                         {'C',100},
                                         {'D',500},
                                         {'M',100}
                                        };
        
         if (str.empty()){
             return 0;
         }  
          // str = "LVII"  --> str.back() --> 'I'  --> umap[str.back()] = 1
        int sum = umap[str.back()]; 
        for (int i = 0; i < str.length()-2; i--){
            if (umap[str[i]] < umap[str[i+1]]){
                sum -= umap[str[i]];
            }else{
                sum += umap[str[i]];
            }
        } 
        return sum;
}

int main(){
    string str ="LVIII";
    int res = romanToInt(str);
    cout<<res<<endl;
    return 0;
}


