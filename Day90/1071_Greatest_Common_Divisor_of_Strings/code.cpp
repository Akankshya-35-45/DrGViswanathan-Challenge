1.problem link : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

2. solution:
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        // Step 1: Check compatibility
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Step 2: Find GCD of both lengths
        int g = gcd(str1.size(), str2.size());

        // Step 3: Extract the common prefix
        return str1.substr(0, g);
    }
};


3. Day 90 – Key Learnings & Takeaways

Key Learnings
1. GCD in String Problems: Learned how the mathematical concept of Greatest Common Divisor can be applied to find the largest common repeating pattern between two strings.
2. String Concatenation: Understood how comparing str1 + str2 with str2 + str1 helps determine whether both strings share a compatible repeating pattern.
3. Prefix Concept: Learned that the common divisor string must be a prefix of both given strings.
4. Euclidean Algorithm: Understood how gcd() efficiently calculates the greatest common divisor of two string lengths.
5. Substring Function: Practised using substr(0, g) to extract the required number of characters from a string.
6. Mathematical Optimization: Learned how mathematical observations can eliminate unnecessary iterations and make a solution more efficient.
  
Key Takeaways
- Not every string problem requires complicated string manipulation; sometimes mathematics provides the simplest solution.
- GCD helps identify the maximum possible length of a common repeating pattern.
- Checking compatibility before calculating GCD prevents incorrect answers.
- Understanding why an approach works is more important than memorising its implementation.
- A brute-force approach helps build intuition, while mathematical reasoning leads to an optimal solution.
Today's biggest lesson: Sometimes the most optimal solution isn't about writing more code; it's about recognising the right mathematical pattern. 💡

