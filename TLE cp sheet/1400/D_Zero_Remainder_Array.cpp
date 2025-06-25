// Created on: 2025-03-08 01:37
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 2e5 + 8;
int A[N];

void Try() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    map<int, int>Mp;
    for (int i = 1; i <= n; i++) {
        int add = (k - A[i] % k) % k;
        if (add) {
            Mp[add]++;
        }
    }
    
    int mx_x = 0, mx_y = 0;
    for (auto [x, y] : Mp) {
        if (y >= mx_y) {
            mx_y = y;
            mx_x = x; 
        }
    }


    cout <<  max(0LL, 1LL * (mx_y - 1) * k + mx_x + 1) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 