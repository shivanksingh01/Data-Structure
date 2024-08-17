/*
1. Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

*/

/*
Approach 1 : Brute force
Time Complexity : O(n2)

Explantion
    In the brute force approach, we use two nested loops to iterate through the array. 
    For each pair of elements, we check if their sum equals the target. 
    If it does, we return their indices.
*/

var twoSum = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] + nums[j] === target) {
        return [i, j];
      }
    }
  }
};



/*
Approach 2 : Using Map
Time Complexity: O(n)

Explanation:
    This approach optimizes the solution using a Map (which is like a hash table in other languages). 
    The Map allows us to store elements and their indices as key-value pairs, enabling quick lookups.

Concept of Map:
    A Map stores key-value pairs. In this case, the key is the array element, and the value is its index.
    We can efficiently check if a required complement (difference between the target and the current element) exists in the Map.
    If it does, the current element and the complement add up to the target, and we return their indices.

Steps:
    Iterate over the array. : for loop
        nums[i] + nums[j] == target
        target - nums[i] = nums[j]
    Calculate the difference (diff) between the target and the current element : diff = target - nums[i].
    Check if this difference is already a key in the Map. : map.has(diff)
    If it is, return the index of the current element and the index of the difference (found in the Map). : map.get(diff) => j  => return [i, j]
    Otherwise, store the current element and its index in the Map.
*/

var twoSum = function(nums, target) {
    let mp = new Map();

    for(i = 0; i<nums.length;i++){
        let diff = target - nums[i];
        if(mp.has(diff)){
            return [i, mp.get(diff)]
        }

        mp.set(nums[i], i)
    }
};


// function call
const main = () => {
  const nums = [2, 7, 11, 15];
  const target = 9;

  const result = twoSum(nums, target);
  if (result) {
    console.log(result);
  } else {
    console.log("No solution found.");
  }
};

main();




/*
More about maps
    In JavaScript, Map is a built-in object that allows you to store key-value pairs. 
    Unlike regular objects, Map allows keys of any type (including objects, functions, and primitives). 
    It also preserves the order of its elements based on insertion order.

Creating a map
    const mp = new Map();    // created a new empty Map object named mp.

Key feature of maps
    1. Keys can be of any type, not just strings or symbols (as is the case with regular objects).
        ex. 
            mp.set('key1', 'value1'); // string key
            mp.set(10, 'value2');     // number key
            mp.set(true, 'value3');   // boolean key
            mp.set({a: 1}, 'value4'); // object key

    2. Preserved Insertion Order: The Map preserves the order in which the key-value pairs are added.
    3. Map Methods
        set(key, value): Adds or updates an element with the specified key and value.
        get(key): Returns the value associated with the specified key, or undefined if the key doesn't exist.
        has(key): Returns true if a value exists for the specified key, otherwise false.
        delete(key): Removes the element associated with the specified key.
        clear(): Removes all key-value pairs from the map.
        size: Returns the number of key-value pairs in the map.

    4. Differences between Map and Objects
        Key Types: In Map, keys can be of any type, whereas in objects, keys are converted to strings (except for symbols).
        Order: Map preserves the insertion order of keys, while objects do not guarantee any specific order.
        Iteration: Map provides better support for iterating over its elements using methods like forEach(), keys(), values(), and entries().

    5. When to Use Map
        When you need key-value pairs with non-string keys.
        When you need to maintain the insertion order of items.
        When you need frequent addition, deletion, or checking of items.

*/