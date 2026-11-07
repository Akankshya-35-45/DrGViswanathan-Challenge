1.solution:
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (edges[0][0] == edges[1][0] ||
            edges[0][0] == edges[1][1]) {
            return edges[0][0];
        }
        return edges[0][1];
    }
};


2.Key Learnings & Takeaways – Day 93
1. Understood the fundamental structure and properties of an Undirected Star Graph.
2. Learned that the center node has a degree of exactly n - 1.
3. Understood that every edge in a Star Graph contains the common center node.
4. Learned how comparing just the first two edges is sufficient to identify the center node.
5. Practised accessing elements of a 2D vector using edges[i][j].
6. Strengthened understanding of pass by reference (&) in C++.
7. Improved understanding of conditional statements and logical OR (||).
8. Learned to optimize a brute-force degree-counting solution using mathematical observations.
9. Reduced time complexity from O(n) to O(1) and auxiliary space complexity from O(n) to O(1).
10. Understood that identifying special properties of a problem can eliminate unnecessary iterations.
  
Biggest takeaway:
Don't just focus on processing the entire input. Look for patterns, observations, and mathematical properties that can lead to a simpler and more efficient solution.
