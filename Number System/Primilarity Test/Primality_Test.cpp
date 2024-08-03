#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORk(i, a, b, k) for(int i = (a); i < (b); i += k)
#define RFOR(i, a, b) for(int i = (a); i >= (b); i--)
#define RFORk(i, a, b, k) for(int i = (a); i >= (b); i -= k)

void solve() {
    int n;
    cin >> n; // Read the integer n

    // Check if n is 1
    if (n == 1) {
        cout << "no" << endl; // 1 is not a prime number
        return;
    }

    // Check if n is 2
    if (n == 2) {
        cout << "yes" << endl; // 2 is a prime number
        return;
    }

    // Loop from 2 to sqrt(n) to check for factors
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cout << "no" << endl; // If n is divisible by i, it's not a prime number
            return;
        }
    }

    // If no factors are found, n is a prime number
    cout << "yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization with C I/O for faster execution
    cin.tie(NULL); // Untie cin from cout
    cout.tie(NULL); // Untie cout from cin

    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
