// Created on: 2025-01-22 19:16
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int N; cin >> N;

    string S; cin >> S;
    int L = 0, M = 0, R = 0;
    bool yes = true;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'T') {
            if (M > R) {
                R++;
            }
            else {
                L++;
            }
        }
        else {
            if (L > M) {
                M++;
            }
            else if (R > 0){
                L++; M++; R--;
            }
            else {
                yes = false;
            }
        }
    }

    if (L == M && M == R && yes) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = 1; cin >> T;
    for (int i = 1; i <= T; i++) {
        solve();
    }
    return 0;
} 