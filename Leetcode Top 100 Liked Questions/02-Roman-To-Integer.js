/*
13. Roman to Integer (Easy) : Given a roman numeral, convert it to an integer.

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 
12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
 

Example 1:
    Input: s = "III"
    Output: 3
    Explanation: III = 3.

Example 2:
    Input: s = "LVIII"
    Output: 58
    Explanation: L = 50, V= 5, III = 3.

Example 3:
    Input: s = "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].

*/

/*
Approach1: BruteForce
Complexity
    Time complexity: O(n^2)

var romanToInt = function (s) {
    const strArr = s.split("");
    const ref = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let result = 0;

    for (let i = 0; i < strArr.length; i++) {
        if (strArr[i] == "I" && i + 1 < strArr.length) {
            if (strArr[i + 1] == "V") {
                result += 4;
                i++;
            } else if (strArr[i + 1] == "X") {
                result += 9;
                i++;
            } else {
                result += ref[strArr[i]];
            }
        } else if (strArr[i] == "X" && i + 1 < strArr.length) {
            if (strArr[i + 1] == "L") {
                result += 40;
                i++;
            } else if (strArr[i + 1] == "C") {
                result += 90;
                i++;
            } else {
                result += ref[strArr[i]];
            }
        } else if (strArr[i] == "C" && i + 1 < strArr.length) {
            if (strArr[i + 1] == "D") {
                result += 400;
                i++;
            } else if (strArr[i + 1] == "M") {
                result += 900;
                i++;
            } else {
                result += ref[strArr[i]];
            }
        } else {
            result += ref[strArr[i]];
        }
    }

    return result;
};
*/

/*
Approach2: Using a Map to Store Roman Numeral Values

    Iterate from right to left, which simplifies our logic.
    If the current value is greater than or equal to the previous value, we add it.
    If it's smaller, we subtract it (handling cases like IV, CM, etc.).

Complexity
    Time Complexity:  O(n), where n is the length of the input string. We iterate through the string only once.
    Space Complexity: O(1), as we use a fixed-size object to store Roman numeral values.

Example walkthrough with "CDXLIV" (444):
    C (100) < D (500), so result = 0 - 100 = -100
    D (500) > X (10), so result = -100 + 500 = 400
    X (10) < L (50), so result = 400 - 10 = 390
    L (50) > I (1), so result = 390 + 50 = 440
    I (1) < V (5), so result = 440 - 1 = 439
    V (5) is last, so result = 439 + 5 = 444

Advantages of this approach : 
    It's more efficient as we only do one pass through the string.
    It doesn't require splitting the string into an array.
    It handles all special cases (IV, IX, XL, XC, CD, CM) without explicit checking, making the code cleaner and more maintainable.
*/

var romanToInt = function (s) {
    const romanValues = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let result = 0;
    for (let i = 0; i < s.length; i++) {
        const currentValue = romanValues[s[i]];
        const nextValue = romanValues[s[i + 1]] || 0;

        if (currentValue < nextValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }
    }
    return result;
};

/*
Approach 3: using JavaScript Map
Time Complexity:  O(n), where n is the length of the input string. We iterate through the string only once.
Space Complexity: O(1), as we use a fixed-size object to store Roman numeral values.

var romanToInt = function (s) {
    const mp = new Map([
        ["I", 1],
        ["V", 5],
        ["X", 10],
        ["L", 50],
        ["C", 100],
        ["D", 500],
        ["M", 1000],
    ]);

    let result = 0;

    for (let i = 0; i < s.length; i++) {
        const currentValue = mp.get(s[i]);
        const nextValue = mp.get(s[i + 1]) || 0;

        if (currentValue < nextValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }
    }

    return result;
};
*/

// function call
const main = () => {
    const s = "MMMDCCCLXXXVIII"; // 3888
    // const s = "CDXLIV"; // 444

    const result = romanToInt(s);
    if (result) {
        console.log(result);
    } else {
        console.log("No solution found.");
    }
};

main();
