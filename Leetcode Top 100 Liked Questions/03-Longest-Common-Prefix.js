/*
14. Longest Common Prefix - Easy
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"

Example 2:
    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
 

Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters
*/

/**
 * @param {string[]} strs
 * @return {string}
 */

/*
// Approach 1 : brute-force
var longestCommonPrefix = function (strs) {
    // handle: if input array is empty
    if (strs.length == 0) return "";

    // assume forst string is the initial common prefix
    let prefix = strs[0]; // prefix = flower  if strs = ["flower", "flow", "flight"];

    // Loop through each character of the first string :: prefix[i] => "f", "l", "o", "w", "e", "r"
    for (let i = 0; i < prefix.length; i++) {
        // get the current character from the first string
        const char = prefix[i]; // char = "f", "l", "o", "w", "e", "r";

        // compare this character with the corresponding character in other strings
        for (let j = 1; j < strs.length; j++) {
            // if character dosn't match or if string is shorter then return common prefix
            if (strs[j].length <= i || strs[j][i] !== char) {
                return prefix.slice(0, i);
            }
        }
    }
};
*/

/*
// Approach2: Higher Order Function (reduce() function)
var longestCommonPrefix = function (strs) {
    // Return an empty string if the input array is empty or undefined
    if (!strs || strs.length === 0) {
        return "";
    }

    // Example : ["flower", "flows", "flight"];
    // Use reduce to find the common prefix
    // 1st iteration     "flower"      "flows"
    // 2nd iteration     "flow"       "flight"
    //return "fl"
    return strs.reduce((commonPrefix, currentString) => {
        let i = 0;

        // Compare characters of commonPrefix and currentString until they differ
        while (
            commonPrefix[i] &&
            currentString[i] &&
            commonPrefix[i] === currentString[i]
        ) {
            i++;
        }

        // Slice the commonPrefix to the length of matching characters
        return commonPrefix.slice(0, i);
    });
};

*/

// Approach3: Using .every()
var longestCommonPrefix = function (strs) {
    if (!strs.length) return "";

    let maxPrefixLength = Math.min(...strs.map((str) => str.length)); // length of smallest string in array can be maxPrefixLength

    let prefix = "";
    for (let i = 0; i < maxPrefixLength; i++) {
        let char = strs[0][i];
        if (strs.every((str) => str[i] === char)) {
            prefix += char;
        } else {
            break;
        }
    }
    return prefix;
};

// function call
const main = () => {
    const strs = ["flower", "flows", "flight"];

    const result = longestCommonPrefix(strs);
    if (result) {
        console.log(result);
    } else {
        console.log("No solution found.");
    }
};

main();

/*
1. reduce()
syntax :  array.reduce(callback(accumulator, currentValue, index, array), initialValue);

    The reduce method in JavaScript is a powerful tool for processing arrays. 
    It allows you to "reduce" the array to a single value by applying a function to each element in the array and accumulating the result.

    callback: A function to execute on each element in the array. It takes four arguments:
        . accumulator: The accumulated result from the previous callback call.
        . currentValue: The current element being processed.
        . index (optional): The index of the current element.
        . array (optional): The array reduce was called upon.
    initialValue (optional): A value to use as the first argument to the first call of the callback. If not provided, the first element in the array is used, and reduce starts from the second element.

Example : Calculate sum of elements in array
    
    const numbers = [1, 2, 3, 4, 5];
    const sum = numbers.reduce((accumulator, currentValue) => {
        return accumulator + currentValue;
    }, 0);
    console.log(sum); // Output: 15

    First Iteration: accumulator = 0, currentValue = 1, result: accumulator = 1.
    Second Iteration: accumulator = 1, currentValue = 2, result: accumulator = 3.
    Third Iteration: accumulator = 3, currentValue = 3, result: accumulator = 6.
    Fourth Iteration: accumulator = 6, currentValue = 4, result: accumulator = 10.
    Fifth Iteration: accumulator = 10, currentValue = 5, result: accumulator = 15.


2. .every()

    syntax : array.every(callback(currentValue, index, array), thisArg);

    The .every() method in JavaScript is used to test whether all elements in an array pass a certain condition. 
    It returns true if every element meets the condition, and false otherwise.

    callback: A function that tests each element. It takes up to three arguments:
        . element: The current element being processed in the array.
        . index (optional): The index of the current element being processed.
        . array (optional): The array on which .every() was called.
        . thisArg (optional): A value to use as this when executing the callback.

    Example : Check if all elements in an array are numbers
    
    const numbers = [1, 2, 3, 4, 5];
    const allNumbers = numbers.every((number) => {
        return typeof number === 'number';
    });
    console.log(allNumbers); // Output: true

    Qus1. What does the .every() method return if the array is empty?
    Ans1. The .every() method returns true for an empty array. 
          This is because there are no elements that violate the condition, so the condition is vacuously true.
    
    Qus2. Can the .every() method modify the array on which it is called?
    Ans2. No, the .every() method does not modify the original array. It only tests the elements against the condition.

    Qus3. What happens if the callback function always returns false?
    Ans3. If the callback function always returns false, .every() will return false, regardless of the elements in the array. 
          This is because at least one element fails the condition.

    Qus4. Can you use .every() with asynchronous operations?
    Ans4. .every() is synchronous and will not wait for asynchronous operations to complete. 
          If you need to handle asynchronous checks, you should use other approaches, such as Promise.all() with .map().

    Qus5. How does .every() compare to .some()?
    Ans5. .every() returns true only if all elements satisfy the condition.
          .some() returns true if at least one element satisfies the condition.

          Example: 
            const numbers = [1, 2, 3, 4, 5];
            console.log(numbers.every(num => num < 6)); // Output: true : all numbers are less than 6
            console.log(numbers.some(num => num > 3)); // Output: true  : some numbers are greater than 3
*/
