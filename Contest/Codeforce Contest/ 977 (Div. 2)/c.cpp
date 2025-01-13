// Created on: 2024-10-06 12:02
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve()
{
    int n,m,q; cin >> n >> m >> q;
    set<int>st;

    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int b[m+1];
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    vector<bool>v(n+1,0);

    int p = 1;
    for (int i = 1; i <= m; i++) {
        if (v[b[i]]) {
            continue;
        }
        else if (p <= n && b[i] == a[p]){
            v[a[p++]] = 1;
        }
        else {
            cout << "TIDAK\n"; return;
        }
    }

    cout << "YA\n";
    
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 