// Created on: 2025-07-16 22:47
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n; cin >> n;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    map<int, map<int, int>>Mp;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        Mp[u][A[v]]++;
        Mp[v][A[u]]++;
    }

    vector<bool>Yes(n + 1, false);
    for (auto [x, mp] : Mp) {
        for (auto [y, cnt] : mp) {
            if (cnt > 1 || A[x] == y) {
                Yes[y] = true;
            }
        }
    }
 
    for (int i = 1; i <= n; i++) {
        cout << (Yes[i] ? '1' : '0');
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