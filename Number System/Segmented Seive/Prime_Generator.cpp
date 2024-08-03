#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<(b); i+=k)
#define RFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define RFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)
#define pb push_back
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<ll> vll;
typedef vector<ull> vull;

const int msm = 31623; // Upper limit for the Sieve of Eratosthenes [maximum sqrt(m)]
bool pr[msm+1], p[100001];
vi prs;

// Function to compute all primes up to msm using Sieve of Eratosthenes
void sieve() {
    // Step 1: Initialize all numbers as prime
    FOR(i, 2, msm + 1)
        pr[i] = true;

    // Step 2: Mark non-primes using Sieve of Eratosthenes
    for(int i = 2; i * i <= msm; i++)
        if(pr[i])
            FORk(j, i * i, msm + 1, i)
                pr[j] = false;

    // Step 3: Store all prime numbers up to msm
    FOR(i, 2, msm + 1)
        if(pr[i])
            prs.pb(i);
}
// Time Complexity of sieve function: O(msm log log msm)
// Space Complexity: O(msm)

// Function to perform segmented sieve to find primes in range [N, M]
void seg_sieve(int N, int M) {
    // Step 2: Initialize the boolean array for range [N, M]
    FOR(i, 0, M - N + 1)
        p[i] = true;

    // Handle the special case where N is 1
    if(N == 1) p[0] = false;

    // Compute the limit for the small primes
    int sm = int(sqrt(M)); //sqrt(m)   

    // Step 3: Use small primes to mark non-primes in range [N, M]
    for(auto i: prs) {
        if(i > sm)
            break;

        int x = (N / i) * i; // Compute the starting point for marking multiples of i
        if(x < N)
            x += i;
        if(x < i * i)
            x = i * i;

        // Mark all multiples of i as non-prime
        FORk(j, x, M + 1, i)
            p[j - N] = false;
    }

    // Output all primes in the range [N, M]
    FOR(i, 0, M - N + 1)
        if(p[i])
            cout << N + i << endl;
}
// Time Complexity of seg_sieve function: O((M-N+1) log log msm + (M-N+1) * log log M)
// Space Complexity: O(M - N + 1)

void solve() {
    int n, m;
    cin >> n >> m; // Read input range
    seg_sieve(n, m); // Find and print primes in the range
    cout << endl; // Print a newline after processing each test case
}

int main() {
    ios_base::sync_with_stdio(false); // Optimize IO operations
    cin.tie(NULL); // Untie cin from cout
    cout.tie(NULL); // Untie cout from cin

    int t = 1;
    cin >> t; // Read the number of test cases
    sieve(); // Precompute all primes up to msm
    while(t--) {
        solve(); // Process each test case
    }
    return 0;
}
