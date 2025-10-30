// Created on: 2025-10-28 20:46
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e6 + 17;

vector<int>Prime;
vector<bool>Gone(nn, false);

void prec() {
    for (int i = 2; i * i < nn - 2; i++) {
        if (!Gone[i]) {
            for (int j = i * i; j < nn - 2; j += i) {
                Gone[j] = true;
            }
        }
    }

    for (int i = 2; i < nn - 2; i++) {
        if (!Gone[i]) {
            Prime.push_back(i);
        }
    }
}

void Try() {
    int n; cin >> n;

    ll A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    for (auto x : Prime) {
        ll g = x;
        for (int i = 1; i <= n; i++) {
            if (gcd(g, A[i]) == 1) {
                cout << x << endl; return;
            }
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t; prec();
    cerr << Prime.size() << endl;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 