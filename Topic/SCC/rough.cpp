// Created on: 2025-12-12 04:16
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17;
int n, m; vector<int> G[nn], Rg[nn];
vector<vector<int>> Scc;
bool Vg[nn], Vrg[nn];

stack<int> St;

void dfsg(int u) {
    Vg[u] = true;
    for (auto v : G[u]) {
        if (!Vg[v]) dfsg(v);
    }

    St.push(u);
}

void dfsrg(int u) {
    Scc.back().push_back(u);

    Vrg[u] = true;
    for (auto v : Rg[u]) {
        if (!Vrg[v]) dfsrg(v);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        Rg[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!Vg[i]) {
            dfsg(i);
        }
    }

    while (St.size()) {
        int u = St.top();
        St.pop();
        if (!Vrg[u]) {
            Scc.push_back({});
            dfsrg(u);
        }
    }

    if (Scc.size() > 1) {
        cout << "NO\n";
        cout << Scc.back().back() << " " << Scc.front().front() << endl;
    }
    else cout << "YES\n";

    return 0;
} 