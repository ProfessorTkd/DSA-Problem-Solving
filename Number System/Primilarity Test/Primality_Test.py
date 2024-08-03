def solve():
    n = int(input())  # Read the input number n
    if n == 1:  # Special case: 1 is not a prime number
        print('no')
        return
    if n == 2:  # Special case: 2 is the smallest prime number
        print('yes')
        return
    i = 2  # Start checking from the smallest prime number
    while i * i <= n:  # Only check divisors up to the square root of n
        if n % i == 0:  # If n is divisible by i, it's not a prime number
            print('no')
            return
        i += 1  # Increment i to check the next potential divisor
    print('yes')  # If no divisors found, n is a prime number

t = 1  # Number of test cases
t = int(input())  # Read the number of test cases
for i in range(t):  # Loop over each test case
    solve()  # Call the solve function for each test case
