# Day 101 – LeetCode 347: Top K Frequent Elements
**Difficulty:** Medium  
**Topic:** Hash Map, Sorting, Priority Queue (Heap), Bucket Sort  
**Language:** C++  
**LeetCode:** [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
## 1. Problem Statement
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.
The answer can be returned in any order.
### Example 1
**Input:**
```cpp
nums = [1,1,1,2,2,3], k = 2
```
**Output:**
```cpp
[1,2]
```
**Explanation:**
- 1 appears 3 times.
- 2 appears 2 times.
- 3 appears 1 time.
The two most frequent elements are 1 and 2.
### Example 2
**Input:**
```cpp
nums = [1], k = 1
```
**Output:**
```cpp
[1]
```
### Example 3
**Input:**
```cpp
nums = [1,2,1,2,1,2,3,1,3,2], k = 2
```
**Output:**
```cpp
[1,2]
```
**Explanation:**
- 1 appears 4 times.
- 2 appears 4 times.
- 3 appears 2 times.
The two most frequent elements are 1 and 2.
## 2. Important Concepts
**1. Hash Map (`unordered_map`)**
- Stores elements as keys and their frequencies as values.
- Helps count the occurrences of each unique number efficiently.
**2. Sorting**
- Sorts elements according to their frequencies.
- We use a custom comparator to sort in descending order.
**3. Min Heap (`priority_queue`)**
- A Min Heap keeps the smallest element at the top.
- We use it to maintain only the K most frequent elements.
**4. Bucket Sort**
- Groups elements according to their frequencies.
- We use frequency as the bucket index.
- Traversing buckets backwards helps find the highest frequencies first.
## 3. Approach 1 – Hash Map + Sorting
### Intuition
First, count the frequency of every element using an unordered map.
Then:
1. Store each number and its frequency in a vector of pairs.
2. Sort the vector according to frequency in descending order.
3. Select the first K elements.
### C++ Code
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }
        // Store number and frequency as pairs
        vector<pair<int, int>> arr;
        for (auto it : freq) {
            arr.push_back({it.first, it.second});
        }
        // Sort according to frequency in descending order
        sort(arr.begin(), arr.end(),
             [](auto &a, auto &b) {
                 return a.second > b.second;
             });
        // Store the top K frequent elements
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(arr[i].first);
        }
        return ans;
    }
};
```
### Line-by-Line Explanation
**Step 1: Create a frequency map**
```cpp
unordered_map<int, int> freq;
```
- Key represents the number.
- Value represents its frequency.
**Step 2: Count frequencies**
```cpp
for (int num : nums) {
    freq[num]++;
}
```
Iterates through the array and increments the frequency of each number.
For `[1,1,1,2,2,3]`, the map becomes:
```cpp
1 -> 3
2 -> 2
3 -> 1
```
**Step 3: Create a vector of pairs**
```cpp
vector<pair<int, int>> arr;
```
Each pair stores `{number, frequency}`.
**Step 4: Copy the map into the vector**
```cpp
for (auto it : freq) {
    arr.push_back({it.first, it.second});
}
```
- `it.first` represents the number.
- `it.second` represents its frequency.
**Step 5: Sort by frequency**
```cpp
sort(arr.begin(), arr.end(),
     [](auto &a, auto &b) {
         return a.second > b.second;
     });
