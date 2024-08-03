import math

class Solution:
    def countPrimes(self, n: int) -> int:
        # Step 1: Handle edge case where n <= 2
        if n <= 2:
            return 0
        
        # Step 2: Initialize a boolean list to mark primes
        # p[i] will be True if i is a prime, False otherwise
        p = [True for i in range(n)]
        p[0] = p[1] = False  # 0 and 1 are not primes
        
        # Step 3: Sieve of Eratosthenes
        for i in range(2, int(math.sqrt(n - 1)) + 1):
            if p[i]:  # Check if i is a prime number
                for j in range(i * i, n, i):  # Mark all multiples of i as not prime
                    p[j] = False
        
        # Step 4: Count the number of True values in the list, which represents the number of primes
        return p.count(True)
