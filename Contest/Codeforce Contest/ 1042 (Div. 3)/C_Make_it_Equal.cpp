// Created on: 2025-08-10 20:55
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    
    multiset<int>S, T;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; x %= k;
        S.insert(x);
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x; x %= k;
        T.insert(x);
    }

    for (auto x : T) {
        if (S.find(x) != S.end()) {
            S.erase(S.find(x));
        }
        else if (S.find(k - x) != S.end()) {
            S.erase(S.find(k - x));
        }
        else {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 