```
The custom comparator sorts the pairs according to frequency in descending order.
**Step 6: Extract the top K elements**
```cpp
vector<int> ans;
for (int i = 0; i < k; i++) {
    ans.push_back(arr[i].first);
}
```
We extract only the numbers from the first K pairs.
**Step 7: Return the answer**
```cpp
return ans;
```
### Dry Run
Input:
```cpp
nums = [1,1,1,2,2,3], k = 2
```
Frequency map:
```cpp
1 -> 3
2 -> 2
3 -> 1
```
After sorting:
```cpp
arr = {{1,3}, {2,2}, {3,1}}
```
Extract the first two numbers:
```cpp
ans = [1,2]
```
### Complexity Analysis
Let `n` be the total number of elements and `m` be the number of unique elements.
- Frequency counting: O(n) average.
- Creating pairs: O(m).
- Sorting: O(m log m).
- Extracting K elements: O(k).
**Time Complexity:**
```text
O(n + m log m)
```
**Space Complexity:**
```text
O(m)
```
### Limitation
Sorting all unique elements is unnecessary when we only need the top K elements. This motivates the Min Heap approach.
## 4. Approach 2 – Hash Map + Min Heap
### Intuition
A Min Heap keeps the element with the smallest frequency at the top.
We use this property to maintain only K elements.
Steps:
1. Count frequencies using an unordered map.
2. Create a Min Heap storing `{frequency, number}`.
3. Insert each unique element into the heap.
4. If heap size becomes greater than K, remove the smallest frequency.
5. Extract the remaining K numbers.
### C++ Code
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }
        // Create a Min Heap
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        // Insert frequency and number into the heap
        for (auto it : freq) {
            pq.push({it.second, it.first});
            // Maintain only K elements
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // Extract the top K frequent elements
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```
### Line-by-Line Explanation
**Step 1: Create a frequency map**
```cpp
unordered_map<int, int> freq;
```
Stores each unique number and its frequency.
**Step 2: Count frequencies**
```cpp
for (int num : nums) {
    freq[num]++;
}
```
For the example, the frequency map becomes:
```cpp
1 -> 3
2 -> 2
3 -> 1
```
**Step 3: Create a Min Heap**
```cpp
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>> pq;
```
Explanation:
- `pair<int,int>` stores two integers.
- `vector<pair<int,int>>` is the underlying container.
- `greater<pair<int,int>>` creates a Min Heap.
We store pairs in the format:
```cpp
{frequency, number}
```
The first element determines the primary ordering of the heap.
**Step 4: Traverse the frequency map**
```cpp
for (auto it : freq) {
```
Visits every unique number and its frequency.
**Step 5: Insert into the heap**
```cpp
pq.push({it.second, it.first});
```
- `it.second` is the frequency.
- `it.first` is the number.
Frequency is stored first because we want to compare elements based on frequency.
**Step 6: Maintain only K elements**
```cpp
if (pq.size() > k) {
    pq.pop();
}
```
If the heap size becomes greater than K, remove the element with the smallest frequency.
This ensures that the heap maintains only the K most frequent elements.
**Step 7: Extract the answer**
```cpp
vector<int> ans;
while (!pq.empty()) {
    ans.push_back(pq.top().second);
    pq.pop();
}
```
- `pq.top()` accesses the pair at the top.
- `.second` extracts the number.
- `pq.pop()` removes the top element.
**Step 8: Return the answer**
```cpp
return ans;
```
### Dry Run
Input:
```cpp
nums = [1,1,1,2,2,3], k = 2
```
Frequency map:
```cpp
1 -> 3
2 -> 2
3 -> 1
```
Heap operations:
| Operation | Heap contents | Action |
|---|---|---|
| Insert `{3,1}` | `{3,1}` | No removal |
| Insert `{2,2}` | `{2,2}`, `{3,1}` | No removal |
| Insert `{1,3}` | `{1,3}`, `{3,1}`, `{2,2}` | Remove `{1,3}` |
Final heap:
```cpp
{2,2}
{3,1}
```
Extract the numbers:
```cpp
ans = [2,1]
```
This is valid because the question allows any order.
### Complexity Analysis
Let `m` be the number of unique elements.
- Frequency counting: O(n) average.
- Heap insertion and removal: O(m log k).
- Extracting K elements: O(k).
**Time Complexity:**
```text
O(n + m log k)
```
**Space Complexity:**
```text
O(m + k)
```
### Why is this better than Sorting?
Sorting processes all unique elements and takes O(m log m).
The Min Heap maintains only K elements and takes O(m log k) for heap operations.
When K is much smaller than M, the Min Heap can be more efficient.
## 5. Approach 3 – Hash Map + Bucket Sort (Optimal)
### Intuition
Bucket Sort groups elements based on their frequency instead of sorting them.
The maximum possible frequency of any element is the length of the array.
Therefore, we can create `n + 1` buckets, where the index represents frequency.
Steps:
1. Count the frequency of every number using an unordered map.
2. Create a vector of buckets of size `n + 1`.
3. Place each number into the bucket corresponding to its frequency.
4. Traverse the buckets from the highest index to the lowest.
5. Collect elements until K elements are found.
### C++ Code
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);
        // Step 3: Place numbers into frequency buckets
        for (auto it : freq) {
            bucket[it.second].push_back(it.first);
        }
        // Step 4: Collect the top K frequent elements
        vector<int> ans;
        for (int i = nums.size(); i >= 1; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                // Stop when K elements are collected
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
```
### Line-by-Line Explanation
**Step 1: Create a frequency map**
```cpp
unordered_map<int, int> freq;
```
Stores each unique number and its frequency.
**Step 2: Count frequencies**
```cpp
for (int num : nums) {
    freq[num]++;
}
```
For `[1,1,1,2,2,3]`:
```cpp
1 -> 3
2 -> 2
3 -> 1
```
**Step 3: Create buckets**
```cpp
vector<vector<int>> bucket(nums.size() + 1);
```
Creates `n + 1` buckets.
Why `+1`?
Because frequencies range from 1 to n, and we need a valid bucket index for frequency n.
**Step 4: Insert numbers into their frequency buckets**
```cpp
for (auto it : freq) {
    bucket[it.second].push_back(it.first);
}
```
- `it.first` represents the number.
- `it.second` represents its frequency.
For example:
```cpp
bucket[3].push_back(1);
bucket[2].push_back(2);
bucket[1].push_back(3);
```
Now:
```cpp
bucket[3] = {1};
bucket[2] = {2};
bucket[1] = {3};
```
**Step 5: Create the answer vector**
```cpp
vector<int> ans;
```
Stores the final K most frequent elements.
**Step 6: Traverse buckets backwards**
```cpp
for (int i = nums.size(); i >= 1; i--) {
```
We start from the highest possible frequency because we need the most frequent elements first.
**Step 7: Traverse elements inside each bucket**
```cpp
for (int num : bucket[i]) {
```
Visits every number stored in the current frequency bucket.
**Step 8: Add the number to the answer**
```cpp
ans.push_back(num);
```
Adds the current number to the result.
**Step 9: Stop after collecting K elements**
```cpp
if (ans.size() == k) {
    return ans;
}
```
Once we have K elements, there is no need to visit the remaining buckets.
**Step 10: Return the answer**
```cpp
return ans;
```
### Dry Run
Input:
```cpp
nums = [1,1,1,2,2,3], k = 2
```
**Step 1: Frequency Map**
```cpp
1 -> 3
2 -> 2
3 -> 1
```
**Step 2: Create Buckets**
```cpp
vector<vector<int>> bucket(7);
```
**Step 3: Insert Elements**
```cpp
bucket[3] = {1};
bucket[2] = {2};
bucket[1] = {3};
```
**Step 4: Traverse from Highest Frequency**
| Bucket Index | Elements | Answer |
|---|---|---|
| 6 | Empty | [] |
| 5 | Empty | [] |
| 4 | Empty | [] |
| 3 | {1} | [1] |
| 2 | {2} | [1,2] |
When the answer size reaches K = 2, we return immediately.
**Final Output:**
```cpp
[1,2]
```
### Complexity Analysis
Let `n` be the total number of elements and `m` be the number of unique elements.
- Frequency counting: O(n) average.
- Bucket creation: O(n).
- Inserting elements into buckets: O(m).
- Traversing buckets: O(n).
**Time Complexity:**
```text
O(n)
```
**Space Complexity:**
```text
O(n)
```
This is the optimal approach in terms of asymptotic average time complexity.
## 6. Comparison of All Three Approaches
Let:
- `n` = total number of elements.
- `m` = number of unique elements.
- `k` = required number of frequent elements.
| Approach | Time Complexity | Space Complexity |
|-------------|---------------|-----------------|
| Hash Map + Sorting | O(n + m log m) | O(m) |
| Hash Map + Min Heap | O(n + m log k) | O(m + k) |
| Hash Map + Bucket Sort | O(n) | O(n) |
### Which Approach Should We Prefer?
**1. Sorting:** Easy to understand and implement, but sorts all unique elements.
**2. Min Heap:** Useful when K is small compared with the number of unique elements. Maintains only K elements.
**3. Bucket Sort:** Optimal for this problem because frequency can be used directly as a bucket index, avoiding comparison-based sorting.
**Recommended approach:** Hash Map + Bucket Sort.
## 7. Important Interview Takeaways
1. Use `unordered_map` for frequency counting.
2. Use `priority_queue` when you need to maintain the top K elements.
3. Understand how `greater<pair<int,int>>` creates a Min Heap.
4. Remember that a number's maximum frequency cannot exceed the array length.
5. Bucket Sort can group elements by frequency without sorting them.
6. Traverse buckets backwards to get the highest frequencies first.
7. Use early return when K elements have been collected.
## 8. Key Learnings from Day 99
- Learned frequency counting using Hash Maps.
- Understood custom sorting using a comparator.
- Learned how Min Heaps maintain the top K frequent elements.
- Understood how to use pairs inside a Priority Queue.
- Learned Bucket Sort and frequency-based grouping.
- Compared three approaches based on time and space complexity.
- Understood why Bucket Sort achieves linear average time complexity.
## 9. Final Revision
**Problem:** LeetCode 347 – Top K Frequent Elements  
**Difficulty:** Medium  
**Approaches Learned:**
- Hash Map + Sorting
- Hash Map + Min Heap
- Hash Map + Bucket Sort
**Optimal Time Complexity:** O(n) average  
**Optimal Space Complexity:** O(n)
**Day 99 Status:** Completed Successfully!

