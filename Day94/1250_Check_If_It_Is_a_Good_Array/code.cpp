1.Day 96 – LeetCode 1250: Check If It Is a Good Array
Difficulty: Hard | Topic: Number Theory, GCD, Euclidean Algorithm, Bézout's Identity | Language: C++
  
2.Approach 1: Using Built-in GCD
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;

        for (int num : nums) {
            g = gcd(g, num);
        }

        return g == 1;
    }
};

Time Complexity: O(nlog M)
Space Complexity: O(1)

  
3.Approach 2: Manual Euclidean Algorithm
class Solution {
public:
    int findGCD(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (int num : nums) {
            g = findGCD(g, num);
        }
        return g == 1;
    }
};

Time Complexity: O(nlog M)
Space Complexity: O(1)

  
4.Key Learnings & Takeaways
1. Understood Bézout's Identity, which states that the GCD of integers can be represented as their integer linear combination.
2. Learned that an array is Good if and only if the GCD of all its elements is 1.
3. Understood why a GCD greater than 1 makes obtaining 1 impossible.
4. Practiced the Euclidean Algorithm using the modulo operator.
5. Learned to calculate GCD using both C++ STL (gcd()) and manual implementation.
6. Understood that initializing GCD with 0 works because \(\gcd(0,x)=x\).
7. Learned how mathematical observations can eliminate unnecessary brute-force approaches.
8. Strengthened understanding of Number Theory and mathematical optimization.
Main Takeaway: Sometimes, solving a Hard problem isn't about writing more code; it's about identifying the mathematical property that makes the solution simple.
