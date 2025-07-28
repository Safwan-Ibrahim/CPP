// Created on: 2025-07-17 20:52
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, k; cin >> n >> k;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<int>B;
    for (int i = 1; i <= n; i++) {
        if (A[i] >= A[k]) {
            B.push_back(A[i]);
        }
    }

    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());

    int mom = 0;
    bool yes = true;
    for (int i = 1; i < B.size(); i++) {
        mom += (B[i] - B[i - 1]);
        if (B[i - 1] < mom) {
            yes = false; break;
        }
    }

    cout << (yes ? "YES\n" : "NO\n");
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 