// Created on: 2025-11-06 21:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 1];

    int cnt = 0;
    vector<int> E;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        cnt += (A[i] % 2) == 0;
        if (A[i] % 2 == 0) E.push_back(A[i]);
    }
    
    if (cnt > 1) {
        cout << E.front() << " " << E.back() << endl; return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (A[j] % A[i] % 2 == 0) {
                cout << A[i] << " " << A[j] << endl; return;
            }
        }
    }

    cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 