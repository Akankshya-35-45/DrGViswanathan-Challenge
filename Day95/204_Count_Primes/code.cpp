# Day 95– Count Primes (LeetCode 204)

## Problem Statement

Given an integer `n`, return the number of prime numbers that are strictly less than `n`.
A prime number is a natural number greater than 1 that has exactly two factors: 1 and itself.

Problem Link: https://leetcode.com/problems/count-primes/

Difficulty: Medium
Topic: Number Theory, Prime Numbers, Sieve of Eratosthenes

## Example

Input:
```text
n = 10
```

Output:
```text
4
```

Explanation:

The prime numbers strictly less than 10 are:

```text
2, 3, 5, 7
```

Therefore, the total count is 4.

## Optimal Approach – Sieve of Eratosthenes

### Intuition

Instead of checking every number individually to determine whether it is prime, we can eliminate all composite numbers systematically.
The Sieve of Eratosthenes works by initially assuming that every number is prime and then marking the multiples of each prime number as non-prime.
The numbers that remain unmarked are prime numbers.

### Algorithm

1. Create a boolean array `isPrime` of size `n`, initially filled with `true`.
2. Mark 0 and 1 as `false`, since they are not prime.
3. Iterate from 2 while `i * i < n`.
4. If `isPrime[i]` is true, mark all its multiples as non-prime.
5. Start marking multiples from `i * i` because smaller multiples have already been eliminated by smaller prime factors.
6. After completing the sieve, count all the indices whose values are still `true`.
7. Return the total count.

### C++ Code

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};
```

## Dry Run

Input: `n = 10`
Initially, all numbers are considered prime.

```text
Index:    0  1  2  3  4  5  6  7  8  9
isPrime:  T  T  T  T  T  T  T  T  T  T
```

Step 1: Mark 0 and 1 as non-prime.

```text
F F T T T T T T T T
```

Step 2: i = 2

Mark multiples of 2 starting from 2 × 2 = 4.

```text
4, 6, 8 → false
```

Updated array:

```text
F F T T F T F T F T
```

Step 3: i = 3

Mark multiples of 3 starting from 3 × 3 = 9.

```text
9 → false
```

Updated array:

```text
F F T T F T F T F F
```

Step 4: Counting

The remaining prime numbers are:

```text
2, 3, 5, 7
```

Output:

```text
4
```

## Complexity Analysis

Time Complexity: O(n log log n)
The Sieve eliminates multiples of prime numbers rather than checking every number individually. The total work of marking these multiples is O(n log log n).
Space Complexity: O(n)
A boolean array of size n is used to store the prime or non-prime status of each number.

## Why Start Marking from i * i?

Consider the prime number 5.

Its multiples are:

```text
10, 15, 20, 25, 30, 35...
```

However:

- 10 was already eliminated by 2.
- 15 was already eliminated by 3.
- 20 was already eliminated by 2.

Therefore, there is no need to process these numbers again.

The first multiple that needs to be considered is:

```text
5 * 5 = 25
```

This avoids redundant operations and makes the algorithm more efficient.

## Connection with LeetCode 762

This problem also connects with LeetCode 762 – Prime Number of Set Bits in Binary Representation.
Both problems use the concept of prime numbers but apply it differently.

- LeetCode 204 uses the Sieve of Eratosthenes to identify prime numbers within a given range.
- LeetCode 762 counts the number of set bits (1s) in the binary representation of a number and checks whether that count is prime.

This connection demonstrates how the same mathematical concept can be applied to different problem-solving scenarios.

## Key Learnings and Takeaways

- Understood the Sieve of Eratosthenes for efficiently identifying prime numbers.
- Learned why checking divisors only up to the square root is sufficient for primality testing.
- Understood why marking multiples starts from `i * i` instead of `2 * i`.
- Learned how to eliminate composite numbers systematically.
- Understood the importance of avoiding redundant calculations.
- Connected prime number concepts with the set-bit problem (LeetCode 762).

## Day 95 Progress
Another day of learning, understanding mathematical patterns, and improving problem-solving skills.

97/100 – Three more days to complete the 100 Days of Code challenge!
