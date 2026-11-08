1.class Solution {
public:
    int countPrimeSetBits(int left, int right) {

        // Step 1: Create prime lookup table
        vector<bool> isPrime(21, true);

        isPrime[0] = false;
        isPrime[1] = false;

        // Step 2: Sieve of Eratosthenes
        for (int i = 2; i * i <= 20; i++) {

            if (isPrime[i]) {

                for (int j = i * i; j <= 20; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 3: Count valid numbers
        int ans = 0;

        for (int i = left; i <= right; i++) {

            int bits = __builtin_popcount(i);

            if (isPrime[bits]) {
                ans++;
            }
        }

        // Step 4: Return answer
        return ans;
    }
};


2.Day 94 – Key Learnings & Takeaways 🚀
💡 Key Learnings
1. Binary Representation: Understood how integers are represented in binary using 0s and 1s.
2. Set Bits: Learned that set bits are the number of 1s in a binary representation.
3. Bit Manipulation: Understood the use of bitwise AND (&) and right shift (>>).
4. Brian Kernighan's Algorithm: Learned how n & (n-1) removes the rightmost set bit efficiently.
5. Built-in Popcount: Learned how __builtin_popcount(n) counts set bits in C++.
6. Prime Numbers: Revised prime number properties and the square-root method for checking primality.
7. Sieve of Eratosthenes: Learned how to efficiently precompute prime numbers by eliminating multiples of each prime.
8. Optimization: Understood how precomputation and lookup tables reduce repeated calculations.
  
🔑 Important Takeaways
- n & (n-1) removes the rightmost set bit.
- __builtin_popcount(n) counts the number of set bits.
- i * i <= n ensures that the Sieve processes numbers only up to the square root of n.
- j += i helps iterate through multiples of the current number.
- isPrime[j] = false marks composite numbers.
- Sieve of Eratosthenes has O(n log log n) time complexity and O(n) space complexity.
- Always analyse constraints before choosing an optimal approach.

