# Day 99 – Group Anagrams (LeetCode 49)

## Problem Statement
Given an array of strings, group the anagrams together. Anagrams are strings that contain the same characters with the same frequencies but in different orders. Return the groups in any order.

Problem Link: https://leetcode.com/problems/group-anagrams/

Difficulty: Medium  
Topic: Strings, Hashing, Sorting, Frequency Counting

## Example
Input:
```cpp
strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
```
Output:
```cpp
[["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
```

## Approach 1: Sorting + Hash Map

### Intuition
- Anagrams become identical when their characters are sorted.
- Sort each string alphabetically and use the sorted string as the hash map key.
- Store the original strings in a vector corresponding to that key.
- Extract all groups from the hash map to obtain the final answer.

### Code
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
```

### Complexity Analysis
- Time Complexity: O(n * k log k), where n is the number of strings and k is the maximum string length. Sorting each string takes O(k log k).
- Space Complexity: O(n * k) for storing the grouped strings and hash map keys.

## Approach 2: Character Frequency + Hash Map (Optimal)

### Intuition
- Instead of sorting every string, count the frequency of each character.
- Since the input contains only lowercase English letters, use an array of size 26.
- Generate a unique key using the 26 character frequencies.
- Strings with identical frequency patterns belong to the same anagram group.
- Use an unordered_map to store the original strings under their frequency-based keys.

### Code
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            int freq[26] = {0};

            for (char ch : s) {
                freq[ch - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
```

### Complexity Analysis
- Time Complexity: O(n * k), where n is the number of strings and k is the maximum string length. Frequency counting takes O(k), and generating the key takes O(26), which is constant.
- Space Complexity: O(n * k) for storing the frequency keys and grouped strings.

## Dry Run
Input:
```cpp
strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
```
Sorting-based keys:
```text
eat → aet
tea → aet
tan → ant
ate → aet
nat → ant
bat → abt
```
Frequency-based grouping:
```text
a=1, e=1, t=1 → ["eat", "tea", "ate"]
a=1, n=1, t=1 → ["tan", "nat"]
a=1, b=1, t=1 → ["bat"]
```

## Why is the Frequency Approach Optimal?
- Eliminates the need to sort every string.
- Uses a fixed-size frequency array of 26 characters.
- Reduces the time complexity from O(n * k log k) to O(n * k).
- Takes advantage of the lowercase English letter constraint.

## Key Learnings
- Anagrams have identical character frequencies.
- Sorting can be used to generate a common representation.
- Hash maps help group elements using common keys.
- Character frequency arrays provide an efficient alternative to sorting.
- The choice of data structure and problem constraints can improve algorithm efficiency.

## Complexity Comparison

| Approach | Time Complexity | Space Complexity |
|---------------|---------------|---------------|
| Sorting + Hash Map | O(n * k log k) | O(n * k) |
| Frequency + Hash Map | O(n * k) | O(n * k) |

## Conclusion
Solved LeetCode 49 – Group Anagrams using two approaches: Sorting + Hash Map and Character Frequency + Hash Map. The frequency-based approach is optimal for lowercase English letters because it avoids sorting and achieves linear time complexity with respect to the total input size.

Day 99 of 100 Days of Code – One step closer to completing the challenge!
