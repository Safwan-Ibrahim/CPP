// Created on: 2025-03-13 20:45
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int N = 1e5 + 8;
vector<int> G[N];
bool ok, Vs[N];
int Par[N];
vector<int>Ans;

void dfs(int u, int p) {
    if (ok) {
        return;
    }
    Par[u] = p;
    Vs[u] = true;
    for (auto v : G[u]) {
        if (ok) return;
        if (v != p) {
            if (!Vs[v]) {
                dfs(v, u);
            }
            else {
                ok = true;
                Ans.push_back(v);
                while(u != v) {
                    Ans.push_back(u);
                    u = Par[u];
                }
                Ans.push_back(v);
                return;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m; cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    

    for (int i = 1; i <= n; i++) {
        if (!Vs[i]) {
            dfs(i, 0);
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n"; return 0;
    }


    reverse(Ans.begin(), Ans.end());
    cout << Ans.size() << endl;
    for (auto x : Ans) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
} 