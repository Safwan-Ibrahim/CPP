// Created on: 2025-11-15 13:50
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 505;
vector<array<int, 3>> G[nn][nn];

void Try() {
    int n, m, k; cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            int x; cin >> x;
            G[i][j].push_back({i, j + 1, x});
            G[i][j + 1].push_back({i, j, x});
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int x; cin >> x;
            G[i][j].push_back({i + 1, j, x});
            G[i + 1][j].push_back({i, j, x});
        }
    }

    int sk = k; k >>= 1;

    ll Cost[n + 1][m + 1][k + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int step = 0; step <= k; step++) {
                Cost[i][j][step] = 1e16 * (step != 0);
            }
        }
    }

    for (int step = 1; step <= k; step++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (auto [x, y, c] : G[i][j]) {
                    Cost[i][j][step] = min(Cost[i][j][step], Cost[x][y][step - 1] + c);
                }
            }
        }
    }

    // remember sk & 1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sk & 1) {
                cout << -1 << " ";
            }
            else cout << Cost[i][j][k] * 2 << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            G[i][j].clear();
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 