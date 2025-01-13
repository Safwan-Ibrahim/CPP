// Created on: 2024-11-05 18:11
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool cmp(pair<int,int> a, pair<int,int> b) {
    int c = max(a.first,a.second);
    int d = max(b.first,b.second);
    int e = min(a.first,a.second);
    int f = min(b.first,b.second);
    if (c == d) {
        return e < f;
    }
    return c < d;
}

void solve()
{
    int n; cin >> n;
    pair<int,int> a[n + 1];
    for (int i = 1; i <= n; i++) {
        int x,y; cin >> x >> y;
        a[i] = make_pair(x,y);
    }

    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        cout << a[i].first << " " << a[i].second << " ";
    }

    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
} 