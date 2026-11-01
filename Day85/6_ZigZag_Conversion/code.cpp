Key concepts to remember
1. String traversal: Processing characters using loops and indices.
2. Vector of strings: Useful for storing characters row-wise.
3. Boolean direction tracking: Using a Boolean variable to control upward and downward movement.
4. Ternary operator: condition ? value1 : value2.
5. Mathematical indexing: Finding positions without explicitly simulating a pattern.
6. Cycle length: Understanding repeating patterns using \(2 \times numRows - 2\).
7. Space optimization: Avoiding unnecessary data structures.



  

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;
        string result = "";
        int cycleLen = 2 * numRows - 2;
        for (int row = 0; row < numRows; row++) {
            for (int j = 0; j + row < s.size(); j += cycleLen) {
                result += s[j + row];
                int diagonal = j + cycleLen - row;
                if (row != 0 && row != numRows - 1 &&
                    diagonal < s.size()) {
                    result += s[diagonal];
                }
            }
        }
        return result;
    }
};
