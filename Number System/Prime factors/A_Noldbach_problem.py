import math

n = 1000  # Set the upper limit for the sieve

# Step 1: Sieve of Eratosthenes
pr = [True for i in range(n+1)]  # Initialize a list to mark primes
pr[0] = pr[1] = False  # 0 and 1 are not primes

# Mark non-primes in the range using the Sieve of Eratosthenes
for i in range(2, int(math.sqrt(n))+1):  # Only go up to the square root of n
    if pr[i]:
        for j in range(i*i, n+1, i):  # Mark all multiples of i as non-prime
            pr[j] = False
# Time Complexity: O(n log log n)
# Space Complexity: O(n)

# Step 2: Collecting prime numbers
prs = []  # List to store prime numbers
for i in range(2, n+1):
    if pr[i]:
        prs.append(i)  # Collect all prime numbers
# Time Complexity: O(n)
# Space Complexity: O(n)

# Step 3: Marking special primes
cb = [False for i in range(n+1)]  # Boolean list to mark special primes

for i in range(len(prs)-1):
    ele = prs[i] + prs[i+1] + 1  # Sum of two consecutive primes + 1
    if ele > n:
        break  # Stop if the element exceeds n
    if pr[ele]:
        cb[ele] = True  # Mark the number as a special prime
# Time Complexity: O(n)
# Space Complexity: O(n)

# Step 4: Counting special primes within the range
n, k = map(int, input().split())  # Read input values
c = 0  # Counter for special primes

for i in range(2, n+1):
    if cb[i]:
        c += 1  # Count the special primes within the range
# Time Complexity: O(N)
# Space Complexity: O(1)

if c >= k:
    print('YES')  # If the count is at least k, print YES
else:
    print('NO')  # Otherwise, print NO
