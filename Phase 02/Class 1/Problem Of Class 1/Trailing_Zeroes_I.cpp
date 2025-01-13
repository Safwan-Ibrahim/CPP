// Created on: 2025-01-05 13:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9;
int c = 1, done[N];
vector<int>primes;

void sieve() {
    for (int i = 2; i < N; i++) {
        if (!done[i]) {
            primes.push_back(i);
            for (int j = i + i; j < N; j += i) {
                done[j] = true;
            }
        }
    }
}

void solve() {
    ll n; cin >> n;
    int ans = 1;
    for (auto x : primes) {
        if (1LL * x * x > n) {
            break;
        }
        int p = 0;
        while(n % x == 0) {
            n /= x;
            p++;
        }
        ans *= p + 1;
    }
    if (n > 1) {
        ans *= 2;
    }
    cout << "Case " << c++ << ": ";
    cout << ans - 1 << endl;  
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve();
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 