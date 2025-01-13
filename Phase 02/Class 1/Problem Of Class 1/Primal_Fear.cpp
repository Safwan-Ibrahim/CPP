// Created on: 2025-01-01 17:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 7;
int done[N];
vector<int>primes, sprimes;

bool ok(int x) {
    int n = x;
    
    while(x > 0) {
        if (x % 10 == 0) return false;
        x /= 10;
    }

    while(n > 9) {
        string num = to_string(n);
        num.erase(num.begin());
        n = stoi(num);
        if (!binary_search(primes.begin(), primes.end(), n)) {
            return false;
        }
    }
    return true;
}

void calculate() {
    for (int i = 2; i < N; i++) {
        if (!done[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < N; j += i) {
                done[j] = true;
            }
        }
    }

    for (auto x : primes) {
        if(ok(x)) {
            sprimes.push_back(x);
        }
    }
}

void solve() {
    int n; cin >> n;
    cout << upper_bound(sprimes.begin(), sprimes.end(), n) - sprimes.begin() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calculate();
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 