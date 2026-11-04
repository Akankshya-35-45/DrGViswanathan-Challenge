problem link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int count = 0;
        int maxCount = 0;

        // Step 1: Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }
        maxCount = count;

        // Step 2: Slide the window
        for (int i = k; i < n; i++) {

            // Remove the character leaving the window
            if (s[i - k] == 'a' || s[i - k] == 'e' ||
                s[i - k] == 'i' || s[i - k] == 'o' ||
                s[i - k] == 'u') {
                count--;
            }

            // Add the character entering the window
            if (s[i] == 'a' || s[i] == 'e' ||
                s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }

            // Update maximum vowel count
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};


Day 90 takeaway
Today's biggest learning:
- Understood Fixed-Size Sliding Window.
- Learned how to avoid repeated calculations.
- Practised maintaining a running count.
- Improved time complexity from O(n × k) to O(n).
Remember this pattern: Whenever a problem asks you to find something in every continuous subarray or substring of a fixed length k, think about Fixed-Size Sliding Window!
