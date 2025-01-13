// Created on: 2025-01-02 18:49
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e7 + 9;
vector<int>primes, done(N, 0);

void calculate() {
    for (int i = 2; i <= N; i++) {
        if (!done[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j <= N; j += i) {
                done[j] = 1;
            }
        }
    }
    return;
}

void solve(int t) {
    cout << "Case " << t << ": ";
    int n; cin >> n;
    int lim = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    int ans = 0;
    for (int i = 0, j = lim - 1; i <= j;) {
        int sum = primes[i] + primes[j];
        if (sum > n) {
            j--;
        }
        else if (sum < n) {
            i++;
        }
        else {
            i++; 
            ans++;
        }
    }
    cout << ans << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calculate();
    int c = 1;
    int t = 1; cin >> t;
    while(t--) solve(c++);
    return 0;
} 