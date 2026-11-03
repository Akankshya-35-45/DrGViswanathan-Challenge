1. problem link: https://leetcode.com/problems/reverse-words-in-a-string/description/
2. solution:
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int i = 0;
        int l = 0;
        while(i < n) {

            // Skip extra spaces
            while(i < n && s[i] == ' ') {
                i++;
            }
            if(i >= n) break;

            // Add a single space
            if(l > 0) {
                s[l++] = ' ';
            }

            // Remember starting position
            int start = l;

            // Copy the word
            while(i < n && s[i] != ' ') {
                s[l++] = s[i++];
            }

            // Reverse individual word
            reverse(s.begin() + start, s.begin() + l);
        }
        s.resize(l);
        return s;
    }
};


3.  Key Learnings:
Understood the difference between reversing the order of words and reversing individual characters.
Learned how stringstream helps extract words while handling multiple spaces.
Gained a deeper understanding of the two-pointer technique using separate reading and writing pointers.
Understood how reversing the entire string followed by individual words produces the desired result.
Learned in-place string manipulation to reduce auxiliary space.
Achieved O(n) time complexity and O(1) auxiliary space with the optimal approach.
