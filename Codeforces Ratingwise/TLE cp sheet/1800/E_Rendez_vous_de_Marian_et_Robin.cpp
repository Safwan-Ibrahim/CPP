// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 2e5 + 17; const ll inf = 1e17;
vector<pair<int, int>> G[nn];
int n, m, h; 
bool Hs[nn];

vector<ll> shortest_path(int s) {

    vector<vector<bool>> Vs(2, vector<bool> (n + 1, false));
    vector<vector<ll>> Dis(2, vector<ll> (n + 1, inf));

    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> Pq;
    Pq.push({0, s, 0});

    Dis[0][s] = 0;

    while (Pq.size()) {
        auto [d, u, h] = Pq.top(); Pq.pop();
        if (Vs[h][u]) continue;
        Vs[h][u] = true;
        h |= Hs[u];
        for (auto [v, w] : G[u]) {
            w >>= h; 
            if (Dis[h][v] > d + w) {
                Dis[h][v] = d + w;
                Pq.push({Dis[h][v], v, h}); 
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        Dis[0][i] = min(Dis[0][i], Dis[1][i]);
    }

    return Dis[0];
}

void Try() {
    cin >> n >> m >> h;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
        Hs[i] = 0;
    }   

    for (int i = 1; i <= h; i++) {
        int x; cin >> x;
        Hs[x] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<ll> A, B;
    A = shortest_path(1);
    B = shortest_path(n);

    ll ans = inf;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(A[i], B[i]));
    }

    cout << (ans >= inf ? -1 : ans) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }

    return 0;
} 