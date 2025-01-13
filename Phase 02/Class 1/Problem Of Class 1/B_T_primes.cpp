// Created on: 2024-12-31 18:28
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e6 + 9;

vector<bool>done(N, false);
vector<int>primes;
set<ll>st;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < N; i++) {
        if (!done[i]) {
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < N; j += i) {
                done[j] = true;
            }
        }
    }

    for (auto x : primes) {
        st.insert(1LL * x * x);
    }

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        cout << (st.find(x) != st.end() ? "YES\n" : "NO\n");
    }
    
    return 0;
} 