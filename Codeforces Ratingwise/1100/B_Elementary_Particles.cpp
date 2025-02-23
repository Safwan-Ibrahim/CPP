// Created on: 2025-01-30 19:30
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 9;
int A[N], n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }    

    map<int, int>Mp;
    int mn = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (Mp.find(A[i]) != Mp.end()) {
            mn = min(mn, i - Mp[A[i]]);
        }
        Mp[A[i]] = i;
    }
    
    if (mn == INT_MAX) {
        mn = n + 1;
    }
    cout << n - mn << endl;         
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 