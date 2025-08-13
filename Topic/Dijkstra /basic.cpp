// Created on: 2025-08-02 23:34
// Author: Safwan_Ibrahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

const int nn = 1e5 + 17; const ll inf = 1e18;
vector<pair<int, int>> G[nn];
int n, m;

vector<ll> djk(int s) {
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

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    
    
    return 0;
} 