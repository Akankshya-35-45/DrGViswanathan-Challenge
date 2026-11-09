 **Problem Link:** [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

## Approach 1: Sliding Window (Two Pointers)

### Intuition

Use two pointers, `left` and `right`, to maintain a sliding window.

- Expand the window by moving `right`.
- Maintain the frequency of characters using a frequency array.
- Once the window contains all three characters, shrink it by moving `left`.
- Continue shrinking until the window becomes invalid.
- Add `left` to the answer because it represents the number of valid starting positions for substrings ending at the current `right` index.

### C++ Code

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {

        int n = s.length();
        int left = 0;
        int ans = 0;

        int freq[3] = {0, 0, 0};

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            while (freq[0] > 0 &&
                   freq[1] > 0 &&
                   freq[2] > 0) {

                freq[s[left] - 'a']--;

                left++;
            }

            ans += left;
        }

        return ans;
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n) – Both pointers traverse the string at most once.
- **Space Complexity:** O(1) – A fixed-size frequency array of three elements is used.

---

## Approach 2: Last Seen Index

### Intuition

Instead of maintaining a sliding window, maintain the last occurrence index of each character.

- Initialize an array `last[3]` with `-1`.
- Traverse the string from left to right.
- Update the last seen index of the current character.
- Find the minimum among the last seen indices of `a`, `b`, and `c`.
- Add `minimum + 1` to the answer.

The minimum last-seen index determines the earliest position from which a valid substring can start.

### C++ Code

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {

        int last[3] = {-1, -1, -1};

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {

            last[s[i] - 'a'] = i;

            ans += min({last[0], last[1], last[2]}) + 1;
        }

        return ans;
    }
};
```

### Complexity Analysis

- **Time Complexity:** O(n) – The string is traversed only once, with constant-time operations at each index.
- **Space Complexity:** O(1) – Only three last-seen indices are maintained.

---

## Approach Comparison

| Approach | Time Complexity | Space Complexity |
|---|---|---|
| Brute Force | O(n²) | O(1) |
| Sliding Window | O(n) | O(1) |
| Last Seen Index | O(n) | O(1) |

**Optimal Approaches:** Both Sliding Window and Last Seen Index achieve linear time complexity and constant auxiliary space.

---

## Key Learnings

1. Understood how the Sliding Window and Two Pointers techniques can optimize substring-counting problems.
2. Learned how maintaining character frequencies helps identify valid windows efficiently.
3. Understood why shrinking a valid window until it becomes invalid allows us to count multiple valid substrings using `ans += left`.
4. Learned how last-seen indices help determine the number of valid substrings ending at each position.
5. Understood the significance of `min(last[0], last[1], last[2]) + 1` in counting valid substrings.
6. Learned how to optimize a brute-force O(n²) solution to O(n).
7. Explored two different optimal approaches to solve the same problem.

## Challenges Faced

- Initially found it difficult to understand why adding `left` counts all valid substrings ending at the current right pointer.
- Understanding when and why to shrink the sliding window required detailed dry runs.
- Understanding how the minimum last-seen index determines valid starting positions was another challenging concept.
- Comparing both optimal approaches helped clarify the underlying counting logic.

## Key Takeaways

- A substring must be continuous and maintain the original character order.
- Sliding Window helps avoid repeatedly generating and checking substrings.
- Two pointers can efficiently maintain and adjust a valid window.
- Frequency arrays provide an efficient way to track character occurrences.
- Last-seen indices can simplify substring-counting problems.
- Different optimal approaches can solve the same problem using different counting strategies.
- Understanding the reasoning behind an algorithm is more important than memorizing its implementation.

---
