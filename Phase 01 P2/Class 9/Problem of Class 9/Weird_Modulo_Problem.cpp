// Created on: 2025-02-20 06:17
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 5e5 + 8;
int A[N];

void Try() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int mn = 2e9;
    for (int i = 1; i <= n; i++) {
        mn = min(mn, A[i]);
    }

    cout << mn << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 