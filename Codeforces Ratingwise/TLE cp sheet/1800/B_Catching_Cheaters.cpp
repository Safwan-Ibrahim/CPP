// Created on: 2025-11-19 21:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n, m; cin >> n >> m;
    string A, B; cin >> A >> B;
    
    int mx = 0;
    vector<int> Mx(m + 1, -1e9);
    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j <= m; j++) {
            Mx[j] = max(Mx[j], - (i + 1) - j);
        }
        vector<int> Nmx = Mx;
        for (int j = m - 1; j >= 0; j--) {
            if (A[i] == B[j]) {
                int ans = 4 + i + j + Mx[j + 1];
                mx = max(mx, ans);
                Nmx[j] = max(Nmx[j], ans - i - j);
            }
            Nmx[j] = max(Nmx[j], Nmx[j + 1]);
        }

        Mx = Nmx;
    }

    cout << mx << endl;

    return 0;
} 