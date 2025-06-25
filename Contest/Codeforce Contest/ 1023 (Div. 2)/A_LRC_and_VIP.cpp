// Created on: 2025-05-05 20:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int mx = -1, id = 10;
    int A[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] > mx) {
            mx = A[i];
            id = i;
        }
    }
    
    int el = A[1];
    bool same = true;
    for (int i = 1; i <= n; i++) {
        if (A[i] != el) {
            same = false;
        }
    }

    if (same) {
        cout << "No\n"; return;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        if (id == i) {
            cout << 2 << " ";
        }
        else {
            cout << 1 << " ";
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