# Day 98 – Break a Palindrome (LeetCode 1328)
## Problem Statement
Given a palindromic string of lowercase English letters, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and is lexicographically the smallest possible.
Return the resulting string. If it is impossible to make the string non-palindromic, return an empty string.
Problem Link: https://leetcode.com/problems/break-a-palindrome/
Difficulty: Medium
Topic: Greedy, Strings
## Examples
Example 1:
Input:
```text
palindrome = "abccba"
```
Output:
```text
"aaccba"
```
Explanation:
Replacing the character `'b'` at index 1 with `'a'` produces `"aaccba"`, which is not a palindrome and is lexicographically the smallest possible result.
Example 2:
Input:
```text
palindrome = "a"
```
Output:
```text
""
```
Explanation:
A single-character string is always a palindrome. Therefore, it is impossible to make it non-palindromic by changing exactly one character.
## Optimal Approach – Greedy
### Intuition
The main objective is to break the palindrome while obtaining the lexicographically smallest possible string.
Since `'a'` is the smallest lowercase English letter, we try to replace the earliest possible character that is not already `'a'` with `'a'`.
We only need to traverse the first half of the string because changing a character in the first half leaves its corresponding mirrored character in the second half unchanged, automatically breaking the palindrome.
If every character in the first half is already `'a'`, we replace the last character with `'b'` to break the palindrome while keeping the string lexicographically smallest.
### Algorithm
1. Calculate the length of the given string.
2. If the length is 1, return an empty string because a single-character string is always a palindrome.
3. Traverse only the first half of the string using `i < n / 2`.
4. Find the first character that is not `'a'`.
5. Replace that character with `'a'` and immediately return the modified string.
6. If all characters in the first half are already `'a'`, replace the last character with `'b'`.
7. Return the resulting string.
### C++ Code
```cpp
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n == 1)
            return "";
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
```
## Dry Run
Input: `palindrome = "abccba"`
Length: `n = 6`
We traverse only the first half of the string because `n / 2 = 3`.
Initial string:
```text
Index:     0  1  2  3  4  5
Character: a  b  c  c  b  a
```
Step 1: `i = 0`
```cpp
palindrome[0] = 'a';
```
The character is already `'a'`, so we skip it.
Step 2: `i = 1`
```cpp
palindrome[1] = 'b';
```
Since `'b' != 'a'`, replace it with `'a'`.
Modified string:
```text
a a c c b a
```
The resulting string is `"aaccba"`.
It is not a palindrome because the second character is `'a'`, whereas the corresponding second-last character is `'b'`.
We immediately return the modified string.
Output:
```text
"aaccba"
```
## Edge Case – All Characters Are 'a'
Input:
```text
palindrome = "aaaa"
```
All characters in the first half are already `'a'`, so the loop does not make any changes.
We replace the last character with `'b'`.
Modified string:
```text
"aaab"
```
Output:
```text
"aaab"
```
## Complexity Analysis
Time Complexity: `O(n)`
The algorithm traverses at most half of the string. Since constant factors are ignored, the overall time complexity is `O(n)`.
Space Complexity: `O(1)`
The input string is modified directly, and only a constant amount of extra space is used.
## Why Traverse Only the First Half?
A palindrome has matching characters at mirrored positions.
For example:
```text
a b c c b a
```
If we modify a character in the first half, its corresponding character in the second half remains unchanged. Therefore, the palindrome property is automatically broken.
There is no need to traverse the entire string.
## Why Replace the First Non-'a' Character?
The objective is to obtain the lexicographically smallest possible string.
- `'a'` is the smallest lowercase English letter.
- Replacing the earliest possible character makes the biggest improvement in lexicographical order.
- Changing a later position cannot produce a smaller result because the earlier differing position determines the ordering.
If all characters in the first half are `'a'`, changing the last character to `'b'` is the smallest possible valid modification.
## Key Learnings and Takeaways
- Understood the Greedy approach for obtaining the lexicographically smallest valid string.
- Learned how the palindrome property helps reduce unnecessary traversal by checking only the first half.
- Understood why replacing the first non-`'a'` character with `'a'` produces the optimal result.
- Learned why replacing the last character with `'b'` handles the special case when all characters are `'a'`.
- Improved understanding of lexicographical ordering and string manipulation.
- Learned how a greedy observation reduces the solution from `O(n²)` brute force to `O(n)` time and `O(1)` auxiliary space.
## Day 98 Progress
Another day of learning greedy strategies, understanding string properties, and improving problem-solving skills.
98/100 – Two more days to complete the 100 Days of Code challenge!
