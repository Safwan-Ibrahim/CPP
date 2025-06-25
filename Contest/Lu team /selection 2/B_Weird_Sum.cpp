// Created on: 2025-04-18 16:17
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m; cin >> n >> m;
    int A[n + 5][m + 5];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }
    
    map<int, vector<int>>R, C;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int v = A[i][j];
            R[v].push_back(i);
            C[v].push_back(j);
        }
    }

    ll ans = 0;
    for (auto [_, v] : R) {
        ll sum = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        for (int i = 0; i < v.size(); i++) {
            ans += sum - ((v.size() - i) * v[i]);
            sum -= v[i];
        }
    }

    
    for (auto [_, v] : C) {
        ll sum = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        for (int i = 0; i < v.size(); i++) {
            ans += sum - ((v.size() - i) * v[i]);
            sum -= v[i];
        }
    }

    cout << ans << endl;
    return 0;
} 