// Created on: 2025-05-05 01:02
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 8;
int n, A[nn];
map<int, vector<int>>Mp;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Mp[A[i] - i].push_back(i);
    }
    
    ll mx = -1;
    for (auto [x, V] : Mp) {
        ll sum = 0;
        for (auto i : V) {
            sum += A[i];
        }
        mx = max(mx, sum);
    }

    cout << mx << endl;
    return 0;
} 