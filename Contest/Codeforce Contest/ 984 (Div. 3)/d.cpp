// Created on: 2024-11-02 22:35
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,m; cin >> n >> m;
    char a[n + 5][m + 5];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= min(n,m) / 2; i++) {
        string v = "";
        int r = i, cs = i, cf = m - i + 1;
        for (int j = cs; j <= cf; j++) {
            v += (a[r][j]);
        } 
        int c = cf, rs = i + 1, rf = n - i;
        for (int j = rs; j <= rf; j++) {
            v += (a[j][c]);
        }
        for (int j = cf; j >= cs; j--) {
            v += (a[n - i + 1][j]);
        }
        for (int j = rf; j >= rs; j--) {
            v += (a[j][i]);
        }
        v += v.substr(0,3);
        for (int j = 0; j < v.size() - 3; j++) {
            if (v.substr(j,4) == "1543") {
                ans++;
            }
        }
    }

    cout << ans << endl;
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 