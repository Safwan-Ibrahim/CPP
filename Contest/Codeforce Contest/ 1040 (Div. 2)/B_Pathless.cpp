// Created on: 2025-07-31 21:01
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void Try() {
    int n, s; cin >> n >> s;
    int sum = 0;
    int A[n + 1];
    vector<int>V;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
        if (A[i] != 0) V.push_back(A[i]);
        else cnt++;
    }
    if (sum == s || sum + 1 < s) {
        cout << -1 << endl; return;
    }

    sort(V.rbegin(), V.rend());
    for (int i = 1; i <= cnt; i++) {
        cout << 0 << " ";
    }
    for (auto x : V) {
        cout << x << " ";
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