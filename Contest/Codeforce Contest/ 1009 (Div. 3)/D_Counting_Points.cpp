// Created on: 2025-03-11 22:18
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int P[N], R[N];

void Try() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }   
    for (int i = 1; i <= n; i++) {
        cin >> R[i];
    }

    vector<pair<int, int>>A;

    sort(A.begin(), A.end());

    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 