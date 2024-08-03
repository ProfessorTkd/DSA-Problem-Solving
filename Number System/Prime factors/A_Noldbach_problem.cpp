#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORk(i, a, b, k) for(int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for(int i = (a); i >= (b); i--)
#define RFORk(i, a, b, k) for(int i = (a); i >= (b); i -= k)

void solve() {
    int n = 1000; // Set the upper limit for the sieve
    vector<bool> pr(n + 1, true); // Initialize a boolean vector to mark primes
    pr[0] = pr[1] = false; // 0 and 1 are not primes
    
    // Step 1: Sieve of Eratosthenes
    for(int i = 2; i * i <= n; i++) {
        if(pr[i]) {
            for(int j = i * i; j <= n; j += i) {
                pr[j] = false; // Mark multiples of i as non-prime
            }
        }
    }
    // Time Complexity: O(n log log n)
    // Space Complexity: O(n)

    vector<int> prs; // Vector to store prime numbers
    for(int i = 2; i <= n; i++) {
        if(pr[i]) {
            prs.push_back(i); // Collect all prime numbers
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    vector<bool> cb(n + 1, false); // Boolean vector to mark special primes
    for(int i = 0; i < prs.size() - 1; i++) {
        int ele = prs[i] + prs[i + 1] + 1; // Sum of two consecutive primes + 1
        if(ele > n) {
            break; // Stop if the element exceeds n
        }
        if(pr[ele]) {
            cb[ele] = true; // Mark the number as a special prime
        }
    }
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    int N, K; // Variables for the input limits
    cin >> N >> K; // Read input values
    int c = 0; // Counter for special primes
    for(int i = 2; i <= N; i++) {
        if(cb[i]) {
            c += 1; // Count the special primes within the range
        }
    }
    // Time Complexity: O(N)
    // Space Complexity: O(1)

    if(c >= K) {
        cout << "YES" << endl; // If the count is at least K, print YES
    } else {
        cout << "NO" << endl; // Otherwise, print NO
    }
}

int main() {
    ios_base::sync_with_stdio(false); // Optimize IO operations
    cin.tie(NULL); // Untie cin from cout
    cout.tie(NULL); // Untie cout from cin
    int t; // Number of test cases
    //cin >> t; // Read the number of test cases
    
    solve(); // Solve 
    
    return 0;
}
