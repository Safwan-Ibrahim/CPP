// Created on: 2025-11-16 21:10
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, V[nn]; pair<int, int> A[nn]; set<int> G[nn];

void Try() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> A[i].first;
        A[i].second = i;
        V[i] = A[i].first;
    }
    
    for (int i = 1; i + 1 <= n; i++) {
        G[i].insert(i + 1);
        G[i + 1].insert(i);
    }
    
    G[1].insert(n);
    G[n].insert(1);

    sort(A + 1, A + n + 1);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int u = A[i].second;
        int mn = 2e9;
        vector<int> B;
        for (auto x : G[u]) {
            G[x].erase(u);
            mn = min(mn, V[x]);
            B.push_back(x);
        }
        ans += mn;
        if (G[u].size() > 1) {
            G[B.front()].insert(B.back());
            G[B.back()].insert(B.front());
        }
    }

    cout << ans << endl;

    for (int i = 1; i <= n; i++) G[i].clear();
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 