// Created on: 2025-08-01 09:23
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 110;
int n, x, P[nn], C[nn];

void Try() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
    }
    
    int ans = 0;
    priority_queue<int>Pq;
    for (int i = 1; i <= n; i++) {
        Pq.push(C[i]);
        x -= C[i];
        if (x < 0) {
            ans++; x += Pq.top(); Pq.pop();
        }
        x += P[i];
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 