#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORk(i,a,b,k) for(int i=(a); i<(b); i+=k)
#define RFOR(i,a,b) for(int i=(a); i>=(b); i--)
#define RFORk(i,a,b,k) for(int i=(a); i>=(b); i-=k)

const int N = 86028121; // Define a constant for the upper limit of the sieve
bool pr[N+1]; // Boolean array to mark prime numbers
vector<int> prs; // Vector to store the list of prime numbers

void sieve() { // Function to perform the Sieve of Eratosthenes
    FOR(i, 2, N+1) pr[i] = true; // Initialize all entries as true (assume all numbers are prime) 
    // Time Complexity: O(N)
    // Space Complexity: O(N)

    for(int i = 2; i * i <= N; i++) { // Iterate up to the square root of N
        if(pr[i]) { // If i is a prime
            FORk(j, i * i, N+1, i) { // Mark all multiples of i starting from i*i
                pr[j] = false; // Mark j as not prime
            }
        }
    }
    // Time Complexity: O(N log log N) (due to nested loops)
    // Space Complexity: O(N)

    prs.push_back(0); // Add a placeholder to index the primes by their position
    FOR(i, 2, N+1) { // Iterate through the range to collect all primes
        if(pr[i]) prs.push_back(i); // If i is prime, add it to the vector
    }
    // Time Complexity: O(N)
    // Space Complexity: O(N) (for storing primes in the vector)
}

void solve() { // Function to handle each test case
    int k;
    cin >> k; // Read the index of the prime to be retrieved
    cout << prs[k] << endl; // Output the k-th prime number
    // Time Complexity: O(1) (constant time access)
    // Space Complexity: O(1) (constant space usage)
}

int main() {
    ios_base::sync_with_stdio(false); // Optimize input/output operations
    cin.tie(NULL); // Untie cin from cout for faster I/O
    cout.tie(NULL); // Untie cout from cin

    int t; 
    cin >> t; // Read the number of test cases
    sieve(); // Generate all primes up to N = 86028121
    // Time Complexity: O(N log log N) (complex sieve generation)
    // Space Complexity: O(N) (space for primes array and vector)

    while(t--) { // Process each test case
        solve(); // Execute solve function for each test case
    }
    return 0;
}
