// Created on: 2025-01-19 20:54
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            a[i].push_back(x);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < a[i].size(); j++) {
            if (a[i][j] != a[i][j - 1] + n) {
                cout << -1 << endl; return;
            }
        }
    }

    int sq = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j][0] == sq) {
                sq++;
                cout << j << " "; break;
            }
        }
    }

    cout << endl;
    
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
} 