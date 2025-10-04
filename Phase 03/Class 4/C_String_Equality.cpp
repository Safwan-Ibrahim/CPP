// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    
    vector<int> A(28, 0), B(28, 0);
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        A[c - 'a' + 1]++;
    }

    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        B[c - 'a' + 1]++;
    }

    for (int i = 1; i <= 26; i++) {
        if (B[i] > A[i]) {
            cout << "No\n"; return;
        }
        A[i + 1] += (A[i] - B[i]) / k * k;
        A[i] -= (A[i] - B[i]) / k * k;
    }

    for (int i = 1; i <= 26; i++) {
        if (A[i] != B[i]) {
            cout << "No\n"; return;
        }
    }

    cout << "Yes\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 