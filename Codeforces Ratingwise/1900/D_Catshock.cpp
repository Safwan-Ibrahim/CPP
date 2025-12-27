// Created on: 2025-12-25 04:38
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17;
int n, Dept[nn];
vector<int> G[nn];

void dfs(int u, int p) {
    for (auto v : G[u]) {
        if (v != p) {
            Dept[v] = Dept[u] + 1;
            dfs(v, u);
        }
    }
}

void Try() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(n, 0);

    priority_queue<pair<int, int>> Pq;
    for (int i = 1; i < n; i++) {
        Pq.push({Dept[i], i});
    }

    vector<int> Ans;
    int cp = Dept[1] % 2; // current parity
    while (Pq.size()) {
        auto [p, u] = Pq.top();
        Pq.pop();
        p %= 2;
        
        if (Ans.size() && Ans.back() != 1) {
            Ans.push_back(1);
            cp ^= 1;
        }

        if (cp == p) {
            Ans.push_back(1);
            cp ^= 1;
        }

        Ans.push_back(-u);
    }

    assert(Ans.size() <= 3 * n);

    cout << Ans.size() << endl;
    for (auto x : Ans) {
        if (x == 1) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << " " << -x << endl;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Dept[i] = 0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    
    return 0;
} 