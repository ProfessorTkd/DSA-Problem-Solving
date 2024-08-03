#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORk(i, a, b, k) for(int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for(int i = (a); i >= (b); i--)
#define RFORk(i, a, b, k) for(int i = (a); i >= (b); i -= k)

const int N = 10000000; // Upper limit for the sieve
bool pr[N + 1]; // Boolean array to mark prime numbers

// Function to perform the Sieve of Eratosthenes
void sieve() {
    FOR(i, 2, N + 1) pr[i] = true; // Initialize all numbers as prime
    // Time Complexity: O(n)
    // Space Complexity: O(n)

    for(int i = 2; i * i <= N; i++) { // Check up to the square root of N
        if(pr[i]) {
            FORk(j, i * i, N + 1, i) // Mark multiples of i as non-prime
                pr[j] = false;
        }
    }
    // Time Complexity: O(n log log n)
    // Space Complexity: O(n)


// void sieve(){
//     FOR(i,2,N+1) pr[i] = true; //All marked true
//     FOR(i,2,N+1)
//         if(pr[i])
//             FORk(j,2*i,N+1,i)
//                 pr[j] = false;  // Mark multiples of i as false
// }               

}

void solve() {
    sieve(); // Call the sieve function to mark primes
    FOR(i, 1, 15) cout << pr[i] << endl; // Print the prime status of numbers 1 to 14
}

int main() {
    ios_base::sync_with_stdio(false); // Optimize IO operations
    cin.tie(NULL); // Untie cin from cout
    cout.tie(NULL); // Untie cout from cin

    int t; // Number of test cases
    cin >> t; // Read the number of test cases
    while(t--) {
        solve(); // Solve each test case
    }
    return 0;
}
   
