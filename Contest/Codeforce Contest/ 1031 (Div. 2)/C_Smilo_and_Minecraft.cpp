// Created on: 2025-06-17 19:15
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 507;
int n, m, k; char S[nn][nn];

bool iv(int i, int j) {
    return 1 <= i && i <= n && 1 <= j && j <= m && S[i][j] == 'g';
}

void Try() {
    cin >> n >> m >> k;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> S[i][j];
        }
    }
    
    vector<vector<int>>Pref(n + 2, vector<int> (m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            Pref[i][j] = (S[i][j] == 'g') + Pref[i - 1][j] + Pref[i][j - 1] - Pref[i - 1][j - 1];
            ans += S[i][j] == 'g';
        }
    }

    k--;
    int mn = 2e9 + 7;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (S[i][j] == '.') {
                int up_row = max(1, i - k), left_col = max(1, j - k);
                int down_row = min(n, i + k), right_col = min(m, j + k);
                int gold = Pref[down_row][right_col] + Pref[up_row - 1][left_col - 1];
                gold -= Pref[up_row - 1][right_col] + Pref[down_row][left_col - 1];
                mn = min(mn, gold);
            }
        }
    }
    cout << ans - mn << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 