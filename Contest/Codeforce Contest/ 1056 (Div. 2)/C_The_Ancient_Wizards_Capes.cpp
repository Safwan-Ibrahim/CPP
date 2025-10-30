// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, A[nn], Pl[nn], Pr[nn];

bool pos(bool x) {
    Pl[1] = !x, Pr[1] = x;

    for (int i = 2; i <= n; i++) {
        x ^= (A[i] == A[i - 1]);
        Pl[i] = Pl[i - 1] + !x;
        Pr[i] = Pr[i - 1] + x;
    }
    
    for (int i = 1; i <= n; i++) {
        if (Pr[n] - Pr[i - 1] + Pl[i] != A[i]) return false;
    }

    return true;
}

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    cout << pos(0) + pos(1) << endl; 
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 