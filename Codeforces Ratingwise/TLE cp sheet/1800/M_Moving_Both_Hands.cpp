// Created on: 2025-11-12 13:57
// Author: Safwan_Ibrahim
    
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17; const ll inf = 1e15;
vector<pair<int, int>> G[nn], IG[nn];
int n, m;

vector<ll> shortest_path(int s) {
    vector<vector<bool>> Vs(2, vector<bool> (n + 1, 0));
    vector<vector<ll>> Dis(2, vector<ll> (n + 1, inf));

    priority_queue<tuple<ll, int, bool>, vector<tuple<ll, int, bool>>, greater<tuple<ll, int, bool>>> Pq;

    Pq.push({0, s, 0});
    Dis[0][s] = 0;
    Dis[1][s] = 0;
    while (Pq.size()) {
        auto [d, u, i] = Pq.top(); Pq.pop();

        if (Vs[i][u]) continue;
        Vs[i][u] = true;

        if (!i) {
            for (auto [v, w] : G[u]) {
                if (Dis[i][v] > Dis[i][u] + w) {
                    Dis[i][v] = Dis[i][u] + w;
                    Pq.push({Dis[i][v], v, i});
                }
            }
        }
        
        for (auto [v, w] : IG[u]) {
            if (Dis[1][v] > Dis[i][u] + w) {
                Dis[1][v] = Dis[i][u] + w;
                Pq.push({Dis[1][v], v, 1});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        Dis[0][i] = min(Dis[0][i], Dis[1][i]);
    }

    return Dis[0];
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        IG[v].push_back({u, w});
    }

    auto D = shortest_path(1);
    for (int i = 2; i <= n; i++) {
        cout << (D[i] >= inf ? -1 : D[i]) << " ";
    }
    cout << endl;
    
    return 0;
} 