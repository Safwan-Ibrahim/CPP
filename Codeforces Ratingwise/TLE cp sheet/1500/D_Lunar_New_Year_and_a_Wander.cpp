// Created on: 2025-05-15 04:49
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 8;
set<int> G[nn];
int n, m;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if (v != u) {
            G[u].insert(v);
            G[v].insert(u);
        }
    }

    priority_queue<int, vector<int>, greater<int>>Pq; vector<bool>Done(n + 3, false);
    Pq.push(1); Done[1] = true;

    for (int i = 1; i <= n; i++) {
        int t = Pq.top();
        Pq.pop();
        for (auto x : G[t]) {
            if (!Done[x]) {
                Pq.push(x);
                Done[x] = true;
            }
        }
        cout << t << " ";
    }
    cout << endl;

    return 0;
} 