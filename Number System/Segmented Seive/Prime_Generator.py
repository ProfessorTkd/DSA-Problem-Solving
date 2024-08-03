import math

def sieve(max_num):
    # Step 1
    pr = [True] * (max_num + 1)
    pr[0] = pr[1] = False  # 0 and 1 are not prime numbers
    for i in range(2, int(math.sqrt(max_num)) + 1):
        if pr[i]:
            for j in range(i * i, max_num + 1, i):
                pr[j] = False
    prs = [i for i in range(2, max_num + 1) if pr[i]]
    return prs

def seg_sieve(N, M, prs):
    # Step 2 & 3
    size = M - N + 1
    p = [True] * size
    if N == 1:
        p[0] = False  # Border case
    sm = int(math.sqrt(M))
    for i in prs:
        if i > sm:
            break
        x = (N // i) * i
        if x < N:
            x += i
        if x < i * i:
            x = i * i
        for j in range(x, M + 1, i):
            p[j - N] = False
    for i in range(size):
        if p[i]:
            print(N + i)

def solve():
    n, m = map(int, input().split())
    prs = sieve(31623)
    seg_sieve(n, m, prs)
    print()


t = int(input())
for _ in range(t):
 solve()
