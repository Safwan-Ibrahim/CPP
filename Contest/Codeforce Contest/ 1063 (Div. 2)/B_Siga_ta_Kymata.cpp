// Created on: 2025-11-10 21:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void p(int a, int b) {
    if (a > b) swap(a, b);
    cout << a << " " << b << endl;
}

void Try() {
    int n; cin >> n;

    int A[n + 1];
    int mn, mx;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] == 1) mn = i;
        if (A[i] == n) mx = i;
    }
    
    string S; cin >> S;

    bool pos = (S.front() != '1') && (S.back() != '1');
    for (int i = 2; i < n; i++) {
        if ((A[i] == 1 || A[i] == n) && S[i - 1] == '1') pos = false;
    }
    
    if (!pos) {
        cout << -1 << endl; return;
    }

    cout << 5 << endl;
    p(mx, mn), p(1, mx), p(n, mx), p(n, mn), p(1, mn);
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 