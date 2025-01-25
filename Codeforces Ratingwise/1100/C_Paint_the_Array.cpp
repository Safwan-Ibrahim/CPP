// Created on: 2025-01-21 23:40
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int N; cin >> N;

    vector<int>A, B;
    bool F = 0;
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        if (F) {
            B.push_back(x);
        }
        else {
            A.push_back(x);
        }
        F ^= 1;
    }

    int G1 = 0, G2 = 0;
    for (auto x : A) {
        G1 = gcd(G1, x);
    }
    for (auto x : B) {
        G2 = gcd(G2, x);
    }
    
    bool no = true;
    for (auto x : A) {
        if (x % G2 == 0) {
            no = false;
        }
    }
    if (no) {
        cout << G2 << endl; 
        return;
    }

    no = true;
    for (auto x : B) {
        if (x % G1 == 0) {
            no = false;
        }
    }

    if (no) {
        cout << G1 << endl;
        return;
    }

    cout << 0 << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 