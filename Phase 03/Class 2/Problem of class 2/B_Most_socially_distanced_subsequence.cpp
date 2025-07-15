// Created on: 2025-07-12 01:42
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    vector<int>A(n);
    for (auto &x : A) {
        cin >> x;
    }

    vector<bool>Ok(n, true);
    int k = n;
    for (int i = 2; i < n; i++) {
        if (Ok[i - 1] && Ok[i - 1] && (A[i - 2] < A[i - 1] && A[i - 1] < A[i] || A[i - 2] > A[i - 1] && A[i - 1] > A[i])) {
            Ok[i - 1] = false; k--;
        }
    }
    
    cout << k << endl;
    for (int i = 0; i < n; i++) {
        if (Ok[i]) {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 