// Created on: 2025-08-21 00:27
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 4e5 + 17; const ll inf = 1e18;
int n, A[nn];
vector<pair<int, int>> G[nn];

vector<ll> shortest_path(int s) {
    vector<bool>Vs(n + 1, 0);
    vector<ll>Dis(n + 1, inf);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Pq;
    Pq.push({0, s});
    Dis[s] = 0;
    while(Pq.size()) {
        auto [d, u] = Pq.top(); Pq.pop();
        if (Vs[u]) continue;
        Vs[u] = true;
        for (auto [v, w] : G[u]) {
            if (Dis[v] > Dis[u] + w) {
                Dis[v] = Dis[u] + w;
                Pq.push({Dis[v], v}); 
            }
        }
    }
    return Dis;
}

void Try() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        G[i].push_back({x, A[i]});
        if (i > 1) G[i].push_back({i - 1, 0});
    }

    vector<ll> Min_cost = shortest_path(1);
    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += A[i];
        ans = max(ans, sum - Min_cost[i]);
        G[i].clear();
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t = 1; cin >> t;
    for (int i = 1; i <= t; i++) {
        Try();
    }
    return 0;
} 