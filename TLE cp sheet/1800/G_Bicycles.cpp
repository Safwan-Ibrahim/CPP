// Created on: 2025-08-26 20:31
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1000 + 17; const ll inf = 1e15;
int n, m, S[nn]; 
vector<pair<int, int>> G[nn];

vector<pair<ll, int>> shortest_path2(ll d, int s, int f) {
    vector<bool>Vs(n + 1, 0);
    vector<pair<ll, int>>Dis(n + 1, {inf, 1008});
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> Pq;
    Pq.push({d, s, f});
    Dis[f] = {d, s};
    while(Pq.size()) {
        auto [d, s, u] = Pq.top(); Pq.pop();
        if (Vs[u]) continue;
        Vs[u] = true;
        for (auto [v, w] : G[u]) {
            if (Dis[v].first > d + 1LL * w * s) {
                Dis[v] = {d + 1LL * s * w, min(s, S[v])};
                Pq.push({Dis[v].first, min(s, S[v]), v}); 
            }
        }
    }
    Dis.erase(Dis.begin());
    return Dis;
}

ll shortest_path1(int f) {
    vector<bool>Vs(n + 1, 0);
    vector<pair<ll, int>>Dis(n + 1, {inf, 1008});

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> Pq;
    Pq.push({0, S[f], f});
    Dis[f] = {0, S[f]};
    while(Pq.size()) {
        auto [d, s, u] = Pq.top(); Pq.pop();
        if (Vs[u]) continue;
        Vs[u] = true;
        int i = 1;
        for (auto [d, s] : shortest_path2(d, s, u)) {
            if (Dis[i].first > d || Dis[i].first == d && Dis[i].second > s) {
                Dis[i] = {d, s};
                Pq.push({d, s, i});
            }
            i++;
        }
    }

    return Dis[n].first;
}



void Try() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }

    cout << shortest_path1(1) << endl;

    for (int i = 1; i <= n; i++) {
        G[i].clear();
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