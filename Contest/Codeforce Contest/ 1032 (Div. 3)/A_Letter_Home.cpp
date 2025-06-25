// Created on: 2025-06-17 20:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n; int A[n + 5];
    int pos; cin >> pos;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    if (pos <= A[1]) {
        cout << A[n] - pos << endl; return;
    }
    if (pos >= A[n]) {
        cout << pos - A[1] << endl; return;
    }
    int tt = A[n] - A[1];
    tt += min(abs(A[1] - pos), abs(A[n] - pos));
    cout << tt << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 