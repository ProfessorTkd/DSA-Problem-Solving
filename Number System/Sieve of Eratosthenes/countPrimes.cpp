#include <bits/stdc++.h>
using namespace std;

// Define the Solution class
class Solution {
public:
    // Function to count the number of prime numbers less than n
    int countPrimes(int n) {
        // If n is less than or equal to 1, there are no primes less than n
        if (n <= 1) return 0;
        
        // Step 1: Initialize a boolean vector to mark prime numbers
        // Initially, assume all numbers are prime
        vector<bool> isPrime(n, true);

        // Step 2: Sieve of Eratosthenes algorithm
        // Iterate through each number starting from 2
        for (int p = 2; p * p < n; ++p) {
            // If p is still marked as prime
            if (isPrime[p]) {
                // Mark all multiples of p as non-prime
                for (int i = p * p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
        // Time Complexity: O(n log log n)
        // Space Complexity: O(n)

        // Step 3: Count the number of primes
        int cnt = 0; // Initialize the prime count
        // Iterate through the vector and count primes
        for (int p = 2; p < n; ++p) {
            if (isPrime[p]) {
                ++cnt; // Increment the count for each prime
            }
        }
        // Time Complexity: O(n)
        // Space Complexity: O(1)

        // Return the total number of primes found
        return cnt;
    }
};
