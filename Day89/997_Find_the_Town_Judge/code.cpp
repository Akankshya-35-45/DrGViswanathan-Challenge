1.problem link: https://leetcode.com/problems/find-the-town-judge/description/

2.solution:
(a)class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // Calculate indegree and outdegree
        for(auto t : trust) {

            int a = t[0];
            int b = t[1];

            outdegree[a]++;
            indegree[b]++;
        }

        // Find the town judge
        for(int i = 1; i <= n; i++) {

            if(indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};

(b)Yes! There is another elegant approach using a single score array.
Instead of storing indegree and outdegree separately, we combine them.

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n + 1, 0);
        for(auto t : trust) {
            score[t[0]]--;
            score[t[1]]++;
        }
        for(int i = 1; i <= n; i++) {
            if(score[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};

3.Key Takeaways:

1. Understanding Trust Relationships: If person a trusts person b, it means a has an outgoing edge and b has an incoming edge.
2. Indegree: Represents the number of people who trust a particular person.
3. Outdegree: Represents the number of people a particular person trusts.
4. Identifying the Judge: A town judge must satisfy two conditions:
- Indegree = n - 1 (everyone else trusts the judge).
- Outdegree = 0 (the judge trusts nobody).
5. Graph Representation: Learned how to use arrays to track incoming and outgoing relationships efficiently.
6. Optimization: Improved from a brute-force approach of O(n × m) to an optimal solution of O(n + m) using indegree and outdegree arrays.
7. Single Array Optimization: Also explored how indegree - outdegree can be combined into a single score array to identify the judge.

Complexity:
- Time: O(n + m)
- Space: O(n)
Biggest Learning: Sometimes, understanding the properties of a graph is more important than traversing it. Identifying the relationship between indegree and outdegree made this problem much simpler!
