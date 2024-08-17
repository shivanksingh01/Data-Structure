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


    ------------------------------------------------------------------------------------------------------------
    Map Questions with Answers
    ---------------------------
    Que1. Can you use an object as a key in a Map? If yes, how does JavaScript differentiate between different object keys?
    Ans1. Yes, you can use an object as a key in a Map. JavaScript uses the object’s reference (not its content) as the key. 
            This means that two different objects with the same properties will be treated as distinct keys because they are different references in memory.
            
            const map = new Map();
            const obj1 = { key: 'value1' };
            const obj2 = { key: 'value1' };

            map.set(obj1, 'Object 1');
            map.set(obj2, 'Object 2');

            console.log(map.get(obj1)); // Output: 'Object 1'
            console.log(map.get(obj2)); // Output: 'Object 2'
            console.log(map.size);      // Output: 2 (since obj1 and obj2 are different references)


    Que2. If you add the same key to a Map multiple times, what happens?
    Ans2. If you add the same key to a Map multiple times, the value associated with that key is simply updated to the latest value. The key is not duplicated
            
            const map = new Map();
            map.set('a', 1);
            map.set('a', 2);
            map.set('a', 3);

            console.log(map.get('a')); // Output: 3
            console.log(map.size);     // Output: 1

    Que3. How does Map handle the insertion order of keys?
    Ans3. A Map in JavaScript preserves the insertion order of its keys. When you iterate over a Map, the elements are returned in the order they were added.

            const map = new Map();
            map.set('first', 1);
            map.set('second', 2);
            map.set('third', 3);

            for (let [key, value] of map) {
                console.log(key, value);
            }

            Output:
            ---------------------------
            first 1
            second 2
            third 3

    Que4. What happens if you use undefined or null as a key in a Map?
    Ans4. You can use both undefined and null as keys in a Map. They are treated as distinct keys, just like any other value.
          
            const map = new Map();
            map.set(undefined, 'This is undefined');
            map.set(null, 'This is null');

            console.log(map.get(undefined)); // Output: 'This is undefined'
            console.log(map.get(null));      // Output: 'This is null'

            note: undefined and null are valid keys and are distinct from each other, so they can both be used in the same Map.
  
    Que5. What is the difference between Map.prototype.forEach() and Array.prototype.forEach()?
    Ans5. Both Map.prototype.forEach() and Array.prototype.forEach() iterate over elements,  
            
            Array.prototype.forEach(), the callback receives (value, index, array), 
            Map.prototype.forEach(), the callback receives (value, key, map).

    Que6. What happens if you attempt to get a value from a Map using a key that doesn’t exist?
    Ans6. The get() method returns undefined if the key is not present in the Map.
            
            const map = new Map();
            map.set('a', 1);

            console.log(map.get('b')); // Output: undefined

    Que7. Can you store NaN as a key in a Map? If so, how is it treated?
    Ans7. Yes, you can store NaN as a key in a Map. All NaN values are considered the same key, even though NaN !== NaN is true according to the IEEE floating-point standard.
          JavaScript treats all NaN values as the same key, so you can use NaN as a unique key in a Map.

            const map = new Map();
            map.set(NaN, 'Not a Number');

            console.log(map.get(NaN)); // Output: 'Not a Number'

    Que8. Does Map perform deep equality checks on object keys?
    Ans8. No, Map does not perform deep equality checks on object keys. It uses reference equality, 
          meaning two objects with the same properties but different references are considered different keys.

            const map = new Map();
            const obj1 = { a: 1 };
            const obj2 = { a: 1 };

            map.set(obj1, 'Object 1');
            map.set(obj2, 'Object 2');

            console.log(map.get(obj1)); // Output: 'Object 1'
            console.log(map.get(obj2)); // Output: 'Object 2'

    Qus9.  What happens if you modify an object used as a key in a Map after setting it?
    Ans9. If you modify an object used as a key in a Map, it does not affect its identity as a key in the Map. The Map still uses the original object reference to retrieve the value.
            
            const map = new Map();
            const obj = { a: 1 };
            map.set(obj, 'Original');
            obj.a = 2; // Modify the object

            console.log(map.get(obj)); // Output: 'Original'

*/